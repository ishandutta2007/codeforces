#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 505;

int n, m;
vector<int> g[N];
int G[N][N];
int deleted[N];

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
    G[u][v] = G[v][u] = 1;
}

int ask(int u) {
    cout << u << endl;
    string response;
    cin >> response;
    if (response == "FOUND") {
        return -1;
    } else {
        int w;
        cin >> w;
        return w;
    }
}

int tin[N];
int fup[N];
int timer;
int used[N];
int sz[N];
int total_num_of_vs;
int best_c, best_c_mx;

void dfs(int v, int from = -1) {
    sz[v] = 1;
    used[v] = 1;
    tin[v] = fup[v] = timer++;

    int chld = 0;
    int mx_sz = 0;
    int is_cp = 0;

    for (int to : g[v]) {
        if (deleted[to]) continue;
        if (to == from) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            chld++;
            sz[v] += sz[to];
            mx_sz = max(mx_sz, sz[to]);
            if (from != -1 && fup[to] >= tin[v]) {
                is_cp = 1;
            }
        }
    }

    if (from == -1 && chld > 1) {
        is_cp = 1;
    }

    if (!is_cp) {
        mx_sz = total_num_of_vs - 1;
    } else {
        mx_sz = max(mx_sz, total_num_of_vs - sz[v]);
    }

//    cout << v << " : " << mx_sz << ", tin = " << tin[v] << "\n";

    if (best_c_mx > mx_sz) {
        best_c_mx = mx_sz;
        best_c = v;
    }
}

int get_centroid() {
    timer = 0;
    fill(tin + 1, tin + n + 1, 0);
    fill(fup + 1, fup + n + 1, 0);
    fill(used + 1, used + n + 1, 0);
    fill(sz + 1, sz + n + 1, 0);

    total_num_of_vs = count(deleted + 1, deleted + n + 1, 0);

    best_c = -1;
    best_c_mx = inf;

    for (int v = 1; v <= n; v++) {
        if (deleted[v]) continue;
        dfs(v);
        return best_c;
    }
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    fill((int*) G, (int*) G + N * N, inf);

    for (int i = 0; i < m; i++) {
        int ki;
        cin >> ki;
        for (int last = -1, cur, j = 1; j <= ki; j++) {
            cin >> cur;
            if (last == -1) {
                last = cur;
                continue;
            }
            add_edge(last, cur);
            last = cur;
        }
    }

    for (int w = 1; w <= n; w++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                G[u][v] = min(G[u][v], G[u][w] + G[w][v]);
            }
        }
    }

    for (int u = 1; u <= n; u++) G[u][u] = 0;

    for (int iter = 0; iter < n; iter++) {
        fill(deleted + 1, deleted + n + 1, 0);
        while (1) {
            int centroid = get_centroid();
            int nxt = ask(centroid);
            if (nxt == -1) {
                break;
            }
            for (int v = 1; v <= n; v++) {
                if (G[nxt][v] >= G[centroid][v]) {
                    deleted[v] = 1;
                }
            }
        }
    }

    return 0;
}