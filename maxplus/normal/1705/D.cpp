#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int q = (cin >> q, q); q--; ) {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i = n--; --i; ) {
      s[i] ^= s[i - 1] ^ i & 1;
      t[i] ^= t[i - 1] ^ i & 1;
    }
    int64_t ans = -(s[0] ^ t[0]);
    s.erase(s.begin()), t.erase(t.begin());
    for (int l = 0, r = 0; l < n && ans != -1; ++l) if (s[l] != t[l]) {
      r = max(r, l);
      while (r < n - 1 && s[r] != s[r + 1]) ++r;
      if (r == n - 1) {
        ans = -1;
        break;
      }
      s[++r] ^= 1;
      ans += r - l;
    }
    cout << ans << '\n';
  }
}