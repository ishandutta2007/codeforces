#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// EVEN
//   ENDS: Degree is 3 + 4k
//   ELSE: Degree is 4k

// ODD
//   ENDS: Degree is 1 + 4k
//   ELSE: Degree is 2 + 4k

#define MAXN 100010

int N;
vector<int> E[MAXN];
vector<int> R;

int X[MAXN];
bool vis[MAXN];

bool dfs(int u) {
  if(vis[u]) return false;
  vis[u] = true;

  bool res = X[u] == 1;
  for(int i = 0; i < E[u].size(); i++) {
    res |= dfs(E[u][i]);
  }
  return res;
}

void dfs2(int u, int p) {
  vis[u] = true;

  X[u] = 1 - X[u];
  R.push_back(u);

  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(vis[v]) continue;

    dfs2(v, u);

    X[u] = 1 - X[u];
    R.push_back(u);
  }

  if(X[u]) {
    if(p == -1) {
      R.resize(R.size() - 1);
    } else {
      X[p] = 1 - X[p];
      R.push_back(p);
      X[u] = 1 - X[u];
      R.push_back(u);
    }
  }
}

int main() {
  int M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i = 0; i < N; i++) {
    cin >> X[i];
  }

  int xs = -1;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;

    if(dfs(i)) {
      if(xs == -1) {
        xs = i;
      } else {
        cout << "-1\n";
        return 0;
      }
    }
  }
  if(xs == -1) {
    cout << "0\n";
  } else {
    memset(vis, 0, sizeof(vis));
    dfs2(xs, -1);

    cout << R.size() << '\n';
    for(int i = 0; i < R.size(); i++) {
      if(i) cout << ' ';
      cout << R[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}