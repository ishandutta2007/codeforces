#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> b;
vector<string> ans;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  b.resize(n);
  for (auto &el : b) {
    cin >> el;
  }
  ans.assign(n, "");
  while (b[0] >= 9) {
    b[0] -= 9;
    ans[0].push_back('9');
  }
  if (b[0] != 0) {
    ans[0].push_back('0' + b[0]);
  }
  for (int i = 1; i < n; i++) {
    ans[i] = ans[i - 1];
    int j = 0;
    while (j < ans[i].size() && ans[i][j] == '9') {
      ans[i][j] = '0';
      j++;
    }
    if (j == ans[i].size()) {
      ans[i].push_back('0');
    }
    ans[i][j]++;
    if (accumulate(ans[i].begin(), ans[i].end(), 0) - '0' * ans[i].size() == b[i]) {
      continue;
    }
    bool any = false;
    for (int j = 0; j < ans[i].size() && !any; j++) {
      if (ans[i][j] == '9') {
        continue;
      }
      int suf_sum = 0;
      for (int k = j + 1; k < ans[i].size(); k++) {
        suf_sum += ans[i][k] - '0';
      }
      if (b[i] - suf_sum < ans[i][j] - '0' + 1) {
        continue;
      }
      int max_left = j * 9;
      if (max_left + 9 + suf_sum >= b[i]) {
        any = true;
        ans[i][j]++;
        b[i] -= suf_sum;
        b[i] -= ans[i][j] - '0';
        assert(b[i] >= 0);
        for (int k = 0; k < j; k++) {
          if (b[i] >= 9) {
            b[i] -= 9;
            ans[i][k] = '9';
          } else {
            ans[i][k] = '0' + b[i];
            b[i] = 0;
          }
        }
        ans[i][j] += b[i];
        assert(ans[i][j] <= '9');
        b[i] = 0;
      }
    }
    if (!any) {
      int len = ans[i].size() + 1;
      while (len * 9 < b[i]) {
        len++;
      }
      ans[i] = string(len, '0');
      ans[i].back() = '1';
      b[i]--;
      for (int j = 0; j < ans[i].size() - 1; j++) {
        if (b[i] >= 9) {
          b[i] -= 9;
          ans[i][j] = '9';
        } else {
          ans[i][j] = '0' + b[i];
          b[i] = 0;
        }
      }
      if (b[i] != 0) {
        ans[i].back() += b[i];
      }
    }
  }
  for (auto &el : ans) {
    reverse(el.begin(), el.end());
    cout << el << '\n';
  }
}