#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXK = 505;

int n, m, k;
vector<pii> adj[MAXN];
int dist[MAXK][MAXK];
int id[MAXN], cmp[MAXN], cnt;

void dfs(int cur) {
    if (cmp[cur] != -1) return;
    cmp[cur] = cnt;
    for (int i=0; i<adj[cur].size(); i++)
        if (!adj[cur][i].se)
            dfs(adj[cur][i].fi);
}

void setmin(int& a, int b) { if (a == -1 || a > b) a = b; }

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        int c; cin >> c;
        for (int j=0; j<c; j++) id[cnt++] = i;
    }

    for (int i=0; i<m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        adj[u].push_back(pii(v, x));
        adj[v].push_back(pii(u, x));
    }

    cnt = 0;
    memset(cmp, -1, sizeof(cmp));
    for (int i=0; i<n; i++)
        if (cmp[i] == -1)
            dfs(i), cnt++;

    for (int i=0; i<n; ) {
        int j;
        for (j=i; j<n && id[i] == id[j]; j++)
            if (cmp[i] != cmp[j]) {
                cout << "No\n";
                return 0;
            }
        i = j;
    }

    cout << "Yes\n";

    memset(dist, -1, sizeof(dist));
    for (int i=0; i<n; i++)
        for (int j=0; j<adj[i].size(); j++)
            setmin(dist[id[i]][id[adj[i][j].fi]], adj[i][j].se);

    for (int i=0; i<k; i++) dist[i][i] = 0;

    for (int K=0; K<k; K++) {
        for (int i=0; i<k; i++)
            for (int j=0; j<k; j++)
                if (dist[i][K] != -1 && dist[K][j] != -1)
                    setmin(dist[i][j], dist[i][K] + dist[K][j]);
    }

    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}