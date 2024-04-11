#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 100000000000000000LL;
const int Maxn = 1005;

int n, m, x, y;
vector <ll> neigh[Maxn], len[Maxn];
ll dist[Maxn];
bool graph[Maxn][Maxn];
ll t[Maxn], c[Maxn];

void Dijkstra(int v)
{
     fill(dist, dist + Maxn, Inf); dist[v] = 0;
     priority_queue <pair <ll, int> > Q; Q.push(make_pair(0, v));
     while (!Q.empty()) {
           v = Q.top().second; ll d = -Q.top().first; Q.pop();
           if (d > dist[v]) continue;
           for (int i = 0; i < neigh[v].size(); i++)
              if (d + len[v][i] < dist[neigh[v][i]]) {
                    dist[neigh[v][i]] = d + len[v][i];
                    Q.push(make_pair(-dist[neigh[v][i]], neigh[v][i]));
              }
     }
}

void Dijkstra2()
{
     fill(dist, dist + Maxn, Inf); dist[x] = 0;
     priority_queue <pair <ll, int> > Q; Q.push(make_pair(0, x));
     while (!Q.empty()) {
           x = Q.top().second; ll d = -Q.top().first; Q.pop();
           if (d > dist[x]) continue;
           for (int i = 1; i <= n; i++)
              if (graph[x][i] && d + c[x] < dist[i]) {
                    dist[i] = d + c[x];
                    Q.push(make_pair(-dist[i], i));
              }
     }
}

int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        neigh[a].push_back(b); len[a].push_back(c);
        neigh[b].push_back(a); len[b].push_back(c);
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        Dijkstra(i);
        for (int j = 1; j <= n; j++)
           graph[i][j] = dist[j] <= t[i];
    }
    Dijkstra2();
    if (dist[y] < Inf) cout << dist[y] << endl;
    else cout << "-1\n";
    return 0;
}