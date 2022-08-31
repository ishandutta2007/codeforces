#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define MAXV 1000000010

int N;
int F[302][302];
int C[302][302];
vector<int> E[2][302];

bool vis[302][2];

int dfs(int x, bool s, int mxf) {
  if(x == N && !s) return mxf;
  if(vis[x][s]) return 0;
  vis[x][s] = true;

  int res = 0;
  for(int i = 0; mxf != 0 && i < E[s][x].size(); i++) {
    int y = E[s][x][i];

    int fm = s ? F[y][x] : C[x][y] - F[x][y];
    if(x != N && mxf < fm) fm = mxf;

    if(fm != 0) {
      fm = dfs(y, !s, fm);
      res += fm;
      mxf -= fm;

      if(s) {
        F[y][x] -= fm;
      } else {
        F[x][y] += fm;
      }
    }
  }
  return res;
}

void addedge(int u, int v, int f, int c) {
  E[0][u].push_back(v);
  E[1][v].push_back(u);
  F[u][v] = f; C[u][v] = c;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int M; cin >> M;
    for(int j = 0; j < M; j++) {
      int x; cin >> x; x--;
      addedge(i, x, 0, MAXV);
    }
  }
  int res = -MAXV * N;
  for(int i = 0; i < N; i++) {
    int w; cin >> w;
    res += w;
    addedge(i, N, MAXV - w, MAXV - w);
    addedge(N, i, MAXV, MAXV);
  }
  for(int f = -1; f != 0; ) {
    memset(vis, 0, sizeof(vis));
    res += (f = dfs(N, true, -1));
  }
  cout << res << endl;
}