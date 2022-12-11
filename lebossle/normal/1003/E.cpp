#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

int n, d, k;
vector<vector<int>> g;
int nextId;

void addEdge(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

void buildSubtree(int root, int maxDepth, int deg) {
  if (maxDepth == 0)
    return;
  for (int i=0; i<k-deg; ++i) {
    if (nextId == n)
      return;
    int cur = nextId; nextId++;
    addEdge(cur, root);
    buildSubtree(cur, maxDepth-1, 1);
  }
}

int main() {
  cin >> n >> d >> k;
  if (n <= d || k == 1 && n > 2) {
    cout << "NO" << endl;
    return 0;
  }
  g.resize(n);
  for (int i=1; i<=d; ++i)
    addEdge(i-1, i);
  nextId=d+1;
  for (int i=1; i <= d-i; ++i) {
    buildSubtree(i, i, 2);
    if (i != d-i)
      buildSubtree(d-i, i, 2);
  }
  LOG(nextId);
  LOG(g);
  if (nextId != n) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i=0; i<n; ++i)
    for (int j : g[i])
      if (i < j)
        cout << i+1 << ' ' << j+1 << '\n';
}