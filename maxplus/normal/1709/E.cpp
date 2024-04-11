#include <iostream>
#include <vector>
#include <set>

using namespace std;

constexpr int N = 2e5;
vector<int> nei[N];
int a[N];
int ans;

pair<set<int>, int> solve(int v, int p) {
  set<int> res{0};
  int tx = 0;
  bool bad = 0;
  for (auto u: nei[v]) if (u != p) {
    auto [tmp, utx] = solve(u, v);
    if (tmp.size() > res.size()) {
      swap(tmp, res);
      swap(utx, tx);
    }
    utx ^= tx;
    for (auto i: tmp) {
      bad |= res.count(i ^ utx ^ a[v]);
    }
    for (auto i: tmp) {
      res.insert(i ^ utx);
    }
  }
  if (bad) {
    res.clear();
    ++ans;
  }
  return {move(res), tx ^ a[v]};
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    int v, u; cin >> v >> u, --v, --u;
    nei[v].push_back(u);
    nei[u].push_back(v);
  }
  solve(0, 0);
  cout << ans << '\n';
}