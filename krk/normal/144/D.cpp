#include <cstdio>
#include <vector>
#include <queue>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 2000000000;

int n, m, s;
vector <int> neigh[Maxn], w[Maxn];
int dist[Maxn];
priority_queue <ii> Q;
int l, res;

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(b); w[a].push_back(c);
        neigh[b].push_back(a); w[b].push_back(c);
    }
    scanf("%d", &l);
    fill(dist, dist + n + 1, Inf); dist[s] = 0;
    Q.push(mp(0, s));
    while (!Q.empty()) {
          int s = Q.top().second, d = -Q.top().first; Q.pop();
          if (dist[s] != d) continue;
          if (d == l) res++;
          for (int i = 0; i < neigh[s].size(); i++) {
              int z = neigh[s][i];
              if (d + w[s][i] < dist[z]) {
                    dist[z] = d + w[s][i];
                    Q.push(mp(-dist[z], z));
              }
          }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            int v = neigh[i][j];
            int d = l - dist[i];
            if (d <= 0 || d >= w[i][j]) continue;
            int e = w[i][j] - d;
            if (l < dist[v] + e) res++;
            else if (l == dist[v] + e && i < v) res++;
        }
    printf("%d\n", res);
    return 0;
}