#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int MXD;
bool H[100010];
vector<int> E[100010];
int memo[100010];

int depth(int u, int p) {
  int& ref = memo[u];
  if(ref != -1) return ref;

  ref = 0;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;
    ref = max(ref, depth(v, u) + 1);
  }

  if(ref == 0 && !H[u]) {
    ref = -2;
  }
  return ref;
}

int solve(int u, int p, int up) {
  if(up > MXD) {
    return 0;
  }

  int result = depth(u, p) <= MXD ? 1 : 0;

  int D0 = -1;
  int D1 = -1;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;

    int dd = depth(v, u) + 1;
    if(dd > D0) {
      D1 = D0;
      D0 = dd;
    } else if(dd > D1) {
      D1 = dd;
    }
  }

  int rup = up == 0 && !H[u] ? 0 : up + 1;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;

    if(depth(v, u) + 1 == D0) {
      result += solve(v, u, max(rup, D1 + 1));
    } else {
      result += solve(v, u, max(rup, D0 + 1));
    }
  }

  return result;
}

int main() {
  int N, M;
  cin >> N >> M >> MXD;

  memset(memo, -1, sizeof(memo));
  for(int i = 0; i < M; i++) {
    int u;
    cin >> u;
    H[u - 1] = true;
  }

  for(int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    E[u].push_back(v);
    E[v].push_back(u);
  }

  cout << solve(0, -1, 0) << endl;
  return 0;
}