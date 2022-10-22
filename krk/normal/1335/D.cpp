#include <bits/stdc++.h>
using namespace std;

const int Maxn = 9;

int T;
char B[Maxn + 3][Maxn + 3];

int main()
{
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < Maxn; i++)
            scanf("%s", B[i]);
        B[0][0] = B[1][1];
        B[1][3] = B[2][4];
        B[2][6] = B[1][7];
        B[3][1] = B[4][0];
        B[4][4] = B[3][3];
        B[5][7] = B[4][6];
        B[6][2] = B[7][1];
        B[7][5] = B[6][4];
        B[8][8] = B[7][7];
        for (int i = 0; i < Maxn; i++) {
            B[i][Maxn] = '\0';
            printf("%s\n", B[i]);
        }
    }
    return 0;
}