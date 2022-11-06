#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 3e5 + 5;

int n, dp[N][3], a[N], b[N];
int p0[N], p1[N], s0[N], s1[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    vector<int> b;
    b.pb(0);
    for (int i = 1; i <= n; i += 2)
        b.pb(a[i]);
    for (int i = 2; i < n; i += 2)
        b.pb(a[i]);
    int ans = 0;
    int bsz = b.size();
    for (int i = 1; i < bsz; i++)
        b.pb(b[i]);
    for (int i = 1; i < b.size(); i++) {
        p0[i] = p0[i - 1] + b[i];
    }
    int sz = (n + 1) / 2;
    for (int i = sz; i < b.size(); i++)
        ans = max(ans, p0[i] - p0[i - sz]);
    cout << ans;
    return 0;
}