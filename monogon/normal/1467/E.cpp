
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

const int N = 2e5 + 5;
int n;
int a[N], tin[N], tout[N], ti = 0;
vi adj[N];
set<pii> se[N];
int p[N];

void addrange(int l, int r, int val) {
    p[l] += val;
    p[r] -= val;
}

void dfs1(int x, int p) {
    tin[x] = ti++;
    for(int y : adj[x]) {
        if(y != p) {
            dfs1(y, x);
        }
    }
    tout[x] = ti;
}

void dfs(int x, int p) {
    int cnt = 0;
    for(int y : adj[x]) {
        if(y != p) {
            dfs(y, x);
            auto it = se[y].lower_bound({a[x], -1});
            if(it != se[y].end() && it->first == a[x]) {
                cnt++;
                addrange(tin[1], tout[1], 1);
                addrange(tin[y], tout[y], -1);
            }
            if(sz(se[y]) <= sz(se[x])) {
                se[x].insert(all(se[y]));
            }else {
                se[y].insert(all(se[x]));
                se[x].swap(se[y]);
            }
        }
    }
    if(cnt >= 2) {
        cout << 0 << '\n';
        exit(0);
    }
    auto lo = se[x].lower_bound({a[x], -1});
    auto up = se[x].lower_bound({a[x] + 1, -1});
    if(lo != up) {
        for(auto it = lo; it != up; it++) {
            addrange(tin[it->second], tout[it->second], 1);
        }
        se[x].erase(lo, up);
    }
    se[x].insert({a[x], x});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 1);
    dfs(1, 1);
    map<int, vi> ma;
    for(auto &pa : se[1]) ma[pa.first].push_back(pa.second);
    for(auto &pa : ma) {
        vi &ve = pa.second;
        if(sz(ve) >= 2) {
            for(int x : ve) {
                addrange(tin[x], tout[x], 1);
            }
        }
    }
    int ans = 0, sum = 0;
    rep(i, 0, n) {
        sum += p[i];
        ans += (sum == 0);
    }
    cout << ans << '\n';
}