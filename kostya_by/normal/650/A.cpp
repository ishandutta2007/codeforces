#include <bits/stdc++.h>

using namespace std;

map<int, int> counters_x;
map<int, int> counters_y;
map<pair<int, int>, int> counters_x_y;

void solve() {
  int n; scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int x, y; scanf("%d%d", &x, &y);
    counters_x[x] += 1;
    counters_y[y] += 1;
    counters_x_y[make_pair(x, y)] += 1;
  }

  long long answer = 0ll;
  for (auto p : counters_x) {
    answer += p.second * 1ll * (p.second - 1) / 2;
  }
  for (auto p : counters_y) {
    answer += p.second * 1ll * (p.second - 1) / 2;
  }
  for (auto p : counters_x_y) {
    answer -= p.second * 1ll * (p.second - 1) / 2;
  }

  cout << answer << "\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}