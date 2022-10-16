#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int N = 1e5;
bool holes[N];

void check(bool cond) {
  if (!cond) {
    cout << -1;
    exit(0);
  }
}

int main() {
  string m; cin >> m;
//  reverse(m.begin(), m.end());
  int n = m.size();
  if (m.substr(1) == m.substr(0, n - 1)) {
    if (m[0] == '_') {
      cout << 0;
    } else {
      cout << "1 " << n;
    }
    return 0;
  }
  for (int i = 0, last = -2; i <= n; ++i) {
    if (i == n || m[i] == '#' && last != i - 1) {
      holes[i + (i == n) - last - 2] = 1;
    }
    if (i != n && m[i] == '#') {
      last = i;
    }
  }
  int f = 0;
  while (!holes[f]) {
    ++f;
  }
  if (holes[f + 1]) {
    f -= 2;
  }
//  f = min(f, 2);
  check(f >= 0);
  if (f <= 1) {
    bool ok = 1;
    for (int i = f + 1; i < N; i += f + 1) {
      ok &= !holes[i];
    }
    check(ok);
  }
  auto s = m.c_str();
  for (int i = m.rfind('#'), last = 3e5; i >= 0; --i) {
    if (m[i] == '#') {
      last = i;
    } else if (last - i <= f || (i == 0 || m[i - 1] != '#') && ((last - i - f) % 2 == 0 || i == 0 || i == n - 1 || i != 1 && m[i - 2] == '#')) {
      m[i] = '#';
    }
  }
  vector<int> ans;
  for (int i = 0; i < n && m[i] == '#'; ++i) {
    int j = i;
    while (m[j] == '#') {
      ++j;
    }
    ans.push_back(j - i);
    i = j;
  }
  {
    int lft = n - 1 - m.rfind('#') - f;
    while (lft) {
      if (lft == 3) {
        ans.push_back(2);
        lft -= 3;
      } else {
        ans.push_back(1);
        lft -= 2;
      }
    }
  }
  check(accumulate(ans.begin(), ans.end(), ans.size()) - 1 == n - f);
  cout << ans.size() << '\n';
  for (auto i: ans) {
    cout << i << ' ';
  }
}