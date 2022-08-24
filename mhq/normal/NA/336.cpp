#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string a, b;
vector < int > g[20];
bool used[20];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < 20; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n; i++) {
        int c1 = a[i] - 'a';
        int c2 = b[i] - 'a';
        if (c1 == c2) continue;
        if (c1 > c2) {
            cout << -1 << '\n';
            return;
        }
        g[c1].emplace_back(c2);
        g[c2].emplace_back(c1);
    }
    int c = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < 20; i++) {
        if (!used[i]) {
            c++;
            dfs(i);
        }
    }
    cout << 20 - c << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}