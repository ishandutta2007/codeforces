#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

inline void upd_edge(set<pii>& es, int u, int v, int type) {
    if (u > v) swap(u, v);
    if (type == +1)
        es.insert({u, v});
    else
        es.erase({u, v});
}

void rec(
    int n,
    vector<int>& d,
    set<pii>& mnd,
    vector<vector<int>>& a,
    vector<set<int>>& b,
    set<pii>& es,
    vector<int>& t,
    set<int>& tot
) {
    if (n == 3) {
        int id = *tot.begin();
        t.push_back(id);
        tot.erase(id);
        for (int i = 0; i < 3; i++) {
            int u = a[id][i];
            int v = a[id][(i + 1) % 3];
            upd_edge(es, u, v, +1);
        }
        return;
    }
    int v = mnd.begin()->second;
    mnd.erase(mnd.begin());
    int id = *b[v].begin();
    int x = -1, y = -1;
    for (int i = 0; i < 3; i++) {
        if (a[id][i] == v)
            continue;
        if (x == -1)
            x = a[id][i];
        else
            y = a[id][i];
    }
    t.push_back(id);
    mnd.erase({d[x], x});
    mnd.erase({d[y], y});
    d[x]--, d[y]--;
    mnd.insert({d[x], x});
    mnd.insert({d[y], y});
    b[x].erase(id);
    b[y].erase(id);
    n--;
    tot.erase(id);
    rec(n, d, mnd, a, b, es, t, tot);
    upd_edge(es, x, y, -1);
    upd_edge(es, x, v, +1);
    upd_edge(es, y, v, +1);
}

void dfs(int v, vector<int>& used, const vector<vector<int>>& g) {
    if (used[v])
        return;
    used[v] = 1;
    cout << v << " ";
    for (int to : g[v]) {
        dfs(to, used, g);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n - 2, vector<int>(3));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> d(n + 1);
    set<pii> mnd;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            d[a[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++)
        mnd.insert({d[i], i});
    set<int> tot;
    for (int i = 0; i < n - 2; i++)
        tot.insert(i);
    vector<set<int>> b(n + 1);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            b[a[i][j]].insert(i);
        }
    }
    vector<int> t;
    set<pii> es;
    rec(n, d, mnd, a, b, es, t, tot);
    vector<vector<int>> g(n + 1);
    for (pii e : es) {
        int u, v;
        tie(u, v) = e;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> used(n + 1);
    dfs(1, used, g);
    cout << "\n";
    for (int id : t) {
        cout << id + 1 << " ";
    }
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}