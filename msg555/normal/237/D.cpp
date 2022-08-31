#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> ID(N);
  vector<pair<int, int> > E;
  cout << N - 1 << endl;
  for(int i = 0; i + 1 < N; i++) {
    int u, v; cin >> u >> v; u--; v--;
    ID[u] = ID[v] = i;
    E.push_back(make_pair(u, v));
    cout << 2 << ' ' << u + 1 << ' ' << v + 1 << endl;
  }
  for(int i = 0; i < E.size(); i++) {
    int u = E[i].first;
    int v = E[i].second;
    if(i != ID[u]) cout << i + 1 << ' ' << ID[u] + 1 << endl;
    if(i != ID[v]) cout << i + 1 << ' ' << ID[v] + 1 << endl;
  }
  return 0;
}