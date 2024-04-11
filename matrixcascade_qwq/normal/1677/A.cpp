#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int T;
int x;
int a[101010];
int sum[5555][5555];
signed main()
{
    T = read();
    while (T--)
    {
        n = read();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 5000; ++j)
            {
                sum[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        for (int i = 1; i <= n; ++i)
        {
            sum[i][a[i]] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 5000; ++j)
            {
                sum[i][j] = sum[i][j] + sum[i - 1][j];
                
               // sum[i][j]+=sum[i][j-1];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 5000; ++j)
            {
                
               sum[i][j]+=sum[i][j-1];
            }
		}
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ans += sum[i - 1][a[j]] * (sum[n][a[i]] - sum[j][a[i]]);
            }
        }
        cout << ans << endl;
    }
}