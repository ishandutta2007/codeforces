/*input
1 3 1
100
1 1 2

3 3 3
010
111
010
1 1 4
2 2 2
3 3 2
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 1e3 + 5;

bool b[N][N];
int n, m, Q;
int incc[N][N];
int sz[N * N];

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int numcc = 0;

void bfs(pair<int, int> root) {
    queue<pair<int, int> > q;
    ++numcc;
    q.push(root); incc[root.fi][root.se] = numcc; sz[numcc]++;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        loop(i, 0, 3) {
            int ax = u.fi + dx[i]; int ay = u.se + dy[i];
            if (0 <= ax && ax < n && 0 <= ay && ay < m && incc[ax][ay] == 0 && b[ax][ay] == b[u.fi][u.se]) {
                incc[ax][ay] = numcc; sz[numcc]++;
                q.push({ax, ay});
            }
        }
    }
}

int dis[N][N];
int INF;
void bfsx(vector<pair<int, int> > vec) {
    queue<pair<int, int> > q;
    memset(dis, 127, sizeof(dis));
    INF = dis[0][0];
    for (auto it : vec) dis[it.fi][it.se] = 0, q.push(it);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        loop(i, 0, 3) {
            int ax = u.fi + dx[i]; int ay = u.se + dy[i];
            if (0 <= ax && ax < n && 0 <= ay && ay < m && dis[ax][ay] > dis[u.fi][u.se] + 1 && sz[incc[ax][ay]] == 1) {
                dis[ax][ay] = dis[u.fi][u.se] + 1;
                q.push({ax, ay});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> Q;
    loop(i, 0, n - 1) {
        string s;
        cin >> s;
        loop(j, 0, m - 1) b[i][j] = s[j] - '0';
    }
    loop(i, 0, n - 1) {
        loop(j, 0, m - 1) {
            if (incc[i][j] == 0) {
                bfs({i, j});
            }
        }
    }
    vector<pair<int, int> > vec;
    loop(i, 0, n - 1) {
        loop(j, 0, m - 1) {
            if (sz[incc[i][j]] >= 2) vec.push_back({i, j});
        }
    }
    bfsx(vec);
    loop(cQ, 1, Q) {
        int x, y, t; cin >> x >> y >> t;
        x--; y--; t--;
        if (dis[x][y] == INF) {
            cout << b[x][y] << endl;
        }
        else {
            if (t >= dis[x][y]) {
                if ((t - dis[x][y]) % 2 == 0) cout << (b[x][y] ^ 1) << endl;
                else cout << (b[x][y]) << endl;
            }
            else cout << (b[x][y]) << endl;
        }
        // if (sz[incc[x][y]] >= 2) {
        //     if (t % 2 == 1) cout << (b[x][y] ^ 1);
        //     else cout << b[x][y];
        // }
        // else {
        //     loop(i, 0, 3) {
        //         int ax = u.fi + dx[i]; int ay = u.se + dy[i];
        //         if (0 <= ax && ax < n && 0 <= ay && ay < m && incc[ax][ay] == 0 && b[ax][ay] == b[u.fi][u.se]) {
        //             incc[ax][ay] = numcc; sz[numcc]++;
        //         }
        //     }
        // }
    }
}