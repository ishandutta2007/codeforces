#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int N = 2e3;
int nxt[N];
bool connected[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t); t--; ) {
    vector<array<int, 2>> edges;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
      nxt[i] = i + 1;
      cin.get();
      for (int j = i; j < n; ++j) {
        connected[i][j] = cin.get() == '1';
      }
    }
    for (int l = n; l--; )
    for (int r = l; ++r < n;) if (connected[l][r] && nxt[l] <= r) {
      edges.push_back({l, r});
      if (nxt[nxt[l]] <= r) {
        edges.push_back({nxt[l], r});
        for (int i = nxt[nxt[l]]; nxt[i] <= r; i = nxt[i])  {
          edges.push_back({l, i});
        }
      }
      for (int i = l; i < r; ++i) {
        nxt[i] = nxt[r];
      }
    }
    for (auto [l, r]: edges) {
      cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }
}