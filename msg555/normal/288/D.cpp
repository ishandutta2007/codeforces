#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long bigint;

bigint N;
bigint result = 0;
vector<int> E[80010];

bigint solve(int u, int p) {
  bigint ret = 1;
  vector<bigint> H(1, 1);
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;
    H.push_back(solve(v, u));
    ret += H.back();
  }
  H.push_back(N - ret);

  bigint inner = 0;
  for(int i = 0; i < H.size(); i++) {
    inner += H[i] * H[i];
  }
  for(int i = 1; i < H.size(); i++) {
    result += H[i] * (N * N - inner) + H[i] * (N - H[i]) *
            ((N - H[i]) * N - (inner - H[i] * H[i]) - (N - H[i]) * H[i]);
  }
  return ret;
}

int main() {
  int nn; cin >> nn;
  N = nn;
  for(int i = 1; i < nn; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  solve(0, -1);
  cout << (N * (N - 1) * N * (N - 1) - result) / 4 << endl;
  return 0;
}