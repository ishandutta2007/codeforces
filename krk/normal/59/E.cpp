#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;
const int Inf = 1000000000;

struct triple {
       int x, y, z;
       triple(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
       bool operator <(const triple &t) const {
            if (x != t.x) return x < t.x;
            if (y != t.y) return y < t.y;
            return z < t.z;
       }
};

int n, m, k;
vector <int> neigh[Maxn];
set <triple> forb;
int dist[Maxn][Maxn];
ii p[Maxn][Maxn];
queue <ii> Q;

void Print(ii v)
{
     if (v.second) Print(p[v.first][v.second]);
     printf("%d ", v.first);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
          int x, y; scanf("%d %d", &x, &y);
          neigh[x].push_back(y); neigh[y].push_back(x);
    }
    while (k--)  {
          triple t; scanf("%d %d %d", &t.x, &t.y, &t.z);
          forb.insert(t);
    }
    fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
    ii v = mp(1, 0); dist[v.first][v.second] = 0;
    Q.push(v);
    while (!Q.empty()) {
          v = Q.front(); int d = dist[v.first][v.second]; Q.pop();
          if (v.first == n) break;
          triple t; t.x = v.second; t.y = v.first;
          for (int i = 0; i < neigh[v.first].size(); i++) {
              int u = neigh[v.first][i];
              t.z = u;
              if (forb.find(t) == forb.end() && d + 1 < dist[u][v.first]) {
                               dist[u][v.first] = d + 1;
                               p[u][v.first] = v;
                               Q.push(mp(u, v.first));
              }
          }
    }
    if (v.first != n) printf("-1\n");
    else {
         printf("%d\n", dist[v.first][v.second]);
         Print(p[v.first][v.second]); printf("%d\n", n);
    }
    return 0;
}