#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) { printf("\033[%d;%dH", y, x); }

// ���� �Լ� (�������� ����)
void printBomb(int isExploded) {
    if (isExploded) {
        printf("\x1b[B\x1b[7D               ");
        printf("\x1b[B\x1b[7D               ");
        printf("\x1b[B\x1b[7D      BOOM     ");
        printf("\x1b[B\x1b[7D               ");
    }
    else {
        printf("    (BOMB)");
    }
}

int main() {
    int sx = 14, sy = 9;          // �Ҳ� ���� ��ġ
    int bx = 2, by = 2;           // ��ź ��ġ
    int dx[4] = { 0,1,0,-1 };    // �� �� �� ��
    int dy[4] = { 1,0,-1,0 };
    int mv[12] = { 1,2,4,4,6,6,8,8,10,10,12,13 };
    int x = sx, y = sy, i, j, d;

    // ���� ��ü �׸���
    for (i = 0; i < 12; i++) {
        d = i % 4;
        for (j = 0; j < mv[i]; j++) {
            x += dx[d]; y += dy[d];
            gotoxy(x, y); printf("#");
        }
    }

    // ��ź ���
    gotoxy(bx, by); printBomb(0);

    // �Ҳ� �̵�
    x = sx; y = sy;
    gotoxy(x, y); printf("*");
    for (i = 0; i < 12; i++) {
        d = i % 4;
        for (j = 0; j < mv[i]; j++) {
            Sleep(100);
            gotoxy(x, y); printf(" ");    // �Ҳ� ������ �ڸ� �����
            x += dx[d]; y += dy[d];

            // bomb�� ����
            if (y == by && x >= bx && x <= bx + 6) {
                gotoxy(bx, by); printBomb(1);
                gotoxy(0, 25); return 0;
            }

            gotoxy(x, y); printf("*");    
        }
    }

    gotoxy(0, 25); return 0;
}