#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
const int MOD = 998244353;
int mul(int a, int b) {
    return int64_t(a) * b % MOD;
}
int power(int a, int64_t b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int f[nax];
vector <int> g[nax];
int n;
vector <int> factor[nax];
int k; /// global k

int dfs(int node, int parent) {
    int bal = 0;
    for (int to : g[node]) {
        if (to == parent) continue;
        int foo = dfs(to, node);
        if (foo == -1) return -1;
        bal += foo;
    }

    if (bal % k == 0) return 1;
    else if ((bal + 1) % k == 0) return 0;
    else return -1;
}
int calc(int x) {
    k = x;
    assert(k != 1);
    if (dfs(1, 0) != 1) return 0;
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 1, u, v ; i < n ; ++ i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int x : factor[n - 1]) {
        f[x] = calc(x);
    }
    f[1] = power(2, n - 1);
    for (int i = n - 1 ; i >= 1 ; -- i)
    for (int j = i + i ; j < n ; j += i)
        f[i] -= f[j];

    for (int i = 1 ; i <= n ; ++ i)
        cout << f[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (int i = 2 ; i < nax ; ++ i)
    for (int j = i ; j < nax; j += i) {
        factor[j].push_back(i);
    }

    for (cin >> T ; T -- ; ) {
        solve();
        fill(f + 1, f + n + 1, 0);
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}