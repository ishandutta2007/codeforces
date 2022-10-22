#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = 110;
const int mod = 1e9+7;

int n, m, a[N], b[N];
string s;
int f[N][N][N];
int vis[N];
int dis[N][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    while (tests--) {
        cin >> n;
        for (int i=1; i<=n-1; i++) {
            for (int j=i+1; j<=n; j++) {
                cin >> s;
                for (int k=1; k<=n; k++) {
                    f[i][j][k] = s[k-1] == '1';
                    f[j][i][k] = s[k-1] == '1';
                }
            }
        }

        bool found = 0;
        for (int i=2; i<=n; i++) {
            // check if 1 and i are connected O (N^3)
            queue<pair<int,int>> q;
            for (int j=1; j<=n; j++) vis[j] = 0;
            vis[1] = 1; vis[i] = 1;
            q.push({i,1}); q.push({1,i});
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    dis[i][j] = 1e9;
                }
            }
            for (int i=1; i<=n; i++) dis[i][i] = 0;
            dis[i][1] = 1;
            dis[1][i] = 1;

            vector<pair<int,int>> edges;
            edges.push_back({i,1});

            
            while(!q.empty()) {
                pair<int,int> p = q.front(); q.pop();
                for (int v=1; v<=n; v++) {
                    if (vis[v]) continue;
                    if (f[p.first][v][p.second]) {
                        q.push({p.second, v});
                        edges.push_back({p.second, v});
                        vis[v] = 1;
                        dis[v][p.second] = 1;
                        dis[p.second][v] = 1;
                    }
                }
            }

            if (edges.size() != n-1) {
                continue;
            }

            for (int k=1; k<=n; k++) {
                for (int i=1; i<=n; i++) {
                    for (int j=1; j<=n; j++) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }

            bool stop = 0;
            for (int k=1; k<=n; k++) {
                for (int i=1; i<=n; i++) {
                    for (int j=i+1; j<=n; j++) {
                        if (f[i][j][k] != (dis[i][k] == dis[j][k])) {
                            stop = 1;
                            break;
                        }
                    }
                    if (stop) {
                        break;
                    }
                }
                if (stop) {
                    break;
                }
            }
            if (!stop) {
                found = 1;
                cout << "Yes" << endl;
                for (auto p : edges) {
                    cout << p.first << " " << p.second << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "No" << endl;
        }
    }
}