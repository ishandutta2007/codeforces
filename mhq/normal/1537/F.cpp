#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5  + 10;
vector<int> g[maxN];
bool used[maxN];
bool ALL_OK = true;
ll sm[2];
ll t[maxN];
ll v[maxN];
int clr[maxN];
void dfs(int v) {
    used[v] = true;
    sm[clr[v]] += t[v];
    for (int to : g[v]) {
        if (used[to]) {
            if (clr[v] == clr[to]) {
                ALL_OK = false;
            }
        }
        else {
            clr[to] = clr[v] ^ 1;
            dfs(to);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        ALL_OK = true;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            used[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        ll S = 0;
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            t[i] -= v[i];
            S += t[i];
        }
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        if (S % 2 != 0) {
            cout << "NO\n";
        }
        else {
            sm[0] = sm[1] = 0;
            clr[1] = 0;
            dfs(1);
            if (!ALL_OK) {
                cout << "YES\n";
            }
            else {
                if (sm[0] == sm[1]) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}