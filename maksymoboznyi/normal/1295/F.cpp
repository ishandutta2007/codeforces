#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 200;
const long long M = 998244353;

int gp(int a, int b) {
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        int d = gp(a, b / 2);
        return d * d % M;
    }
    return a * gp(a, b - 1) % M;
}

int gb(int a) {
    return gp(a, M - 2);
}

int gf(int n, int k) {
    if (k == 1)
        return n;
    int d = gf(n, k - 1);
    d = d * (n - k + 1) % M * gb(k) % M;
    return d;
}

int need[N], n, dp[N][N];
pair<int, int> a[N];
vector<pair<int, int> > s;

bool is(int i, int j) {
    return a[i].first <= s[j].second && a[i].second >= s[j].first;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> v;
    int b = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        v.pb(a[i].first);
        v.pb(a[i].second);
        b = b * (a[i].second - a[i].first + 1) % M;
    }
    sort(v.rbegin(), v.rend());
    vector<int> u;
    u.pb(v[0]);
    for (int i = 1; i < v.size(); i++)
        if (v[i] != v[i - 1])
            u.pb(v[i]);
    s.pb({-1, -1});
    s.pb({u[0], u[0]});
    for (int i = 1; i < (int) u.size(); i++) {
        if (u[i] + 1 <= u[i - 1] - 1)
            s.pb({u[i - 1] - 1, u[i] + 1});
        s.pb({u[i], u[i]});
    }
    dp[0][0] = 1 ;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j + 1 < s.size(); j++)
            if (dp[i][j] != 0) {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= M;
                for (int k = i + 1; k <= n; k++)
                    if (is(k, j + 1))
                        dp[k][j + 1] += gf(-s[j + 1].second + s[j + 1].first + 1 + (k - i) - 1, k - i) * dp[i][j] % M, dp[k][j + 1] %= M;
                    else
                        break;
            }
    cout << dp[n][s.size() - 1] * gb(b) % M;
    return 0;
}