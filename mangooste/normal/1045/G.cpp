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

struct One {
  int x, r, iq;
  One(int x = 0, int r = 0, int iq = 228) :
    x(x), r(r), iq(iq)
  {}
};

struct Fenwik {
  int n;
  vector<int> bit;

  void unite(int n_) {
    n = n_;
    bit.assign(n + 1, 0);
  }

  int get(int pos) {
    int ans = 0;
    for (; pos > 0; pos -= pos & -pos) {
      ans += bit[pos];
    }
    return ans;
  }

  int get(int L, int R) {
    return get(R) - get(L);
  }

  void increase(int pos) {
    for (pos++; pos <= n; pos += pos & -pos) {
      bit[pos]++;
    }
  }
};

int n, k;
ll ans = 0;
vector<One> segs;
unordered_map<int, vector<int>> mapa;
unordered_map<int, Fenwik> bit;
vector<int> where;

void Main() {
  cin >> n >> k;
  segs.resize(n);
  for (auto &[x, r, iq] : segs) {
    cin >> x >> r >> iq;
  }
  sort(segs.begin(), segs.end(), [](One &a, One &b) {
    return a.r > b.r;
  });
  for (int i = 0; i < n; i++) {
    mapa[segs[i].iq].push_back(i);
  }
  where.assign(n, -1);
  for (auto &[iq, els] : mapa) {
    sort(els.begin(), els.end(), [&](int &i, int &j) {
      return segs[i].x < segs[j].x;
    });
    for (int i = 0; i < (int)els.size(); i++) {
      where[els[i]] = i;
      els[i] = segs[els[i]].x;
    }
    bit[iq].unite(els.size());
  }
  for (int i = 0; i < n; i++) {
    int L = segs[i].x - segs[i].r;
    int R = segs[i].x + segs[i].r;
    for (int iq = segs[i].iq - k; iq <= segs[i].iq + k; iq++) {
      if (bit.find(iq) == bit.end()) {
        continue;
      }
      int li = lower_bound(mapa[iq].begin(), mapa[iq].end(), L) - mapa[iq].begin();
      int ri = upper_bound(mapa[iq].begin(), mapa[iq].end(), R) - mapa[iq].begin();
      ans += bit[iq].get(li, ri);
    }
    bit[segs[i].iq].increase(where[i]);
  }
  cout << ans << '\n';
}