#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1000000000

vector<pair<int, int> > dodist(const vector<vector<int> >& E, int s) {
  int N = E.size();
  vector<bool> vis(N);
  vis[s] = true;
  queue<pair<int, int> > q;
  q.push(make_pair(0, s));

  vector<pair<int, int> > res;
  while (!q.empty()) {
    int d = q.front().first;
    int u = q.front().second;
    q.pop();

    for (int v : E[u]) {
      if (!vis[v]) {
        vis[v] = true;
        q.push(make_pair(d + 1, v));
        res.push_back(make_pair(d + 1, v));
      }
    }
  }

  reverse(res.begin(), res.end());
  return res;
}



int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int> > E(N);
  vector<vector<int> > RE(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    RE[v].push_back(u);
  }

  vector<vector<pair<int, int> > > dto(N);
  vector<vector<pair<int, int> > > dfr(N);
  for (int i = 0; i < N; i++) {
    dto[i] = dodist(E, i);
    dfr[i] = dodist(RE, i);
  }

  int best = 0;
  vector<int> res(4, -1);
  for (int i = 0; i < N; i++) {
    for (int jj = 0; jj < dto[i].size(); jj++) {
      int j = dto[i][jj].second;
      for (int a = 0; a < 3 && a < dfr[i].size(); a++) {
        for (int b = 0; b < 3 && b < dto[j].size(); b++) {
          
          int x = dfr[i][a].second;
          int y = dto[j][b].second;
          if (x == y || x == j || i == y) {
            continue;
          }

          int dist = dto[i][jj].first +
                     dfr[i][a].first +
                     dto[j][b].first;
          if (dist < best) {
            continue;
          }

          best = dist;
          res[0] = dfr[i][a].second;
          res[1] = i;
          res[2] = j;
          res[3] = dto[j][b].second;
        }
      }
    }
  }

  cerr << best << endl;
  for (int i = 0; i < res.size(); i++) {
    if (i) cout << ' ';
    cout << res[i] + 1;
  }
  cout << endl;
  return 0;
}