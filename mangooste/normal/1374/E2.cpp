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

// #include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m, k;
vector<array<int, 3>> a;
vector<vector<vector<pair<int, int>>>> want(2, vector<vector<pair<int, int>>>(2));
vector<vector<vector<ll>>> pref(2, vector<vector<ll>>(2));
ordered_set<pair<int, int>> st;
ll sum_need = 0;
int cnt_need = 0;

inline void add(pair<int, int> el) {
  if ((int)st.size() < cnt_need) {
    sum_need += el.first;
  } else if (cnt_need != 0) {
    auto it = st.find_by_order(cnt_need - 1);
    if (el <= *it) {
      sum_need -= it->first;
      sum_need += el.first;
    }
  }
  st.insert(el);
}

inline void my_erase(pair<int, int> el) {
  if (st.find(el) == st.end()) {
    return;
  }
  if ((int)st.size() <= cnt_need) {
    sum_need -= el.first;
  } else if (cnt_need != 0) {
    auto it = st.find_by_order(cnt_need - 1);
    if (el <= *it) {
      sum_need -= el.first;
      if ((int)st.size() > cnt_need) {
        sum_need += st.find_by_order(cnt_need)->first;
      }
    }
  }
  st.erase(el);
}

inline void sub(int to_cnt) {
  if (to_cnt == 0) {
    cnt_need = 0;
    sum_need = 0;
    return;
  }
  while (cnt_need > to_cnt) {
    cnt_need--;
    if ((int)st.size() > cnt_need) {
      sum_need -= st.find_by_order(cnt_need)->first;
    }
  }
  while (cnt_need < to_cnt) {
    if ((int)st.size() > cnt_need) {
      sum_need += st.find_by_order(cnt_need)->first;
    }
    cnt_need++;
  }
}

void Main() {
  cin >> n >> m >> k;
  a.resize(n);
  for (auto &el : a) {
    cin >> el[0] >> el[1] >> el[2];
  }
  for (int i = 0; i < n; i++) {
    want[a[i][1]][a[i][2]].emplace_back(a[i][0], i);
  }
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      sort(want[a][b].begin(), want[a][b].end());
      pref[a][b].push_back(0);
      for (int i = 0; i < (int)want[a][b].size(); i++) {
        pref[a][b].push_back(pref[a][b].back() + want[a][b][i].first);
      }
    }
  }
  cnt_need = max(0, m - 2 * k);
  for (auto el : want[0][0]) {
    add(el);
  }
  for (int i = k; i < (int)want[1][0].size(); i++) {
    add(want[1][0][i]);
  }
  for (int i = k; i < (int)want[0][1].size(); i++) {
    add(want[0][1][i]);
  }
  for (auto el : want[1][1]) {
    add(el);
  }
  ll ans = 1e18;
  int where_ans = -1;
  for (int mid = 0; mid <= (int)want[1][1].size() && mid <= m; mid++) {
    int need = max(0, k - mid);
    if ((int)st.size() + mid + 2 * need >= m && (int)want[1][0].size() >= need && (int)want[0][1].size() >= need) {
      ll cur_ans = pref[1][1][mid] + pref[1][0][need] + pref[0][1][need];
      int cur_cnt = mid + 2 * need;
      if (cur_cnt <= m) {
        sub(m - cur_cnt);
        cur_ans += sum_need;
        if (ans > cur_ans) {
          ans = cur_ans;
          where_ans = mid;
        }
      }
    }
    if (need != 0) {
      if (need - 1 < (int)want[1][0].size()) {
        add(want[1][0][need - 1]);
      }
      if (need - 1 < (int)want[0][1].size()) {
        add(want[0][1][need - 1]);
      }
    }
    if (mid != (int)want[1][1].size()) {
      my_erase(want[1][1][mid]);
    }
  }
  if (where_ans == -1) {
    cout << "-1\n";
    return;
  }
  vector<int> inds;
  for (int i = 0; i < where_ans; i++) {
    inds.push_back(want[1][1][i].second);
  }
  int need = max(0, k - where_ans);
  for (int i = 0; i < need; i++) {
    inds.push_back(want[1][0][i].second);
    inds.push_back(want[0][1][i].second);
  }
  vector<pair<int, int>> other;
  for (int i = where_ans; i < (int)want[1][1].size(); i++) {
    other.push_back(want[1][1][i]);
  }
  for (int i = need; i < (int)want[1][0].size(); i++) {
    other.push_back(want[1][0][i]);
  }
  for (int i = need; i < (int)want[0][1].size(); i++) {
    other.push_back(want[0][1][i]);
  }
  for (auto el : want[0][0]) {
    other.push_back(el);
  }
  sort(other.begin(), other.end());
  for (int i = 0; i < m - 2 * need - where_ans; i++) {
    inds.push_back(other[i].second);
  }
  cout << ans << '\n';
  sort(inds.begin(), inds.end());
  for (auto el : inds) {
    cout << el + 1 << ' ';
  }
  cout << '\n';
}