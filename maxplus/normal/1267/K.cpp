#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int A = 21;

int cnk[A][A];

int64_t solve(string ms) {
  int counts[A]{};
  for (int i = 0; i < ms.size(); ++i) {
    ++counts[ms[i]];
  }
  int64_t ans1 = 1;
  for (int i = ms.size() + 1, am = 0, pos = 0; pos += i != 1, i--; ) if (counts[i]) {
    ans1 *= cnk[pos][counts[i]];
    pos -= counts[i];
  }
  int64_t ans2 = !!counts[0]--;
  for (int i = ms.size() + 1, am = 0, pos = -1; pos += i != 1, i-- && ans2; ) if (counts[i]) {
    ans2 *= cnk[pos][counts[i]];
    pos -= counts[i];
  }
  return ans1 - ans2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int n = 0; n < A; ++n) {
    cnk[n][0] = 1;
    for (int k = 1; k <= n; ++k) {
      cnk[n][k] = cnk[n - 1][k] + cnk[n - 1][k - 1];
    }
  }
  for (int t = (cin >> t, t); t--; ) {
    int64_t k, cur = 2; cin >> k;
    string ms;
    while (k) {
      ms += k % cur, k /= cur++;
    }
    sort(ms.begin(), ms.end());
    cout << solve(ms) - 1 << '\n';
  }
}