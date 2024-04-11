#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 3e5 + 10;
ll tot[maxN];
int p[maxN];
int get(int a) {
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}
int sz[maxN];
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    tot[a] += tot[b];
    p[b] = a;
    return true;
}
vector<int> ans;
vector<pair<int,int>> ini[maxN];
ll a[maxN];
int x;
bool used[maxN];
vector<pair<int,int>> g[maxN];
void ini_dfs(int v) {
    used[v] = true;
    for (auto& it : ini[v]) {
        if (used[it.first]) continue;
        g[v].emplace_back(it);
        g[it.first].emplace_back(v, it.second);
        ini_dfs(it.first);
    }
}
deque<int> d;
int deg[maxN];
pair<int,int> par[maxN];
void go(int v, int p) {
     for (auto& it : g[v]) {
         if (it.first == p) continue;
         deg[v]++;
         par[it.first] = make_pair(v, it.second);
         go(it.first, v);
     }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> x;
    ll cost = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
        sz[i] = 1;
        tot[i] = a[i];
        cost += tot[i];
    }
    if (cost < 1LL * (n - 1) * x) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ini[x].emplace_back(y, i);
        ini[y].emplace_back(x, i);
    }
    ini_dfs(1);
    memset(used, 0, sizeof used);
    go(1, -1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    vector<pair<int,int>> add;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        if (it == 1) break;
        if (a[it] < x) {
            add.emplace_back(par[it].second, 1);
        }
        else {
            add.emplace_back(par[it].second, 0);
            a[par[it].first] += a[it] - x;
        }
        deg[par[it].first]--;
        if (deg[par[it].first] == 0) {
            q.push(par[it].first);
        }
    }
    reverse(add.begin(), add.end());
    for (auto& it : add) {
        if (it.second == 1) {
            d.push_back(it.first);
        }
        else {
            d.push_front(it.first);
        }
    }
    cout << "YES\n";
    assert((int)d.size() == n - 1);
    for (int& v : d) cout << v << "\n";
    return 0;
}