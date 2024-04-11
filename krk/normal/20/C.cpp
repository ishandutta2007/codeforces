#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100001;
const ll Inf = 100000000000000LL;

int n, m, p[Maxn];
vector <int> neigh[Maxn], cost[Maxn];

void Dijkstra()
{
     ll dist[Maxn]; fill(dist, dist + Maxn, Inf);
     bool taken[Maxn] = {};
     fill(p, p + Maxn, -1);
     priority_queue <pair <int, int> > Q;
     dist[1] = 0; Q.push(make_pair(0, 1));
     while (!Q.empty()) {
           int v = Q.top().second; Q.pop();
           if (taken[v]) continue;
           taken[v] = true;
           for (int i = 0; i < neigh[v].size(); i++)
              if (dist[v] + ll(cost[v][i]) < dist[neigh[v][i]]) {
                          dist[neigh[v][i]] = dist[v] + ll(cost[v][i]);
                          p[neigh[v][i]] = v;
                          Q.push(make_pair(-dist[neigh[v][i]], neigh[v][i]));
              }
     }
}

void Print(int x)
{
     if (x != 1) {
           Print(p[x]); printf(" ");
     }
     printf("%d", x);
}

int main()
{
    int a, b, c;
    scanf("%d %d", &n, &m);
    while (m--) {
          scanf("%d %d %d", &a, &b, &c);
          neigh[a].push_back(b); cost[a].push_back(c);
          neigh[b].push_back(a); cost[b].push_back(c);
    }
    Dijkstra();
    if (p[n] == -1) printf("-1\n");
    else {
         Print(n); printf("\n");
    }
    return 0;
}