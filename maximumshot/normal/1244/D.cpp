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

const int N = 1e5 + 5;

int n;
int c[3][N];
vector<int> g[N];
ll dp[N][3][3];
int fr[N][3][3];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 3; i++) {
        for (int v = 1; v <= n; v++) {
            cin >> c[i][v];
        }
    }

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int st = -1, fn = -1;

    for (int v = 1; v <= n; v++) {
        if ((int) g[v].size() > 2) {
            cout << "-1\n";
            return 0;
        }
        if ((int) g[v].size() == 1) {
            if (st == -1) {
                st = v;
            } else {
                fn = v;
            }
        }
    }

    vector<int> dist(n + 1, inf), from(n + 1, -1);
    queue<int> q;

    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    vector<int> path;

    for (int x = fn; ; x = from[x]) {
        path.push_back(x);
        if (x == st) break;
    }

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                dp[i][x][y] = inf64;
                fr[i][x][y] = -1;
            }
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (x == y) {
                continue;
            }
            dp[1][x][y] = c[x][path[0]] + c[y][path[1]];
        }
    }

    for (int i = 2; i < n; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    if (x == y || x == z || y == z) continue;
                    ll tmp_cost = dp[i - 1][x][y] + c[z][path[i]];
                    if (dp[i][y][z] > tmp_cost) {
                        dp[i][y][z] = tmp_cost;
                        fr[i][y][z] = x;
                    }
                }
            }
        }
    }

    int bx, by;
    ll res = inf64;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (x == y) continue;
            if (res > dp[n - 1][x][y]) {
                res = dp[n - 1][x][y];
                bx = x;
                by = y;
            }
        }
    }

    cout << res << "\n";

    vector<int> color(n + 1);

    color[path[n - 1]] = by + 1;
    color[path[n - 2]] = bx + 1;

    for (int i = n - 1; i > 1; i--) {
        int toy = bx;
        int tox = fr[i][bx][by];
        bx = tox;
        by = toy;
        color[path[i - 2]] = bx + 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }

    cout << "\n";

    return 0;
}