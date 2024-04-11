#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
const int maxN = 2 * (int)1e5 + 100;
int fact[maxN];
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
vector < int > g[maxN];
int n;
int ans = 1;
int sz[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    int cnt = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        cnt++;
        dfs(to, v);
        sz[v] += sz[to];
    }
    if (v != 1) ans = mult(ans, fact[cnt + 1]);
    else ans = mult(ans, mult(n, fact[cnt]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 //   freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = mult(i, fact[i - 1]);
    dfs(1, -1);
    cout << ans;
    return 0;
}