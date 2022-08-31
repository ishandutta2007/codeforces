#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

#define INF 0x3FFFFFFF
#define MAXN 5010

int C[MAXN];
int D[MAXN];
int P[MAXN];

vector<int> E[MAXN];

vector<int> cst1[MAXN];
vector<int> cst2[MAXN];

void solve(int u) {
  int szu = 2;
  cst1[u].push_back(0);
  cst1[u].push_back(C[u] - D[u]);
  cst2[u].push_back(0);
  cst2[u].push_back(C[u]);
  for (int v : E[u]) {
    solve(v);

    int szv = cst1[v].size();
    vector<int> nc1(szu + szv - 1, INF);
    vector<int> nc2(szu + szv - 1, INF);

    nc1[0] = 0;
    nc1[1] = C[u] - D[u];
    for (int i = 1; i < szu; i++) {
      for (int j = 0; j < szv; j++) {
        nc1[i + j] = min(nc1[i + j], cst1[u][i] + cst1[v][j]);
      }
    }
    for (int i = 0; i < szu; i++) {
      for (int j = 0; j < szv; j++) {
        nc2[i + j] = min(nc2[i + j], cst2[u][i] + cst2[v][j]);
      }
    }
    cst1[v].clear();
    cst2[v].clear();

    szu += szv - 1;
    cst1[u].swap(nc1);
    cst2[u].swap(nc2);
  }
  for (int i = 0; i < szu; i++) {
    cst1[u][i] = min(cst1[u][i], cst2[u][i]);
  }
}

int main() {
  int N, B;
  cin >> N >> B;

  for (int i = 0; i < N; i++) {
    cin >> C[i] >> D[i];
    if (i) {
      cin >> P[i];
      P[i]--;
      E[P[i]].push_back(i);
    }
  }

  solve(0);

/*
  for (int i = 0; i < cst1[0].size(); i++) {
    cout << i << ": " << cst1[0][i] << endl;
  }
*/
  cout << upper_bound(cst1[0].begin(), cst1[0].end(), B) - cst1[0].begin() - 1
       << endl;

  return 0;
}