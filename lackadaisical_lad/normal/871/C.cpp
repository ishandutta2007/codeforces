#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
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

const int N = 2e5 + 5;
int p[N], sz[N];
int cyc[N];
int used[N];

int get_root(int v) {
    return v == p[v] ? v : p[v] = get_root(p[v]);
}

void unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        cyc[a] = 1;
        return;
    }
    p[b] = a;
    sz[a] += sz[b];
    cyc[a] |= cyc[b];
}

void solve() {
    int n;
    cin >> n;
    int cur = 0;
    map<int, int> hor, ver;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int a, b;
        if (hor.count(x)) {
            a = hor[x];
        } else {
            p[cur] = cur;
            sz[cur] = 1;
            hor[x] = cur;
            a = cur++;
        }
        if (ver.count(y)) {
            b = ver[y];
        } else {
            p[cur] = cur;
            sz[cur] = 1;
            ver[y] = cur;
            b = cur++;
        }
        unite(a, b);
    }
    ll ans = 1;
    for (int i = 0; i < cur; i++) {
        int v = get_root(i);
        if (used[v]) continue;
        ll mul = binpow(2, sz[v]);
        if (!cyc[v]) mul--;
        ans = ans * mul % MOD;
        used[v] = 1;
    }
    cout << ans << endl;
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