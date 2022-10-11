#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<char> used(3 * n, 0);
    for (int i = 0; i < m; i++) {
      int v, u;
      cin >> v >> u;
      v--, u--;
      edges.emplace_back(u, v);
    }
    vector<int> matching;
    for (int i = 0; i < m; i++) {
      auto [u, v] = edges[i];
      if (!used[u] && !used[v]) {
        used[u] = used[v] = 1;
        matching.push_back(i + 1);
      }
    }
    if ((int)matching.size() >= n) {
      cout << "Matching\n";
      for (int i = 0; i < n; i++) {
        cout << matching[i] << ' ';
      }
      cout << '\n';
    } else {
      cout << "IndSet\n";
      vector<int> vers;
      for (int i = 0; i < 3 * n; i++) {
        if (!used[i]) {
          vers.push_back(i + 1);
        }
      }
      assert((int)vers.size() >= n);
      for (int i = 0; i < n; i++) {
        cout << vers[i] << ' ';
      }
      cout << '\n';
    }
  }
}