#include <iostream>
#include <vector>
#include <numeric>
#include <memory.h>

using namespace std;

constexpr int N = 2000, max_power = 1e9 + 1;

int pwr, a[N], b[N];
int p[N];
bool sc[N];
vector<int> nei[N];

int sum_pwr(int pwr, int v) {
  return min(max_power, pwr + b[v]);
}

void augment(int v) {
  while (!sc[v]) {
    sc[v] = 1;
    pwr = sum_pwr(pwr, v);
    v = p[v];
  }
}

bool dfs(int v, int pwr) {
  for (auto nxt: nei[v]) if (nxt != p[v] && a[nxt] < pwr) {
    if (sc[nxt]? !sc[v]: p[nxt] != -1) {
      augment(nxt);
      augment(v);
      return 1;
    } else if (!sc[nxt]) {
      p[nxt] = v;
      if (dfs(nxt, sum_pwr(pwr, nxt))) {
        return 1;
      }
    }
  }
  return 0;
}

int main()
{
  int t, n, m, v0, v1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      nei[i].clear();
    }
    for (auto arr: {a, b}) {
      for (int i = 1; i < n; ++i) {
        cin >> arr[i];
      }
    }
    for (int i = 0; i < m; ++i) {
      cin >> v0 >> v1;
      nei[--v0].push_back(--v1);
      nei[v1].push_back(v0);
    }
    int l = 1, r = max_power, mid;
    while (r != l + 1) {
      mid = (l + r) / 2;
      pwr = mid;
      memset(sc, 0, sizeof sc);
      memset(p, -1, sizeof p);
      sc[0] = 1;
      bool ok = 1;
      while (ok) {
        ok = 0;
        for (int i = 0; i < n; ++i) if (sc[i]) {
          if (ok |= dfs(i, pwr)) {
            break;
          }
        }
        memset(p, -1, sizeof p);
      }
      (accumulate(sc, sc + n, 0) == n? r: l) = mid;
    }
    cout << r << '\n';
  }
  return 0;
}