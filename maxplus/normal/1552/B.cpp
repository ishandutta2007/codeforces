#include <functional>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

constexpr int N = 5e4, M = 5;
int r[M][N], s[M][N], ok[N];
map<int, int, greater<int>> cm;

bool add_to_cm(int x, int y) {
  auto it = cm.upper_bound(x);
  if (it != cm.end() && it->second < y) {
    return 0;
  }
  it = cm.emplace_hint(it, x, y);
  while (it != cm.begin()) {
    --it;
    if (it->second > y) {
      it = cm.erase(it);
    } else {
      break;
    }
  }
  return 1;
}

int main()
{
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> r[j][i];
      }
      ok[i] = 1;
    }
    for (int j = 0; j < M; ++j) {
      for (int i = 0; i < n; ++i) {
        s[j][i] = i;
      }
      sort(s[j], s[j] + n, [&key = r[j]](int a, int b) { return key[a] < key[b]; });
    }
    for (int m0 =      0; m0 < M; ++m0)
    for (int m1 = m0 + 1; m1 < M; ++m1)
    for (int m2 = m1 + 1; m2 < M; ++m2) {
      cm.clear();
      for (int i = 0; i < n; ++i) {
        int j = s[m0][i];
        ok[j] &= add_to_cm(r[m1][j], r[m2][j]);
      }
    }
    int winner = find(ok, ok + n, 1) - ok;
    cout << (winner + 2) % (n + 2) - 1 << '\n';
  }
  return 0;
}