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

const int N = 3e5 + 5;

int p[N];
ll pref[N], suf[N], sum[N], best[N];

int get_root(int v) {
    return p[v] == v ? v : p[v] = get_root(p[v]);
}

void unite(int l, int r) {
    l = get_root(l);
    r = get_root(r);
    if (l > r) {
        swap(l, r);
    }
    best[l] = max(best[l], best[r]);
    best[l] = max(best[l], suf[l] + pref[r]);
    pref[l] = max(pref[l], sum[l] + pref[r]);
    suf[l] = max(suf[r], suf[l] + sum[r]);
    sum[l] += sum[r];
    p[r] = l;
}

void solve() {
    int n;
    ll a;
    cin >> n >> a;
    vector<ll> d(n), c(n);
    vector<int> edges;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            edges.push_back(i);
        }
        cin >> d[i] >> c[i];
        sum[i] = c[i] = a - c[i];
        ans = max(ans, c[i]);
        pref[i] = suf[i] = best[i] = max(c[i], 0LL);
        p[i] = i;
    }

    auto get_gap = [&](int pos) {
        return (d[pos + 1] - d[pos]) * (d[pos + 1] - d[pos]);
    };

    sort(edges.begin(), edges.end(), [&](int l, int r) {
        return get_gap(l) < get_gap(r);
    });

    for (int i = 0; i + 1 < n; i++) {
        int l = edges[i];
        int r = edges[i] + 1;
        unite(l, r);
        ans = max(ans, best[get_root(l)] - get_gap(l));
    }
    cout << ans << '\n';
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