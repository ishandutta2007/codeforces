#include <bits/stdc++.h>
using namespace std;

const int N = 500005, B = 505;

int q, t, x, y;
long long ans, a[N], dp[B][B];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--)
    {
        cin >> t >> x >> y;
        if (t == 1)
        {
            a[x] += y;
            for (int i = 1; i < B; i++)
                dp[i][x % i] += y;
        }
        else
        {
            if (x < B)
                cout << dp[x][y] << '\n';
            else
            {
                ans = 0;
                for (int i = y; i < N; i += x)
                    ans += a[i];
                cout << ans << '\n';
            }
        }
    }
}