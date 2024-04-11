#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, dp[100005][2], ans = 100000000;
pii v[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][1] + 1;
        int destroy = upper_bound(v + 1, v + n + 1, make_pair(v[i].first - v[i].second, -1)) - v ;
        dp[i][1] = i - destroy + dp[destroy - 1][1];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] += n - i;
        dp[i][1] += n - i;
        ans = min({ans, dp[i][1], dp[i][0]});
    }
    cout << ans;

}