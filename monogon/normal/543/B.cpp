
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// do bfs to make sure dist(s1, t1) <= l1 and dist(s2, t2) <= l2
// we don't have to minimize distance, just make sure distance remains less than l.
// option 1: take shortest paths.
// otherwise, if they share a vertex,
// there is some vertex v1 where they meet first and v2 where they meet last.
// check dist(v1, v2) + dist(v1, s1) + dist(v2, t1) + dist(v1, s2) + dist(v2, t2)
// and   dist(v1, v2) + dist(v1, s1) + dist(v2, t1) + dist(v1, t2) + dist(v2, s2)

const int N = 3005;
int n, m, u, v, s1, t1, l1, s2, t2, l2, dist[N][N];
vi adj[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    rep(i, 1, n + 1) {
        queue<int> Q;
        Q.push(i);
        fill(vis + 1, vis + n + 1, false);
        vis[i] = true;
        dist[i][i] = 0;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int y : adj[x]) {
                if(!vis[y]) {
                    dist[i][y] = dist[i][x] + 1;
                    vis[y] = true;
                    Q.push(y);
                }
            }
        }
    }
    if(dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << "-1\n";
        return 0;
    }
    int ans = dist[s1][t1] + dist[s2][t2];
    rep(v1, 1, n + 1) {
        rep(v2, 1, n + 1) {
            if(dist[s1][v1] + dist[v1][v2] + dist[v2][t1] <= l1) {
                if(dist[s2][v1] + dist[v1][v2] + dist[v2][t2] <= l2) {
                    ans = min(ans, dist[s1][v1] + dist[v1][v2] + dist[v2][t1] + dist[s2][v1] + dist[v2][t2]);
                }
                if(dist[t2][v1] + dist[v1][v2] + dist[v2][s2] <= l2) {
                    ans = min(ans, dist[s1][v1] + dist[v1][v2] + dist[v2][t1] + dist[t2][v1] + dist[v2][s2]);
                }
            }
        }
    }
    cout << m - ans << '\n';
}