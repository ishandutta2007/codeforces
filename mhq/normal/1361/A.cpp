#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 5e5 + 10;
vector < int > g[maxN];
int t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector < pair < int, int > > ans;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        ans.emplace_back(t[i], i);
    }
    sort(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++) {
        vector < bool > has(g[i].size() + 1, false);
        if (t[i] > (int)g[i].size() + 1) {
            cout << -1;
            return 0;
        }
        for (int u : g[i]) {
            if (t[u] == t[i]) {
                cout << -1;
                return 0;
            }
            if (t[u] < t[i]) {
                has[t[u]] = true;
            }
        }
        for (int j = 1; j < t[i]; j++) {
            if (!has[j]) {
                cout << -1;
                return 0;
            }
        }
    }
    for (auto& it : ans) cout << it.second << " ";
    return 0;
}