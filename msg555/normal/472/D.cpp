#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

#define MAXN 2020

int D[MAXN][MAXN];
vector<int> E[MAXN];

void no() {
  cout << "NO\n";
  exit(0);
}

void yes() {
  cout << "YES\n";
  exit(0);
}

bool solve(const vector<int>& PI) {
  if(PI.size() <= 1) {
    return true;
  }

  int N = PI.size();
  int u = PI[0];
  int v = PI[1];
  for(int i = 2; i < N; i++) {
    int y = PI[i];
    if(D[u][y] < D[u][v]) {
      v = y;
    }
  }
  E[u].push_back(v);
  E[v].push_back(u);

  vector<int> PI1(1, u);
  vector<int> PI2(1, v);
  for(int i = 0; i < N; i++) {
    int y = PI[i];
    if(u == y || v == y) continue;

    int diff = D[u][y] - D[v][y];
    if (diff != D[u][v] && -diff != D[u][v]) {
      return false;
    }
    if (diff < 0) {
      PI1.push_back(y);
    } else {
      PI2.push_back(y);
    }
  }

  return solve(PI1) && solve(PI2);
}

void dfs(int u, int dst, int p, vector<int>& DD) {
  DD[u] = dst;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if (v != p) {
      dfs(v, dst + D[u][v], u, DD);
    }
  }
}

int main() {
  int N; cin >> N;
  vector<int> PI(N);
  for(int i = 0; i < N; i++) {
    PI[i] = i;
    for(int j = 0; j < N; j++) {
      cin >> D[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(D[i][j] != D[j][i]) {
        no();
      }
      if(i != j && D[i][j] == 0) {
        no();
      }
      if(i == j && D[i][i] != 0) {
        no();
      }
    }
  }

  if (!solve(PI)) {
    no();
  }

  for(int i = 0; i < N; i++) {
    vector<int> DD(N, -1);
    dfs(i, 0, -1, DD);
    for(int j = 0; j < N; j++) {
      if(DD[j] != D[i][j]) {
        no();
      }
    }
  }
  yes();

  return 0;
}