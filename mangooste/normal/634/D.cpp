#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Segment_tree {
  int n;
  vector<pair<int, int>> tree;

  void unite(int n_) {
    n = n_;
    tree.assign(4 * n, make_pair(1e9, -1));
  }

  void update(int pos, int new_val) {
    update(0, 0, n, pos, new_val);
  }

  void update(int v, int vl, int vr, int pos, int new_val) {
    if (pos < vl || vr <= pos) {
      return;
    }
    if (vr - vl == 1) {
      tree[v] = make_pair(new_val, vl);
      return;
    }
    int vm = (vl + vr) / 2;
    update(2 * v + 1, vl, vm, pos, new_val);
    update(2 * v + 2, vm, vr, pos, new_val);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
  }

  int find_less(int pos, int val) {
    return find_less(0, 0, n, pos, val);
  }

  int find_less(int v, int vl, int vr, int pos, int val) {
    if (tree[v].first > val || pos >= vr) {
      return -1;
    }
    if (vr - vl == 1) {
      return vl;
    }
    int vm = (vl + vr) / 2;
    int ans = find_less(2 * v + 1, vl, vm, pos, val);
    if (ans == -1) {
      ans = find_less(2 * v + 2, vm, vr, pos, val);
    }
    return ans;
  }

  int get_min(int L, int R) {
    return get_min(0, 0, n, L, R).second;
  }

  pair<int, int> get_min(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L) {
      return make_pair(1e9, -1);
    }
    if (L <= vl && vr <= R) {
      return tree[v];
    }
    int vm = (vl + vr) / 2;
    return min(get_min(2 * v + 1, vl, vm, L, R), get_min(2 * v + 2, vm, vr, L, R));
  }
};

int d, n, m;
map<int, int> mapa;
vector<pair<int, int>> opt;
Segment_tree tree;
int cur, pos = 0, opt_pos = 0;
ll ans = 0;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> d >> n >> m;
  mapa[0] = 0;
  for (int i = 0; i < m; i++) {
    int x, cost;
    cin >> x >> cost;
    if (mapa.find(x) == mapa.end()) {
      mapa[x] = cost;
    } else {
      mapa[x] = min(mapa[x], cost);
    }
  }
  for (auto el : mapa) {
    opt.push_back(el);
  }
  tree.unite(opt.size());
  for (int i = 0; i < opt.size(); i++) {
    tree.update(i, opt[i].second);
  }
  cur = n;
  while (pos < d) {
    int cur_cost = mapa[pos];
    int less = tree.find_less(opt_pos + 1, cur_cost);
    int R = lower_bound(opt.begin(), opt.end(), make_pair(pos + n, (int)1e9)) - opt.begin() - 1;
    if (less == -1 && R == opt_pos) {
      if (d - pos > n) {
        ans = -1;
      } else {
        ans += 1ll * max(0, d - pos - cur) * cur_cost;
      }
      break;
    }
    if (less == -1 && d - pos <= n) {
      ans += 1ll * max(0, d - pos - cur) * cur_cost;
      break;
    }
    if (less != -1 && opt[less].first - pos <= n) {
      int to = opt[less].first;
      ans += 1ll * max(0, to - pos - cur) * cur_cost;
      cur += max(0, to - pos - cur);
      cur -= to - pos;
      opt_pos = less;
      pos = to;
    } else {
      if (R == opt_pos) {
        ans = -1;
        break;
      }
      int to = tree.get_min(opt_pos + 1, R + 1);
      assert(to != -1);
      ans += 1ll * (n - cur) * cur_cost;
      cur = n;
      opt_pos = to;
      cur -= opt[to].first - pos;
      pos = opt[to].first;
    }
  }
  cout << ans << '\n';
}