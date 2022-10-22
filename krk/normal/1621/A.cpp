#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (k > (n + 1) / 2) { printf("-1\n"); continue; }
        fill((char*)B, (char*)B + Maxn * Maxn, '.');
        for (int i = 0; i < k; i++)
            B[2 * i][2 * i] = 'R';
        for (int i = 0; i < n; i++) {
            B[i][n] = '\0';
            printf("%s\n", B[i]);
        }
    }
    return 0;
}