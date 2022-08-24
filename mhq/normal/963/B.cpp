#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
int n;
int sz[maxN];
void calc(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        calc(to, v);
        sz[v] += sz[to];
    }
}
vector<int> ans;
void dfs(int v, int p, int add) {
    int c = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (sz[to] % 2 == 0) {
            dfs(to, v, 1);
        }
        else {
            ++c;
        }
    }
    assert((c + add) % 2 == 0);
    ans.emplace_back(v);
    for (int to : g[v]) {
        if (to == p) continue;
        if (sz[to] % 2 == 1) {
            dfs(to, v, 0);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == 0) continue;
        g[i].emplace_back(p);
        g[p].emplace_back(i);
    }
    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    calc(1, -1);
    dfs(1, -1, 0);
    cout << "YES\n";
    for (int v : ans) {
        cout << v << "\n";
    }
    return 0;
}