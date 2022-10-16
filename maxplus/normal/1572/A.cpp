#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 2e5;
vector<int> req[N];
int used[N], t[N];

void rereads(int v) {
  used[v] = 1;
  t[v] = 1;
  for (auto u: req[v]) {
    if (used[u] == 1) {
      t[v] = N + 1;
    } else if (!used[u]) {
      rereads(u);
    }
    t[v] = max(t[v], t[u] + (u > v));
  }
  req[v].clear();
  used[v] = 2;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, k, r;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> k;
      while (k--) {
        cin >> r;
        req[i].push_back(r - 1);
      }
      used[i] = ::t[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) if (!used[i]) {
      rereads(i);
      ans = max(ans, ::t[i]);
    }
    cout << (ans > N? -1: ans) << '\n';
  }
  return 0;
}