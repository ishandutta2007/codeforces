#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, row[N][N], col[N][N], f[N][N][N][N];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            row[i][j] = row[i][j - 1] + (s[j - 1] == '#');
            col[i][j] = col[i - 1][j] + (s[j - 1] == '#');
        }
    }
    for (int lc = n; lc >= 1; lc--)
        for (int rc = lc; rc <= n; rc++)
            for (int lr = n; lr >= 1; lr--)
                for (int rr = lr; rr <= n; rr++)
                {
                    f[lc][rc][lr][rr] = N;
                    if (rc - lc == rr - lr)
                        f[lc][rc][lr][rr] = rc - lc + 1;
                    for (int k = lc; k <= rc; k++)
                        if (col[rr][k] - col[lr - 1][k] == 0)
                            f[lc][rc][lr][rr] = min(f[lc][rc][lr][rr], f[lc][k - 1][lr][rr] + f[k + 1][rc][lr][rr]);
                    for (int k = lr; k <= rr; k++)
                        if (row[k][rc] - row[k][lc - 1] == 0)
                            f[lc][rc][lr][rr] = min(f[lc][rc][lr][rr], f[lc][rc][lr][k - 1] + f[lc][rc][k + 1][rr]);
                }
    cout << f[1][n][1][n];
}