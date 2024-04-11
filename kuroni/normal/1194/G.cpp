#include <bits/stdc++.h>
using namespace std;

const int N = 105, MX = 10, MOD = 998244353;

int n, ans = 0, a[N], dp[N][MX][MX][16][16][2];
char s[N];

void solve(int x, int y, vector<int> dx, vector<int> dy)
{
    for (int i = n, cur = 0; i >= 1; i--)
    {
        (cur *= 10) += (s[i] - '0');
        a[i] = cur / y;
        cur %= y;
    }
    int sz = dx.size();
    for (int i = 1; i <= n; i++)
        for (int cx = 0; cx < MX; cx++)
            for (int cy = 0; cy < MX; cy++)
                for (int sx = 0; sx < (1 << sz); sx++)
                    for (int sy = 0; sy < (1 << sz); sy++)
                        for (int hi = 0; hi < 2; hi++)
                            dp[i][cx][cy][sx][sy][hi] = 0;
    dp[0][0][0][0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int cx = 0; cx < MX; cx++)
            for (int cy = 0; cy < MX; cy++)
                for (int sx = 0; sx < (1 << sz); sx++)
                    for (int sy = 0; sy < (1 << sz); sy++)
                        for (int hi = 0; hi < 2; hi++)
                            for (int cur = 0; cur < MX; cur++)
                            {
                                int nx = cx + cur * x, ny = cy + cur * y;
                                int nsx = sx, lx = nx % MX;
                                for (int i = 0; i < sz; i++)
                                    if (lx == dx[i])
                                        nsx |= (1 << i);
                                int nsy = sy, ly = ny % MX;
                                for (int i = 0; i < sz; i++)
                                    if (ly == dy[i])
                                        nsy |= (1 << i);
                                int nhi = hi;
                                if (cur < a[i])
                                    nhi = 0;
                                else if (cur > a[i])
                                    nhi = 1;
                                (dp[i][nx / MX][ny / MX][nsx][nsy][nhi] += dp[i - 1][cx][cy][sx][sy][hi]) %= MOD;
                            }
    for (int sx = 0; sx < (1 << sz); sx++)
        for (int sy = 0; sy < (1 << sz); sy++)
            if (sx & sy)
                (ans += 2 * dp[n][0][0][sx][sy][0] % MOD) %= MOD;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    reverse(s + 1, s + n + 1);
    for (int i = 1, cur = 1; i <= n; i++)
    {
        (ans += 1LL * cur * (s[i] - '0') % MOD) %= MOD;
        cur = 10LL * cur % MOD;
    }
    for (int x = 1; x < MX; x++)
        for (int y = x + 1; y < MX; y++)
            if (__gcd(x, y) == 1)
            {
                vector<int> dx, dy;
                for (int i = 1; i <= (MX - 1) / y; i++)
                {
                    dx.push_back(x * i);
                    dy.push_back(y * i);
                }
                solve(x, y, dx, dy);
            }
    cout << ans;
}