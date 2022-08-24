#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int n;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
const int maxN = (int)1e5 + 100;
ll x[maxN];
vector < int > g[maxN];
vector < pair < ll, int > > all[maxN];
int ans = 0;
void dfs(int v, int p) {
    if (p != -1) {
        all[p].emplace_back(x[v], 1);
        for (auto it : all[p]) {
            ll nit = gcd(it.first, x[v]);
            if (!all[v].empty() && all[v].back().first == nit) {
                all[v].back().second += it.second;
            }
            else {
                all[v].emplace_back(nit, it.second);
            }
        }
        all[p].pop_back();
    }
    else {
        all[v].emplace_back(x[v], 1);
    }
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto it : all[i]) {
            ans = sum(ans, mult(it.first % mod, it.second));
        }
    }
    cout << ans;
    return 0;
}