#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2e5 + 10;
int a[maxN];
int n;
vector<int> g[maxN];
int pref[maxN];
void dfs(int v, int p) {
    pref[v] ^= a[v];
    for (int to : g[v]) {
        if (to == p) continue;
        pref[to] = pref[v];
        dfs(to, v);
    }
}
int ans = 0;
set<int> s[maxN];
void dfs2(int v, int p) {
    s[v].insert(pref[v]);
    bool fnd = false;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs2(to, v);
        if (!fnd) {
            if (s[v].size() < s[to].size()) {
                swap(s[v], s[to]);
            }
            for (int x: s[to]) {
                if (s[v].count(a[v] ^ x)) {
                    fnd = true;
                    break;
                }
            }
            for (int x: s[to]) {
                s[v].insert(x);
            }
        }
    }
    if (fnd) {
        s[v].clear();
        ans++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << ans << '\n';
    return 0;
}