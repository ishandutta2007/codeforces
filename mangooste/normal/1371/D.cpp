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

int sqr(int x) {
  return x * x;
}

void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
      if (k == 1) {
        cout << "0\n1\n";
      } else {
        cout << "0\n0\n";
      }
      continue;
    }
    if (k == 0) {
      cout << "0\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << '0';
        }
        cout << '\n';
      }
      cout << '\n';
      continue;
    }
    int ans = 1e9;
    int where = -1;
    for (int cnt = 0; cnt <= n && cnt <= k; cnt++) {
      if ((n - 1) * n >= k - cnt) {
        int ost = k - cnt;
        vector<int> vals;
        for (int i = 0; i < n - 1; i++) {
          vals.push_back(ost / (n - 1));
        }
        for (int i = 1; i <= ost % (n - 1); i++) {
          vals[i]++;
        }
        int cur_ans = 0;
        cur_ans += sqr(max(cnt, *max_element(vals.begin(), vals.end())) - min(cnt, *min_element(vals.begin(), vals.end())));
        vals.clear();
        vals.assign(n, 0);
        for (int i = 0; i < cnt; i++) {
          vals[i] = 1;
        }
        for (int i = 0; i < n; i++) {
          vals[i] += ost / n;
        }
        for (int i = 0; i < ost % n; i++) {
          vals[n - 1 - i]++;
        }
        cur_ans += sqr(*max_element(vals.begin(), vals.end()) - *min_element(vals.begin(), vals.end()));
        // cout << "cnt = " << cnt << " cur_ans = " << cur_ans << '\n';
        if (ans > cur_ans) {
          ans = cur_ans;
          where = cnt;
        }
      }
    }
    assert(where != -1);
    vector<string> a(n, string(n, '0'));
    for (int i = 0; i < where; i++) {
      a[i][0] = '1';
    }
    int ost = k - where;
    vector<int> need(n, 0);
    for (int i = 1; i < n; i++) {
      need[i] += ost / (n - 1);
    }
    for (int i = 1; i <= ost % (n - 1); i++) {
      need[i]++;
    }
    vector<int> vals(n, 0);
    for (int i = 0; i < n; i++) {
      vals[i] += ost / n;
    }
    for (int i = 0; i < ost % n; i++) {
      vals[n - 1 - i]++;
    }
    assert(accumulate(need.begin(), need.end(), 0) == accumulate(vals.begin(), vals.end(), 0));
    for (int i = 0; i < n; i++) {
      vector<int> inds(n - 1);
      iota(inds.begin(), inds.end(), 1);
      sort(inds.begin(), inds.end(), [&](int &pos1, int &pos2) {
        return n - i - need[pos1] < n - i - need[pos2];
      });
      for (int j = 0; j < vals[i]; j++) {
        need[inds[j]]--;
        a[i][inds[j]] = '1';
      }
    }
    assert(*max_element(need.begin(), need.end()) == 0);
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << '\n';
    }
  }
}