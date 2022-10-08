
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// indices in priority queue instead? (color priority, color number)
// enter node -> all occupied colors have their priorities updated to current depth
// new ice uses color with lowest priority, possibly colliding with ice cream of lower depth
// exit node -> reset all color priorities

const int N = 3e5 + 5;
int n, m, s[N], u, v, color[N], depth[N];
vi adj[N], ice[N];
stack<int> prio[N];
bool vis[N];
set<pii> Q;

void dfs(int x) {
    for(int ty : ice[x]) {
        if(color[ty] != 0) {
            Q.erase(Q.find(make_pair(prio[color[ty]].top(), color[ty])));
            prio[color[ty]].push(depth[x]);
            Q.emplace(depth[x], color[ty]);
        }
    }
    vector<pii> v;
    for(int ty : ice[x]) {
        if(color[ty] == 0) {
            pii p = *Q.begin();
            Q.erase(Q.begin());
            Q.emplace(depth[x], p.se);
            color[ty] = p.se;
            prio[color[ty]].push(depth[x]);
            v.push_back(p);
        }
    }
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            dfs(y);
        }
    }
    for(int ty : ice[x]) {
        Q.erase(Q.find(make_pair(prio[color[ty]].top(), color[ty])));
        prio[color[ty]].pop();
        Q.emplace(prio[color[ty]].top(), color[ty]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int c = 1;
    rep(i, 1, n + 1) {
        cin >> s[i];
        ice[i].assign(s[i], 0);
        rep(j, 0, s[i]) {
            cin >> ice[i][j];
        }
        c = max(c, s[i]);
    }
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, c + 1) {
        Q.emplace(-1, i);
        prio[i].push(-1);
    }
    dfs(1);
    cout << c << '\n';
    rep(i, 1, m + 1) {
        cout << max(1, color[i]) << ' ';
    }
    cout << '\n';
}