
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int N = 5e5 + 5;
int n, m;
vector<pii> adj[N], adjr[N];
bool ans[N];
int dist[N];
bool vis[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].emplace_back(v, t);
        adjr[v].emplace_back(u, t);
    }
    queue<int> Q;
    Q.push(n);
    vis[0][n] = vis[1][n] = true;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(auto &pa : adjr[x]) {
            int y, t;
            tie(y, t) = pa;
            if(!vis[t][y]) {
                vis[t][y] = true;
                if(vis[!t][y]) {
                    dist[y] = dist[x] + 1;
                    Q.push(y);
                }else ans[y] = !t;
            }
        }
    }
    if(vis[ans[1]][1]) {
        cout << dist[1] << '\n';
    }else {
        cout << "-1\n";
    }
    rep(i, 1, n + 1) cout << ans[i];
    cout << '\n';
}