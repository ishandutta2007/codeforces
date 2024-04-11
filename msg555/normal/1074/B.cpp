#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void dfs(vector<vector<int> >& E, vector<int>& dist, int u, int p, int d) {
  dist[u] = d;
  for (int v : E[u]) {
    if (v != p) {
      dfs(E, dist, v, u, d + 1);
    }
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<vector<int> > E(N);
    for (int i = 1; i < N; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    int K1; cin >> K1;
    vector<int> V1(K1);
    for (int i = 0; i < K1; i++) {
      cin >> V1[i];
      V1[i]--;
    }

    int K2; cin >> K2;
    vector<int> V2(K2);
    for (int i = 0; i < K2; i++) {
      cin >> V2[i];
      V2[i]--;
    }

    cout << "B " << V2[0] + 1 << endl;

    int v0;
    cin >> v0;
    v0--;
    vector<int> dist(N);
    dfs(E, dist, v0, -1, 0);

    int cl = -1;
    for (int i = 0; i < K1; i++) {
      if (cl == -1 || dist[V1[i]] < dist[cl]) {
        cl = V1[i];
      }
    }

    cout << "A " << cl + 1 << endl;

    int v1;
    cin >> v1;
    v1--;

    bool found = false;
    for (int u : V2) {
      if (u == v1) {
        found = true;
      }
    }

    if (found) {
      cout << "C " << cl + 1 << endl;
    } else {
      cout << "C " << -1 << endl;
    }
  }
  return 0;
}