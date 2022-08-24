#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
set < pair < int, int > > bad;
const int maxN = (int)1e5 + 100;
bool used[maxN];
set < int > unv;
void dfs(int v) {
    used[v] = true;
    unv.erase(v);
    vector < int > will;
    for (int x : unv) {
        if (bad.find(minmax(x, v)) == bad.end()) will.push_back(x);
    }
    for (int p : will) unv.erase(p);
    for (int p : will) dfs(p);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        bad.insert(minmax(x, y));
    }
    for (int i = 1; i <= n; i++) unv.insert(i);
    int cmp = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cmp++;
            dfs(i);
        }
    }
    cout << cmp - 1;
    return 0;
}