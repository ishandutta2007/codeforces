
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

// nodes with label 1 should be paired off
// So, each component should have either a -1 or an even number of 1's.
// choose a 1 node.
// take a path to another 1 node or a -1 node
// add these edges to the subset and repeat
// but how to do it fast enough?

// 1 -- 0 -- 1 -- 1
//      |
//      1

// greedy doesn't always work
// find a spanning tree
// include an edge if and only if odd parity of 1's on one side

const int N = 3e5 + 5;
int n, m, u[N], v[N], d1[N], d[N], m1[N], dsu[N];
vi edges;
vector<pii> adj[N];
int vis[N];

void dfs(int x) {
    vis[x] = 1;
    for(auto &p : adj[x]) {
        int y = p.se;
        if(vis[y] != 1) {
            dfs(y);
            d[x] ^= d[y];
            m1[x] += m1[y];
        }
    }
}
void dfs2(int x) {
    vis[x] = 2;
    for(auto &p : adj[x]) {
        auto [i, y] = p;
        if(vis[y] != 2) {
            if((d[x] ^ d[y]) == 1 || d[y] == 1) {
                edges.push_back(i);
                if(d1[u[i]] != -1) d1[u[i]] ^= 1;
                if(d1[v[i]] != -1) d1[v[i]] ^= 1;
            }
            d[y] = d[x];
            dfs2(y);
        }
    }
}

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int num1 = 0;
    rep(i, 1, n + 1) {
        cin >> d[i];
        d1[i] = d[i];
        if(d[i] == -1) {
            d[i] = 0;
        }else if(d[i] == 1) {
            num1++;
        }
    }
    if(num1 % 2) {
        rep(i, 1, n + 1) {
            if(d1[i] == -1) {
                d[i] = 1;
                break;
            }
        }
    }
    fill(dsu + 1, dsu + n + 1, -1);
    rep(i, 0, m) {
        cin >> u[i] >> v[i];
        if(trace(u[i]) != trace(v[i])) {
            adj[u[i]].emplace_back(i, v[i]);
            adj[v[i]].emplace_back(i, u[i]);
            join(u[i], v[i]);
        }
    }
    rep(i, 1, n + 1) {
        if(vis[i] == 0) {
            dfs(i);
            dfs2(i);
            if(d[i] == 1 && m1[i] == 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    rep(i, 1, n + 1) {
        if(d1[i] == 1) {
            cout << "-1\n";
            return 0;
        }
    }
    sort(edges.begin(), edges.end());
    cout << sz(edges) << '\n';
    for(auto x : edges) {
        cout << x + 1 << '\n';
    }
}