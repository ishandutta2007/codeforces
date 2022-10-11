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

string s;
int n, m;
vector<int> allowed, cnt;
vector<vector<int>> suf;

void Main() {
  cin >> s >> m;
  n = (int)s.size();
  allowed.assign(n, (1 << 6) - 1);
  for (int i = 0; i < m; i++) {
    int pos;
    string can;
    cin >> pos >> can;
    pos--;
    allowed[pos] = 0;
    for (auto el : can) {
      allowed[pos] += (1 << (el - 'a'));
    }
  }
  cnt.assign(6, 0);
  for (auto el : s) {
    cnt[el - 'a']++;
  }
  suf.resize(n + 1, vector<int>((1 << 6), 0));
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1];
    for (int mask = 1; mask < (1 << 6); mask++) {
      if (allowed[i] & mask) {
        suf[i][mask]++;
      }
    }
  }
  bool ok = true;
  string ans = "";
  for (int i = 0; i < n; i++) {
    bool any = false;
    for (int cur = 0; cur < 6; cur++) {
      if ((allowed[i] & (1 << cur)) && cnt[cur] > 0) {
        cnt[cur]--;
        bool all_right = true;
        for (int mask = 1; mask < (1 << 6); mask++) {
          bool skip = false;
          for (int j = 0; j < 6; j++) {
            if (((mask >> j) & 1) && cnt[j] == 0) {
              skip = true;
              break;
            }
          }
          if (skip) {
            continue;
          }
          int suf_cnt = suf[i + 1][mask];
          int need_cnt = 0;
          for (int j = 0; j < 6; j++) {
            if (mask & (1 << j)) {
              need_cnt += cnt[j];
            }
          }
          if (suf_cnt < need_cnt) {
            all_right = false;
            break;
          }
        }
        if (all_right) {
          ans.push_back('a' + cur);
          any = true;
          break;
        }
        cnt[cur]++;
      }
    }
    if (!any) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << "Impossible\n";
  } else {
    cout << ans << '\n';
  }
}