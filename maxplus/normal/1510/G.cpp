#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 100;

vector<int> ch[N];
int d[N];

int calcd(int v) {
  int d = 0;
  for (auto u: ch[v]) {
    d = max(d, calcd(u));
  }
  return ::d[v] = d + 1;
}

void printpath(int v, int& k, int maxop) {
  cout << v + 1 << ' ';
  --k;
  if (!k || ch[v].empty()) {
    return;
  }
  sort(ch[v].begin(), ch[v].end(), [](int a, int b) { return ::d[a] < ::d[b]; });
  for (auto u: ch[v]) {
    auto tmp = u == ch[v].back()? maxop: max(maxop, d[v] - 1);
    if (d[u] >= k || tmp < k) {
      printpath(u, k, tmp);
      if (k) {
        cout << v + 1 << ' ';
      } else {
        return;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t); t--; ) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      ch[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int p; cin >> p;
      ch[--p].push_back(i);
    }
    calcd(0);
    cout << max(k - 1, 2 * (k - 1) - d[0] + 1) << '\n';
    printpath(0, k, 0);
    cout << '\n';
  }
}