#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

const int BUBEN = 6005;

int n;
int m;
int q;
const int maxN = 2005;
vector < pair < int, ll > > g[maxN];
ll dp[BUBEN + 10][maxN];
const ll INF = 1e18;
ll mx[BUBEN + 10];
const int mod = (int)1e9 + 7;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int ed[maxN][2];
ll val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
        ed[i][0] = a;
        ed[i][1] = b;
        val[i] = w;
    }
    for (int i = 0; i <= BUBEN; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][1] = 0;
    for (int i = 0; i <= BUBEN; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto& it : g[j]) {
                dp[i + 1][it.first] = max(dp[i + 1][it.first], dp[i][j] + it.second);
            }
        }
        for (int j = 1; j <= n; j++) {
            mx[i] = max(mx[i], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = sum(ans, mx[i] % mod);
    }
    vector < pair < ll, ll > > cand;
    for (int i = 1; i <= m; i++) {
        ll best = -INF;
        for (int j = 0; j < 2; j++) {
            int who = ed[i][j];
            for (int p = 0; p <= m + 1; p++) {
                best = max(best, -val[i] * p + dp[p][who]);
            }
        }
        cand.emplace_back(val[i], best);
    }
    sort(cand.begin(), cand.end());
    const int inv2 = (mod + 1) / 2;
    auto arifm = [&](int from, int delta, int sz) {
        int dd = sum(from, sum(from, mult(delta, sz - 1)));
        dd = mult(dd, sz);
        ans = sum(ans, mult(dd, inv2));
    };
    for (int i = 0; i < cand.size(); i++) {
        ll from = -1e9 - 228;
        ll to = 1e9 + 228;
        // not strictly better
        for (int j = 0; j < i; j++) {
            if (cand[i].second >= cand[j].second) continue;
            ll delta = cand[i].first - cand[j].first;
            assert(delta != 0);
            from = max(from, (cand[j].second - cand[i].second + delta - 1) / delta);
        }
        // strictly better
        for (int j = i + 1; j < cand.size(); j++) {
            if (cand[j].second >= cand[i].second) {
                from = to + 1;
                break;
            }
            ll delta = cand[j].first - cand[i].first;
            assert(delta != 0);
            to = min(to, (cand[i].second - cand[j].second - 1) / delta);
        }
        from = max(from, (ll)m + 1);
        to = min(to, (ll)q);
        if (from > to) continue;
        ll val_from = cand[i].first * from + cand[i].second;
        arifm(val_from % mod, cand[i].first % mod, (to - from + 1) % mod);
    }
    cout << ans;
    return 0;
}