#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 1005;
const int M = 6725;

pair<int, ll> dp[N][M];
int way[N][M];

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        int pos = min_element(a.begin() + 1, a.end()) - a.begin();
        cout << "1\n" << pos << '\n';
        return;
    }
    vector<ll> divs;
    for (ll d = 1; d * d <= k; d++) {
        if (k % d) continue;
        divs.push_back(d);
        if (d != k / d) {
            divs.push_back(k / d);
        }
    }
    sort(divs.begin(), divs.end());
    const int D = divs.size();
    map<ll, int> id;
    for (int i = 0; i < D; i++) {
        id[divs[i]] = i;
        dp[0][i] = {n + 1, 0};
    }
    dp[0][0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        ll g = gcd(a[i], k);
        copy(dp[i - 1], dp[i - 1] + D, dp[i]);
        for (int j = 0; j < D; j++) {
            int nxt = id[gcd(g * divs[j], k)];
            auto p = pair<int, ll>{dp[i - 1][j].first + 1, dp[i - 1][j].second + a[i]};
            if (p < dp[i][nxt]) {
                dp[i][nxt] = p;
                way[i][nxt] = j + 1;
            }
        }
    }
    if (dp[n][D - 1].first == n + 1) {
        cout << "-1\n";
        return;
    } 
    int cur = D - 1;
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        if (way[i][cur]) {
            ans.push_back(i);
            cur = way[i][cur] - 1;
        }
    }
    cout << ans.size() << endl;
    for (int pos : ans) {
        cout << pos << ' ';
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}