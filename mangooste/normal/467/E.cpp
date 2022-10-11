#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Segment_tree {
  int n;
  vector<int> tree;

  void unite(int n_) {
    n = n_;
    tree.assign(4 * n, n);
  }

  void update(int pos, int new_value) {
    update(0, 0, n, pos, new_value);
  }

  void update(int v, int vl, int vr, int pos, int new_value) {
    if (pos < vl || vr <= pos) {
      return;
    }
    if (vr - vl == 1) {
      tree[v] = new_value;
      return;
    }
    int vm = (vl + vr) / 2;
    update(2 * v + 1, vl, vm, pos, new_value);
    update(2 * v + 2, vm, vr, pos, new_value);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
  }

  int get(int L, int R) {
    return get(0, 0, n, L, R);
  }

  int get(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L) {
      return n;
    }
    if (L <= vl && vr <= R) {
      return tree[v];
    }
    int vm = (vl + vr) / 2;
    return min(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
  }
};

int n, timer = 0;
map<int, int> back;
vector<int> a, ans, used;
vector<vector<int>> poses;
Segment_tree tree;

inline void compress() {
  vector<int> values = a;
  sort(values.begin(), values.end());
  values.resize(unique(values.begin(), values.end()) - values.begin());
  for (auto &el : a) {
    el = lower_bound(values.begin(), values.end(), el) - values.begin();
    back[el] = values[el];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.assign(n, 0);
  for (auto &el : a) {
    cin >> el;
  }
  compress();
  used.assign(n, -1);
  poses.assign(n, vector<int>());
  tree.unite(n);
  for (int i = 0; i < n; i++) {
    if (used[a[i]] != timer) {
      used[a[i]] = timer;
      poses[a[i]] = {i};
    } else {
      poses[a[i]].push_back(i);
      if (poses[a[i]].size() > 3) {
        for (int j = 0; j < 4; j++) {
          ans.push_back(a[i]);
        }
        timer++;
      } else {
        for (int j = 0; j < poses[a[i]].size() - 1; j++) {
          int mn = tree.get(poses[a[i]][j] + 1, i);
          if (mn < poses[a[i]][j]) {
            int pos = poses[a[i]][j] + 1;
            while (poses[a[pos]].empty() || poses[a[pos]][0] >= poses[a[i]][j]) {
              pos++;
            }
            ans.push_back(a[pos]);
            ans.push_back(a[i]);
            ans.push_back(a[pos]);
            ans.push_back(a[i]);
            timer++;
            break;
          }
        }
        tree.update(i, poses[a[i]][0]);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto &el : ans) {
    cout << back[el] << ' ';
  }
}