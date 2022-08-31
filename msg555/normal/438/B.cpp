#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 100010

bool added[MAXN];

int P[MAXN];
int S[MAXN];

int uf_find(int x) {
  return P[x] == x ? x : P[x] = uf_find(P[x]);
}

int uf_size(int x) {
  return S[uf_find(x)];
}

bool uf_merge(int x, int y) {
  int X = uf_find(x);
  int Y = uf_find(y);
  if(X == Y) return false;
  int NP = S[X] < S[Y] ? Y : X;
  P[X] = P[Y] = P[x] = P[y] = NP;
  S[NP] = S[X] + S[Y];
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    P[i] = i;
    S[i] = 1;
  }

  vector<pair<int, int> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());

  vector<vector<int> > E(N);
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  long long result = 0;
  for(int i = A.size() - 1; i >= 0; i--) {
    int u = A[i].second;
    added[u] = true;

    long long mul = 1;
    for(int j = 0; j < E[u].size(); j++) {
      int v = E[u][j];
      if(!added[v]) {
        continue;
      }
      int sz = uf_size(v);
      if(uf_merge(u, v)) {
        result += sz * mul * A[i].first;
        mul += sz;
      }
    }
  }

  printf("%.9f\n", 1.0 * result / N / (N - 1) * 2);
  return 0;
}