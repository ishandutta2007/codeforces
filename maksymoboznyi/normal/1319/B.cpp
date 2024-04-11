#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 4e5 + 5;

int n, a[N], nxt[N], dp[N];

set<pair<int, int> > q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        nxt[i] = n + 1;
    for (int i = n; i > 0; i--) {
        auto it = q.lower_bound({a[i] - i, -1});
        if (it == q.end() || it -> first != a[i] - i) {

            q.insert({a[i] - i, i});
            continue;
        }
        nxt[i] = it -> second;
        q.insert({a[i] - i, i});
    }
    int ans = -1;
    for (int i = n; i > 0; i--)
        dp[i] = a[i] + dp[nxt[i]], ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}