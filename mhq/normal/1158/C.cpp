#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 500 * 1000 + 5;
int n;
int nxt[maxN];
vector < int > g[maxN];
set < int > clr0;
vector < int > ord;
int clr[maxN];
bool ALL_OK = true;
void dfs(int v) {
    clr[v] = 1;
    if (!ALL_OK) return;
    for (int to : g[v]) {
        if (clr[to] == 1) {
            ALL_OK = false;
            return;
        }
        if (clr[to] == 0) {
            dfs(to);
            if (!ALL_OK) return;
        }
    }
    if (nxt[v] != -1) {
        while (true) {
            auto it = clr0.lower_bound(v + 1);
            if (it == clr0.end() || (*it >= nxt[v])) break;
            int to = *it;
            if (clr[to] == 1) {
                ALL_OK = false;
                return ;
            }
            dfs(to);
            if (!ALL_OK) return;
        }
    }
    clr0.erase(v);
    ord.push_back(v);
    clr[v] = 2;
}
int p[maxN];
void solve() {
    cin >> n;
    ALL_OK = true;
    clr0.clear();
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        clr[i] = 0;
    }
    ord.clear();
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        clr0.insert(i);
        if (nxt[i] != -1) g[nxt[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (clr[i] == 0) dfs(i);
    }
    if (!ALL_OK) {
        cout << -1 << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++) {
        p[ord[i - 1]] = i;
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}