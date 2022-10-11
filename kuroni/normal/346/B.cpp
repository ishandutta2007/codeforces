#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MX = 105;

int n, m, q, kmp[MX], kmp_nxt[MX][26], f[MX][MX][MX], tr[MX][MX][MX];
char s[MX], t[MX], v[MX], ans[MX];

int main()
{
    scanf("%s\n%s\n%s", s + 1, t + 1, v + 1);
    n = strlen(s + 1); m = strlen(t + 1); q = strlen(v + 1);
    for (int i = 2; i <= q; i++)
    {
        kmp[i] = kmp[i - 1];
        while (kmp[i] != 0 && v[i] != v[kmp[i] + 1])
            kmp[i] = kmp[kmp[i]];
        kmp[i] += (v[i] == v[kmp[i] + 1]);
    }
    for (int i = 0; i < q; i++)
        for (int j = 0; j < 26; j++)
        {
            kmp_nxt[i][j] = i;
            while (kmp_nxt[i][j] != 0 && (char)(j + 'A') != v[kmp_nxt[i][j] + 1])
                kmp_nxt[i][j] = kmp[kmp_nxt[i][j]];
            kmp_nxt[i][j] += ((char)(j + 'A') == v[kmp_nxt[i][j] + 1]);
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 1; k < q; k++)
                f[i][j][k] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < q; k++)
            {
                f[i][j][k] = max(f[i - 1][j][k], f[i][j - 1][k]);
                tr[i][j][k] = -1;
                if (s[i] == t[j])
                    for (int t = 0; t < q; t++)
                        if (kmp_nxt[t][s[i] - 'A'] == k && f[i - 1][j - 1][t] > -1 && f[i][j][k] < f[i - 1][j - 1][t] + 1)
                        {
                            f[i][j][k] = f[i - 1][j - 1][t] + 1;
                            tr[i][j][k] = t;
                        }
            }
    int cur = 0;
    for (int i = 1; i < q; i++)
        if (f[n][m][i] > f[n][m][cur])
            cur = i;
    if (f[n][m][cur] == 0)
        return printf("0"), 0;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (tr[i][j][cur] == -1)
        {
            if (f[i - 1][j][cur] == f[i][j][cur])
                --i;
            else
                --j;
        }
        else
        {
            ans[f[i][j][cur]] = s[i];
            cur = tr[i][j][cur];
            --i; --j;
        }
    }
    printf("%s", ans + 1);
}