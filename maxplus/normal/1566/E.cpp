#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 2e5;

vector<int> nei[N];

pair<int, int> calc_leaves(int p, int v) {
  int res = 0;
  int dv = 0;
  for (auto u: nei[v]) if (u != p) {
    auto [leaves, du] = calc_leaves(v, u);
    if (du == 1) {
      --leaves;
    } else {
      dv = max(dv, du + 1);
    }
    res += leaves;
  }
  nei[v].clear();
  return {res + !dv, dv};
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
      cin >> u >> v;
      nei[--u].push_back(--v);
      nei[v].push_back(u);
    }
    cout << calc_leaves(0, 0).first << '\n';
  }
  return 0;
}