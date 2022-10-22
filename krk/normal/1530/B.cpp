#include <bits/stdc++.h>
using namespace std;

const int Maxn = 22;

int T;
int h, w;
char B[Maxn][Maxn];

bool Write(int r, int c)
{
    for (int i = r - 1; i <= r + 1; i++)
        for (int j = c - 1; j <= c + 1; j++)
            if (0 <= i && i < h && 0 <= j && j < w && B[i][j] == '1')
                return false;
    B[r][c] = '1';
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            fill(B[i], B[i] + w, '0');
            B[i][w] = '\0';
        }
        for (int j = 0; j < w; j++)
            Write(0, j);
        for (int i = 0; i < h; i++)
            Write(i, w - 1);
        for (int j = w - 1; j >= 0; j--)
            Write(h - 1, j);
        for (int i = h - 1; i >= 0; i--)
            Write(i, 0);
        for (int i = 0; i < h; i++)
            printf("%s\n", B[i]);
    }
    return 0;
}