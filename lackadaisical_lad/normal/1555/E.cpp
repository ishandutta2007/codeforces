#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
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

int t[N * 4];
int lazy[N * 4];

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1e9;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
        a[i][2]--;
    }
    m--;
    sort(a.begin(), a.end());
    int j = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        while (j < n && query(1, 1, m, 1, m) == 0) {
            update(1, 1, m, a[j][1], a[j][2], 1);
            j++;
        }
        if (query(1, 1, m, 1, m) == 0) {
            break;
        }
        // cout << i << ' ' << j - 1 << '\n';
        ans = min(ans, a[j - 1][0] - a[i][0]);
        update(1, 1, m, a[i][1], a[i][2], -1);
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