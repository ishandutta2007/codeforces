#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Segment_tree {
  struct Node {
    ll ans;
    int len, left, right;

    Node(ll ans = 0, int len = 0, int left = 0, int right = 0) : ans(ans), len(len), left(left), right(right) {}

    inline ll sqr(int x) {
      return 1ll * x * x;
    }

    Node operator + (Node n) {
      Node res = Node();
      res.len = len + n.len;
      res.ans = ans + n.ans - sqr((right + 1) / 2) - sqr((n.left + 1) / 2) + sqr((right + n.left + 1) / 2);
      res.left = left + (len == left) * n.left;
      res.right = n.right + (n.len == n.right) * right;
      return res;
    }
  };

  int n;
  vector<Node> tree;

  inline void resize(int n_) {
    n = n_;
    tree.assign(4 * n, Node());
    build(0, 0, n);
  }

  void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
      tree[v] = Node(1, 1, 1, 1);
      return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v + 1, vl, vm);
    build(2 * v + 2, vm, vr);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
  }

  inline void decrease(int pos) {
    decrease(0, 0, n, pos);
  }

  void decrease(int v, int vl, int vr, int pos) {
    if (pos < vl || vr <= pos) {
      return;
    }
    if (vr - vl == 1) {
      if (tree[v].ans == 1) {
        tree[v] = Node(0, 1, 0, 0);
      }
      return;
    }
    int vm = (vl + vr) / 2;
    decrease(2 * v + 1, vl, vm, pos);
    decrease(2 * v + 2, vm, vr, pos);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
  }

  inline ll get() {
    return tree[0].ans;
  }
};

array<vector<int>, 3> suffix_array(string s) { // returns:
  s.push_back(0);                              // 0: suffix array
  int n = s.size();                            // 1: the position of of each suffix in the suffix array
  vector<int> suf, num;                        // 2: longest common prefix of suffix[i] ans suffix[i - 1]
  suf.assign(n, 0);
  iota(suf.begin(), suf.end(), 0);
  sort(suf.begin(), suf.end(), [&](int &i, int &j) {
    return s[i] < s[j];
  });
  num.assign(n, 0);
  for (int i = 1; i < n; i++) {
    num[suf[i]] = num[suf[i - 1]] + (s[suf[i]] != s[suf[i - 1]]);
  }
  for (int k = 0; (1 << k) < n && num[suf.back()] < n - 1; k++) {
    vector<vector<int>> count;
    count.assign(num[suf.back()] + 1, vector<int>());
    for (auto &el : suf) {
      el = (el - (1 << k) + n) % n;
      count[num[el]].push_back(el);
    }
    suf.clear();
    for (auto &el : count) {
      for (auto &ell : el) {
        suf.push_back(ell);
      }
    }
    vector<int> new_num;
    new_num.assign(n, 0);
    for (int i = 1; i < n; i++) {
      pair<int, int> was = {num[suf[i - 1]], num[(suf[i - 1] + (1 << k)) % n]};
      pair<int, int> now = {num[suf[i]], num[(suf[i] + (1 << k)) % n]};
      new_num[suf[i]] = new_num[suf[i - 1]] + (was != now);
    }
    num = new_num;
  }
  vector<int> lcp;
  lcp.assign(n, 0);
  for (int i = 0, already = 0; i < n - 1; i++, already = max(already - 1, 0)) {
    int j = suf[num[i] - 1];
    while (s[i + already] == s[j + already]) {
      already++;
    }
    lcp[num[i]] = already;
  }
  return {suf, num, lcp};
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    auto [suf, num, lcp] = suffix_array(s);
    vector<vector<int>> events;
    events.assign(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
      events[lcp[i]].push_back(1 + (i - 2) * 2);
    }
    Segment_tree tree;
    tree.resize(2 * n - 1);
    ll ans = 0;
    for (int len = 0; len <= n; len++) {
      ans += (len > 0) * tree.get();
      for (auto &pos : events[len]) {
        tree.decrease(pos);
      }
      if (len > 0) {
        tree.decrease((num[n - len] - 1) * 2);
      }
    }
    cout << ans << '\n';
  }
}