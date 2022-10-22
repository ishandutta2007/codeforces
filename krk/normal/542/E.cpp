#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[Maxn];
int col[Maxn];
vector <int> seq;
int dist[Maxn];
int res;

int getDist(int v)
{
    fill(dist, dist + n + 1, Inf); dist[v] = 0;
    queue <int> Q; Q.push(v);
    int res = 0;
    while (!Q.empty()) {
        v = Q.front(); Q.pop();
        res = dist[v];
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
    return res;
}

bool Bicolour(int v, int c)
{
    if (col[v]) return col[v] == c;
    col[v] = c;
    seq.push_back(v);
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Bicolour(neigh[v][i], -c)) return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!col[i]) {
        seq.clear();
        if (!Bicolour(i, 1)) {
            printf("-1\n");
            return 0;
        }
        int mx = 0;
        for (int j = 0; j < seq.size(); j++)
            mx = max(mx, getDist(seq[j]));
        res += mx;
    }
    printf("%d\n", res);
    return 0;
}