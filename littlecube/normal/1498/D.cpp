#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, dp[100005], t, y, x;
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        dp[i] = 1000000000;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> x >> y;
        if (t == 1)
        {

            int mod = (x + 99999) / 100000;
            for (int j = 0; j < mod; j++)
            {
                deque<int> dq;
                for (int k = j; k <= m; k += mod)
                {
                    while (!dq.empty() && k - dq.front() > y * mod)
                        dq.pop_front();
                    if (!dq.empty())
                        dp[k] = min(i, dp[k]);
                    if (dp[k] < i)
                        dq.push_back(k);
                }
            }
        }
        else
        {

            int cal[100005] = {0};
            for (int j = 1; j <= m; j++)
            {
                if (cal[j])
                    continue;
                vector<int> v;
                for (int k = j; k <= m; k = (int)((k * x + 99999) / 100000))
                {
                    v.pb(k);
                    cal[k] = v.size();
                }
                deque<int> dq;
                for (int k : v)
                {
                    while (!dq.empty() && cal[k] - cal[dq.front()] > y)
                        dq.pop_front();
                    if (!dq.empty())
                        dp[k] = min(dp[k], i);
                    if (dp[k] < i)
                        dq.push_back(k);
                }
            }
        }
        //for (int i = 1; i <= m; i++)
        //    cout << (dp[i] > 100000 ? -1 : dp[i]) << " \n"[i == m];
    }
    for (int i = 1; i <= m; i++)
        cout << (dp[i] > 100000 ? -1 : dp[i]) << " ";
}