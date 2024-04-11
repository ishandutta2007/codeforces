#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
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

const int N = 3e5 + 5;

int sum[N];

int get(int f[], int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += f[pos];
    }
    return res;
}

void upd(int f[], int pos, int delta = 1) {
    for (; pos < N; pos |= pos + 1) {
        f[pos] += delta;
    }
}

pair<int, int> t[N * 4];
int lazy[N * 4];

void build(vector<int> a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = { a[tl], tl };
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void push(int v) {
    t[v*2].first += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].first += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].first += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {1e9,1e9};
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
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> used(n + 1);
    vector<int> path;
    function<void(int, int)> dfs = [&](int v, int par) {
        used[v] = 1;
        a[v] ^= 1;
        path.push_back(v);
        for (int u : g[v]) {
            if (!used[u]) {
                dfs(u, v);
                path.push_back(v);
                a[v] ^= 1;
            }
        }
        if (a[v] && par != -1) {
            a[v] ^= 1;
            a[par] ^= 1;
            path.push_back(par);
            path.push_back(v);
        }
        if (a[v] && par == -1 && !g[v].empty()) {
            a[v] ^= 1;
            path.push_back(g[v][0]);
            path.push_back(v);
            path.push_back(g[v][0]);
        }
    };

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            root = i;
            break;
        }
    }
    if (root != -1) {
        dfs(root, -1);
    }

    if (*max_element(a.begin() + 1, a.end()) == 1) {
        cout << "-1\n";
        return;
    }
    cout << path.size() << '\n';
    for (int v : path) {
        cout << v << ' ';
    }
    cout << '\n';
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