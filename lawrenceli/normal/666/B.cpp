#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <ios>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 3005;
const int inf = 1e8;

int n, m;
vector<int> adj[maxn];

int dist[maxn][maxn];
pii mad[maxn][3], mad2[maxn][3];

bool vis[maxn];

void bfs(int st) {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(st);
    for (int t = 0; !q.empty(); t++) {
        int sze = q.size();
        for (int ii = 0; ii < sze; ii++) {
            int x = q.front(); q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            dist[st][x] = t;
            for (int i : adj[x]) q.push(i);
        }
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dist[st][i] = -inf;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) bfs(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            mad[i][j] = pii(-inf, 0);
        for (int j = 1; j <= n; j++) {
            pii p = pii(dist[i][j], j);
            for (int k = 0; k < 3; k++) {
                if (p > mad[i][k]) {
                    pii p2 = mad[i][k];
                    mad[i][k] = p;
                    p = p2;
                }
            }
        }
    }
        
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            mad2[i][j] = pii(-inf, 0);
        for (int j = 1; j <= n; j++) {
            pii p = pii(dist[j][i], j);
            for (int k = 0; k < 3; k++) {
                if (p > mad2[i][k]) {
                    pii p2 = mad2[i][k];
                    mad2[i][k] = p;
                    p = p2;
                }
            }
        }
    }

    int a, b, c, d;
    int ans = -inf;
    //cout << mad[1][0].A << ' ' << mad[1][0].B << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++) {
                    if (i == mad2[i][k].B || j == mad2[i][k].B || i == mad[j][l].B || j == mad[j][l].B || mad2[i][k].B == mad[j][l].B) continue;
                    int x = dist[i][j] + mad2[i][k].A + mad[j][l].A;
                    if (x > ans)
                        ans = x, a = mad2[i][k].B, b = i, c = j, d = mad[j][l].B;
                }
        }

    //cout << ans << endl;
    //cout << dist[a][b] << ' ' << dist[b][c] << ' ' << dist[c][d] << endl;
    
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}