#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1002;
int a[N][N], pref[N][N];
long long f[N][N];
long long current[N];

void calc_sums()
{
    for (int i = 0; i < N - 1; ++i)
        for (int j = 1; j < N; ++j)
            pref[i][j] = (i ? pref[i][j - 1] + a[i][j] : 0);
}

void solve()
{
    int n, m, k;
    scanf("%d%d%d", & n, & m, & k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%I64d", & a[i][j]);

    calc_sums();

    for (int x = k; x <= n - k + 1; ++x)
    {
        int y = k;
        f[x][y] = 0;
        for (int i = x - k + 1; i <= x + k - 1; ++i)
        {
            int step = min(i - (x - k + 1), x + k - 1 - i);
            current[i] = 0;
            for (int j = y - step; j <= y + step; ++j)
                current[i] += a[i][j] * min(j - (y - step) + 1, (y + step) - j + 1);
            f[x][y] += current[i];
        }
        for (y = k + 1; y <= m - k + 1; ++y)
        {
            f[x][y] = 0;
            for (int i = x - k + 1; i <= x + k - 1; ++i)
            {
                int step = min(i - (x - k + 1), x + k - 1 - i);
                current[i] += pref[i][y + step] - pref[i][y - 1];
                current[i] -= pref[i][y - 1] - pref[i][y - step - 2];
                f[x][y] += current[i];
            }
        }
    }

    int ansx, ansy;
    long long ans = -1;
    for (int i = k; i <= n - k + 1; ++i)
        for (int j = k; j <= m - k + 1; ++j)
            if (f[i][j] > ans)
            {
                ans = f[i][j];
                ansx = i;
                ansy = j;
            }

    printf("%d %d", ansx, ansy);
}


int main()
{
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}