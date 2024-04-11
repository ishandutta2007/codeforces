#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, half;
vector<vector<int>> G;
int cur_num = 0;
map<string, int> num;
vector<string> cur;
vector<char> is;
vector<int> dp, ok;
int ans = 0;

inline int get_num(string &s) {
  if (num.find(s) == num.end()) {
    num[s] = cur_num++;
  }
  assert(cur_num <= m);
  return num[s];
}

void make_graph() {
  vector<int> nums;
  for (auto &el : cur) {
    nums.push_back(get_num(el));
  }
  sort(nums.begin(), nums.end());
  nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      G[nums[i]].push_back(nums[j]);
      G[nums[j]].push_back(nums[i]);
    }
  }
  cur.clear();
}

void calc_is(int left) {
  is.assign(1 << left, 0);
  is[0] = 1;
  for (int mask = 1; mask < (1 << left); mask++) {
    int one = -1;
    vector<int> in(left, 0);
    for (int i = 0; i < left; i++) {
      if (mask & (1 << i)) {
        in[i] = 1;
        one = i;
      }
    }
    assert(one != -1);
    if (!is[mask - (1 << one)]) {
      continue;
    }
    is[mask] = 1;
    for (auto u : G[one]) {
      if (u < left && in[u]) {
        is[mask] = 0;
        break;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  G.resize(m);
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      make_graph();
    } else {
      string s;
      cin >> s;
      cur.push_back(s);
    }
  }
  make_graph();
  for (auto &el : G) {
    sort(el.begin(), el.end());
    el.resize(unique(el.begin(), el.end()) - el.begin());
  }
  half = m / 2;
  calc_is(half);
  dp.assign(1 << half, 0);
  dp[0] = 0;
  for (int mask = 1; mask < (1 << half); mask++) {
    if (is[mask]) {
      dp[mask] = __builtin_popcount(mask);
      continue;
    }
    for (int i = 0; i < half; i++) {
      if (mask & (1 << i)) {
        dp[mask] = max(dp[mask], dp[mask - (1 << i)]);
      }
    }
  }
  reverse(G.begin(), G.end());
  for (auto &el : G) {
    for (auto &ell : el) {
      ell = m - 1 - ell;
    }
  }
  calc_is(m - half);
  ok.assign(1 << (m - half), 0);
  ok[0] = (1 << half) - 1;
  for (int mask = 1; mask < (1 << (m - half)); mask++) {
    int one = -1;
    for (int i = 0; i < m - half; i++) {
      if (mask & (1 << i)) {
        one = i;
      }
    }
    assert(one != -1);
    ok[mask] = ok[mask - (1 << one)];
    for (auto j : G[one]) {
      int jj = m - 1 - j;
      if (jj < half && (ok[mask] & (1 << jj))) {
        ok[mask] -= (1 << jj);
      }
    }
  }
  for (int mask = 0; mask < (1 << (m - half)); mask++) {
    if (is[mask]) {
      ans = max(ans, dp[ok[mask]] + __builtin_popcount(mask));
    }
  }
  cout << ans << '\n';
}