#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
    //cout << "Case #" << testNum++ << ": ";
    //cerr << testNum << endl;
    solve(true);
    //cerr << testNum - 1 << endl;
  }
  cout.flush();
#ifdef AIM1
  while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

void precalc() {

}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

//#define int li
//const int mod = 1000000007;

const int shift = 1 << 17;
int tree[2 * shift];

int rsq(int l, int r) {
  if (l >= r) {
    return 0;
  }
  if (l & 1) {
    return tree[l] + rsq(l + 1, r);
  }
  if (r & 1) {
    return tree[r - 1] + rsq(l, r - 1);
  }
  return rsq(l / 2, r / 2);
}

int get_sum(int l, int r) {
  return rsq(l + shift, r + shift);
}

void modify(int v, int val) {
  v += shift;
  tree[v] += val;
  v /= 2;
  while (v) {
    tree[v] = tree[2 * v] + tree[2 * v + 1];
    v /= 2;
  }
}

int get_res(int l, int r) {
  if (l <= r) {
    return get_sum(l, r) + 1;
  } else {
    return get_sum(l, shift) + get_sum(0, r) + 1;
  }
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    tree[i + shift] = 1;
  }
  for (int i = shift - 1; i > 0; --i) {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  li ans = 0;
  vector<pair<int, int>> sorted;
  for (int i = 0; i < n; ++i) {
    sorted.push_back({a[i], i});
  }
  sort(all(sorted));
  int uk = 0;
  int cur_pos = 0;
  while (uk < sorted.size()) {
    vector<int> poses;
    int j = uk;
    while (j < sorted.size() && sorted[j].first == sorted[uk].first) {
      poses.push_back(sorted[j].second);
      ++j;
    }
    uk = j;

    sort(all(poses));

    auto it = lower_bound(all(poses), cur_pos);
    if (it == poses.end()) {
      it = poses.begin();
    }
    int id = it - poses.begin();
    for (int i = 0; i < poses.size(); ++i) {
      ans += get_res(cur_pos, poses[id]);
      modify(poses[id], -1);
      cur_pos = poses[id];
      id = (id + 1) % (int)poses.size();
    }
  }
  cout << ans << endl;

}