#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef pair<pair<int, int>, pair<int, int> > edge;
typedef pair<pair<int, int>, pair<int, int> > data;

const int maxn = 500100;

int n, m;
edge edges[maxn];
vector<int> adj[maxn];
int adjpnt[2][maxn];

int dist[2][2][maxn];

inline int getv(int i, int b) {
    return b ? edges[i].A.B : edges[i].A.A;
}

bool cmp(int i1, int i2) {
    return edges[i1].B.A < edges[i2].B.A;
}

int main() {
    scanf("%d %d", &n, &m);
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &edges[i].A.A, &edges[i].A.B, &edges[i].B.A, &edges[i].B.B);
        adj[edges[i].A.A].push_back(i);
        adj[edges[i].A.B].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), cmp);

    memset(dist, -1, sizeof(dist));
    priority_queue<data, vector<data>, greater<data> > pq;
    for (int i : adj[1])
        if (edges[i].B.A == 0) pq.push(MP(MP(0, i), MP(0, getv(i, 1) == 1)));

    while (!pq.empty()) {
        int d = pq.top().A.A, i = pq.top().A.B, a = pq.top().B.A, b = pq.top().B.B;
        pq.pop();
        if (dist[a][b][i] != -1) continue;
        dist[a][b][i] = d;

        int v = getv(i, b);
        while (adjpnt[a][v] < adj[v].size()) {
            int j = adj[v][adjpnt[a][v]];
            int l = edges[j].B.A, r = edges[j].B.B;
            if (d < l) {
                int l2 = l + int((l - d) & 1);
                if (l2 > edges[i].B.B) break;
                if (l2 < r) {
                    int b2 = (getv(j, 1) == v);
                    pq.push(MP(MP(l2, j), MP(l2 & 1, b2)));
                }
                adjpnt[a][v]++;
                continue;
            }

            if (d >= r) {
                adjpnt[a][v]++;
                continue;
            }

            int b2 = (getv(j, 1) == v);
            if (dist[a][b2][j] == -1) {
                pq.push(MP(MP(d, j), MP(a, b2)));
            }
            adjpnt[a][v]++;
        }

        if (d < edges[i].B.B && dist[!a][!b][i] == -1) {
            pq.push(MP(MP(d + 1, i), MP(!a, !b)));
        }
    }

    int ans = 2e9;
    for (int i = 0; i < m; i++) {
        int a = edges[i].A.A, b = edges[i].A.B;
        if (a == n) {
            int d1 = dist[0][0][i], d2 = dist[1][0][i];
            if (d1 != -1) ans = min(ans, d1);
            if (d2 != -1) ans = min(ans, d2);
        } else if (b == n) {
            int d1 = dist[0][1][i], d2 = dist[1][1][i];
            if (d1 != -1) ans = min(ans, d1);
            if (d2 != -1) ans = min(ans, d2);
        }
    }

    if (ans == (2e9)) printf("-1\n");
    else printf("%d\n", ans);
}