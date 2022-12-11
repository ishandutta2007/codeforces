#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi = pair<int, int>;

using vpi = vector<pi>;

#define sz(x) int((x).size())

#define eb emplace_back

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

#define va first
#define vb second

const ll INF = 1e9;

vpi ans;
int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 2], dp[n + 2];
        a[0] = a[1] = 0;
        FOR(i, 2, n + 2)
        {
            cin >> a[i];
        }
        dp[0] = INF;
        dp[1] = 0;
        FOR(i, 2, n + 2)
        {
            dp[i] = (abs(dp[i - 2] + (a[i - 1] - a[i])) < abs(dp[i - 1] + a[i])) ? dp[i - 2] + (a[i - 1] - a[i]) : dp[i - 1] + a[i];
        }
        if (dp[n + 1])
        {
            cout << -1 << '\n';
            continue;
        }
        ans.clear();
        ROF(i, 2, n + 2)
        {
            if (abs(dp[i - 2] + (a[i - 1] - a[i])) < abs(dp[i - 1] + a[i]))
            {
                ans.eb(i - 2, i - 1);
                i--;
            }
            else
                ans.eb(i - 1, i - 1);
        }
        cout << sz(ans) << '\n';
        R0F(i, sz(ans))
        {
            cout << ans[i].va << ' ' << ans[i].vb << '\n';
        }
    }
}