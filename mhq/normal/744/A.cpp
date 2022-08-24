#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
int n, m, k;
bool st[maxN];
vector < int > g[maxN];
bool used[maxN];
int dfs(int v) {
    used[v] = true;
    int f = 1;
    for (int to : g[v]) {
        if (!used[to]) f += dfs(to);
    }
    return f;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int mx_sz = 0;
    ll can_add = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i]) {
            int cnt = dfs(i);
            mx_sz = max(mx_sz, cnt);
            can_add += (1LL * cnt * (cnt - 1)) / 2;
        }
    }
    int free = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) free++;
    }
    can_add += (1LL * free * (free - 1)) / 2;
    can_add += (1LL * free * mx_sz);
    cout << can_add - m;
    return 0;
}