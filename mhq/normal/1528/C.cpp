#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3e5 + 10;
vector<int> first_tree[maxN];
vector<int> second_tree[maxN];
int tin[maxN], tout[maxN];
int timer = 0;
void dfs_sec(int v) {
    tin[v] = timer++;
    for (int to : second_tree[v]) {
        dfs_sec(to);
    }
    tout[v] = timer++;
}
int mx;
set<pair<int,int>> s;
void dfs_first(int v) {
    pair<int,int> t = make_pair(-1, -1);
    auto it = s.lower_bound(make_pair(tin[v], tout[v]));
    if (it != s.begin()) {
        --it;
        if ((it->first) <= tin[v] && tout[v] <= (it->second)) {
            t = *it;
            s.erase(it);
            s.insert(make_pair(tin[v], tout[v]));
        }
        else {
            s.insert(make_pair(tin[v], tout[v]));
        }
    }
    else {
        s.insert(make_pair(tin[v], tout[v]));
    }
    mx = max(mx, (int)s.size());
    for (int to : first_tree[v]) {
        dfs_first(to);
    }
    s.erase(make_pair(tin[v], tout[v]));
    if (t.first != -1) s.insert(t);
}
void solve() {
    timer = 0;
    s.clear();
    mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        first_tree[i].clear();
        second_tree[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        first_tree[par].emplace_back(i);
    }

    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        second_tree[par].emplace_back(i);
    }
    dfs_sec(1);
    dfs_first(1);
    cout << mx << '\n';
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