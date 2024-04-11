#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 3e5, M = 1e6, max_size = 1 << 21;

int t[max_size], inc[max_size];

struct STOperation {
  int mod, l, r;

  int call(int i = 0, int L = 0, int R = M) {
    int dummy = 1e9, &maybe = !mod? dummy: t[i];
    if (R <= l || r <= L) {
      return maybe + inc[i];
    } else if (l <= L && R <= r) {
      inc[i] += mod;
      return t[i] + inc[i];
    }
    return (maybe = min(call(2 * i + 1, L, (L + R) / 2), call(2 * i + 2, (L + R) / 2, R))) + inc[i];
  }
};

pair<int, pair<int, int>> s[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i].second.first >> s[i].second.second >> s[i].first, --s[i].second.first, --s[i].second.second;
  }
  sort(s, s + n);
  int l = 0, r = 0, ans = 1e9;
  while (1) {
    if (STOperation{0, 0, m - 1}.call()) {
      ans = min(ans, s[r - 1].first - s[l].first);
      STOperation{-1, s[l].second.first, s[l].second.second}.call();
      ++l;
    } else if (r == n) {
      break;
    } else {
      STOperation{1, s[r].second.first, s[r].second.second}.call();
      ++r;
    }
  }
  cout << ans << '\n';
  return 0;
}