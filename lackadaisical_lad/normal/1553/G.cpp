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

const int N = 1e6 + 5;
int p[N * 2];

int getRoot(int v) {
    return p[v] == v ? v : p[v] = getRoot(p[v]);
}

void unite(int v, int u) {
    p[getRoot(v)] = getRoot(u);
}

void solve() {
    // mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    vector<int> lp(N);
    for (int i = 2; i < N; i++) {
        if (lp[i]) continue;
        for (int j = i; j < N; j += i) {
            if (!lp[j]) lp[j] = i;
        }
    }
    iota(p, p + N * 2, 0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        while (x > 1) {
            unite(i, n + lp[x]);
            x /= lp[x];
        }
    }

    set<pair<int, int>> setik;
    for (int i = 0; i < n; i++) {
        int x = a[i] + 1;
        vector<int> kekw;
        while (x > 1) {
            if (kekw.empty() || lp[x] != kekw.back()) {
                kekw.push_back(lp[x]);
            }
            setik.insert({getRoot(i), getRoot(n + lp[x])});
            setik.insert({getRoot(n + lp[x]), getRoot(i)});
            x /= lp[x];
        }
        for (int p1 : kekw) {
            for (int p2 : kekw) {
                setik.insert({getRoot(n + p1), getRoot(n + p2)});
                setik.insert({getRoot(n + p2), getRoot(n + p1)});
            }
        }
    }

    while (q--) {
        int s, t;
        cin >> s >> t;
        s = getRoot(s - 1);
        t = getRoot(t - 1);
        if (s == t) {
            cout << "0\n";
        } else if (setik.count({s, t})) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
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