#include <bits/stdc++.h>

using namespace std;

const int N = 44;

string s[N];
int n, m, q;
int dp[N][N][N][N];
bool is[N][N][N][N];

void calc(int x1, int y1, int x2, int y2)
{
    if (dp[x1][y1][x2][y2] >= 0)
        return;

    int &res = dp[x1][y1][x2][y2];

    if (x1 == x2 && y1 == y2)
    {
        if (s[x1][y1] == '0')
        {
            res = 1;
            is[x1][y1][x2][y2] = true;
        }
        else
        {
            res = 0;
            is[x1][y1][x2][y2] = false;
        }
        return;
    }

    calc(x1 + 1, y1, x2, y2);
    calc(x1, y1 + 1, x2, y2);
    calc(x1, y1, x2 - 1, y2);
    calc(x1, y1, x2, y2 - 1);

    res = 0;
    for (int mask = 1; mask < 16; mask++)
    {
        int cnt = __builtin_popcount(mask);
        int a = (mask & 1) ? 1 : 0;
        int b = (mask & 2) ? 1 : 0;
        int c = (mask & 4) ? -1 : 0;
        int d = (mask & 8) ? -1 : 0;
        int val = dp[x1 + a][y1 + b][x2 + c][y2 + d];
        if (cnt % 2)
            res += val;
        else
            res -= val;
    }
    //cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    if (is[x1 + 1][y1 + 1][x2 - 1][y2 - 1])
    {
        bool ok = true;
        for (int i = x1; i <= x2; i++)
            if (s[i][y1] == '1' || s[i][y2] == '1')
                ok = false;
        for (int i = y1; i <= y2; i++)
            if (s[x1][i] == '1' || s[x2][i] == '1')
                ok = false;
        //cerr << "ok" << endl;
        if (ok)
        {
            is[x1][y1][x2][y2] = true;
            res++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = '$' + s[i];
    }
    for (int x1 = 0; x1 < 44; x1++)
        for (int y1 = 0; y1 < 44; y1++)
            for (int x2 = 0; x2 < 44; x2++)
                for (int y2 = 0; y2 < 44; y2++)
                    if (x1 > x2 || y1 > y2)
                    {
                        dp[x1][y1][x2][y2] = 0;
                        is[x1][y1][x2][y2] = true;
                    }
                    else
                    {
                        dp[x1][y1][x2][y2] = -1;
                        is[x1][y1][x2][y2] = false;
                    }
    calc(1, 1, n, m);
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << "\n";
    }

    return 0;
}