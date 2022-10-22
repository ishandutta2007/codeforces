#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 1005;

int h, w;
char B[Maxn][Maxn];
int res = 1;

int main()
{
    fill((char*)B, (char*)B + Maxn * Maxn, '?');
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        int r; scanf("%d", &r);
        for (int j = 0; j < r; j++)
            B[i][j] = '1';
        if (r < w) B[i][r] = '0';
    }
    for (int j = 0; j < w; j++) {
        int c; scanf("%d", &c);
        for (int i = 0; i < c; i++)
            if (B[i][j] != '?' && B[i][j] != '1') {
                printf("0\n"); return 0;
            } else B[i][j] = '1';
        if (c < h)
            if (B[c][j] != '?' && B[c][j] != '0') {
                printf("0\n"); return 0;
            } else B[c][j] = '0';
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (B[i][j] == '?') res = 2 * res % mod;
    printf("%d\n", res);
    return 0;
}