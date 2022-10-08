
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct dsu {
    vector<int> a;
    dsu(size_t n) {
        a.assign(n, -1);
    }
    size_t find(size_t x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    size_t size(size_t x) {
        return -a[find(x)];
    }
    bool join(size_t x, size_t y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    set<pii> ed;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ed.insert({u, v});
        ed.insert({v, u});
    }
    // 0 -> remove parent edge
    // 1 -> don't
    vi dp0(n + 1), dp1(n + 1);
    vi ch0(n + 1), ch1(n + 1);
    function<void(int, int)> dfs = [&](int x, int p) {
        vector<pii> a(2, make_pair(0, -1));
        int sum = 0;
        for(int y : g[x]) {
            if(y != p) {
                dfs(y, x);
                sum += 1 + dp0[y];
                a.push_back({dp1[y] - (1 + dp0[y]), y});
            }
        }
        sort(all(a));
        ch0[x] = a[0].second;
        ch1[x] = a[1].second;
        dp0[x] = sum + a[0].first + a[1].first;
        dp1[x] = sum + a[0].first;
    };
    vector<pii> add, rem;
    function<void(int, int, bool)> dfs2 = [&](int x, int p, bool b) {
        for(int y : g[x]) {
            if(y != p) {
                if(y == ch0[x] || (!b && y == ch1[x])) {
                    dfs2(y, x, 1);
                }else {
                    rem.push_back({x, y});
                    ed.erase({x, y});
                    ed.erase({y, x});
                    dfs2(y, x, 0);
                }
            }
        }
    };
    dfs(1, 1);
    dfs2(1, 1, 0);
    dsu D(n + 1);
    vi deg(n + 1, 0);
    for(auto &pa : ed) {
        D.join(pa.first, pa.second);
        deg[pa.first]++;
        deg[pa.second]++;
    }
    vector<vi> ve(n + 1);
    rep(i, 1, n + 1) {
        if(deg[i] <= 2) ve[D.find(i)].push_back(i);
        if(deg[i] == 0) ve[D.find(i)].push_back(i);
    }
    int last = -1;
    rep(i, 1, n + 1) {
        if(!ve[i].empty()) {
            if(last != -1) add.push_back({last, ve[i][0]});
            last = ve[i][1];
        }
    }
    
    cout << dp0[1] << '\n';
    assert(dp0[1] == sz(add) && dp0[1] == sz(rem));
    rep(i, 0, dp0[1]) {
        cout << rem[i].first << ' ' << rem[i].second << ' ' << add[i].first << ' ' << add[i].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}