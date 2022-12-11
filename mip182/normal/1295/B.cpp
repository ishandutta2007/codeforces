#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  string s(n, '1');
  map<int, int> bal;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    if (s[i] == '1') {
      --cur;
    } else {
      ++cur;
    }
    ++bal[cur];
  }
  if (cur == 0) {
    if (bal[x]) {
      cout << -1;
    } else {
      cout << 0;
    }
    return;
  }
  long long ans = 0;
  if (x == 0) {
    ++ans;
  }
  for (auto [a, b] : bal) {
    if (abs(x - a) % abs(cur)) {
      continue;
    }
    if ((x - a) / cur < 0) {
      continue;
    }
    ans += b;
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}