#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000005;

int n, L;
pair <int, ii> s[Maxn];
int len;
int r[Maxn], l[Maxn], ri[Maxn], li[Maxn], tim[Maxn];
int dist[Maxn], p[Maxn], wth[Maxn];
vector <int> res;

void getRamps(int v)
{
     if (!p[v]) return;
     getRamps(p[v]);
     if (wth[v] == 1) res.push_back(s[p[v]].second.first);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> L;
    s[len++] = make_pair(0, make_pair(0, 1));
    s[len++] = make_pair(L, make_pair(Maxn - 1, 1));
    for (int i = 1; i <= n; i++) {
        int x, d, t, p; cin >> x >> d >> t >> p;
        l[i] = x - p; r[i] = x + d; tim[i] = p + t;
        if (l[i] >= 0) {
                 s[len++] = make_pair(l[i], make_pair(i, 0));
                 s[len++] = make_pair(r[i], make_pair(i, 1));
        }
    }
    sort(s, s + len);
    for (int i = 0; i < len; i++)
        if (s[i].second.second == 0) li[s[i].second.first] = i;
        else ri[s[i].second.first] = i;
    fill(dist, dist + len, Inf); dist[0] = 0;
    priority_queue <pair <int, int> > Q; Q.push(make_pair(0, 0));
    while (!Q.empty()) {
          int v = Q.top().second, d = -Q.top().first; Q.pop();
          if (d > dist[v]) continue;
          if (v) {
                 int cand = dist[v] + s[v].first - s[v - 1].first;
                 if (cand < dist[v - 1]) {
                          dist[v - 1] = cand;
                          p[v - 1] = v; wth[v - 1] = 0;
                          Q.push(make_pair(-dist[v - 1], v - 1));
                 }
          }
          if (v < len - 1) {
                 int cand = dist[v] + s[v + 1].first - s[v].first;
                 if (cand < dist[v + 1]) {
                          dist[v + 1] = cand;
                          p[v + 1] = v; wth[v + 1] = 0;
                          Q.push(make_pair(-dist[v + 1], v + 1));
                 }
          }
          if (s[v].second.second == 0) {
                                 int ind = s[v].second.first;
                                 int u = ri[ind], cand = dist[v] + tim[ind];
                                 if (cand < dist[u]) {
                                          dist[u] = cand;
                                          p[u] = v; wth[u] = 1;
                                          Q.push(make_pair(-dist[u], u));
                                 }
          }
    }
    cout << dist[len - 1] << endl;
    getRamps(len - 1);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size()? " ": "\n");
    return 0;
}