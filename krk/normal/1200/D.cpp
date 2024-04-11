#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n, k;
char B[Maxn][Maxn];
int S[Maxn][Maxn];
int res;

void Add(int r1, int c1, int r2, int c2)
{
    r1 = max(r1, 1); c1 = max(c1, 1);
    c2 = min(c2, n + 1 - k); r2 = min(r2, n + 1 - k);
    if (r1 > r2 || c1 > c2) return;
    S[r1][c1]++; S[r2 + 1][c1]--; S[r1][c2 + 1]--; S[r2 + 1][c2 + 1]++;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", B[i] + 1);
        int L = 1;
        while (L <= n && B[i][L] == 'W') L++;
        if (L > n) Add(1, 1, n, n);
        else {
            int R = n;
            while (B[i][R] == 'W') R--;
            int lft = k - (R - L + 1);
            if (lft >= 0) Add(i - k + 1, L - lft, i, L);
        }
    }
    for (int j = 1; j <= n; j++) {
        int L = 1;
        while (L <= n && B[L][j] == 'W') L++;
        if (L > n) Add(1, 1, n, n);
        else {
            int R = n;
            while (B[R][j] == 'W') R--;
            int lft = k - (R - L + 1);
            if (lft >= 0) Add(L - lft, j - k + 1, L, j);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
            if (i <= n - k + 1 && j <= n - k + 1)
                res = max(res, S[i][j]);
        }
    printf("%d\n", res);
    return 0;
}