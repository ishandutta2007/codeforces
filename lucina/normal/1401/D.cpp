#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MOD = 1e9 + 7;

int n;
int sz[nax];
vector <int> a[nax];
vector <int64_t> b;
int m;
int p[nax];

void dfs (int nod, int parent) {
    sz[nod] = 1;
    for (int i : a[nod]) {
        if (i == parent)
            continue;
        dfs(i, nod);
        sz[nod] += sz[i];
        b.push_back(1LL * (n - sz[i]) * (sz[i]));
    }
}

void solve() {
    cin >> n;

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);

    sort(b.begin(), b.end());

    cin >> m;

    for (int i = 0 ; i < m ; ++ i)
        cin >> p[i];
    sort(p, p + m);
    long long ans = 0;
    if (m <= n - 1) {
        reverse(b.begin(), b.end());
        reverse(p, p + m);
        for (int i = 0 ; i < n - 1; ++ i) {
            ans += 1LL * (b[i] % MOD) * (i >= m ? 1 : p[i]);
            ans %= MOD;
        }
    } else {
        for (int j = n - 1 ; j < m ; ++ j) {
            p[n - 2] = 1LL * p[n - 2] * p[j] % MOD;
        }

        for (int i = 0 ; i < n - 1 ; ++ i) {
            ans += 1LL * (b[i] % MOD) * p[i];
            ans %= MOD;
        }
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ;  T -- ; ) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            a[i].clear();
        b.clear();
    }
}