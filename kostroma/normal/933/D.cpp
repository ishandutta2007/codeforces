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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
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

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

#define int li
const int mod = 1000000007;

int rev6, rev3;

struct Item {
  vector<int> degs;
  int k;
  Item() {
    degs.assign(3, 0);
    k = 1;
  }
  Item(int a, int b, int c, int K) {
    degs = {a, b, c};
    k = K;
  }
  int& operator [] (int c) {
    return degs[c];
  }
  Item operator * (const Item& ot) const {
    Item res = Item();
    res.k = k * ot.k % mod;
    for (int i = 0; i < 3; ++i) {
      res[i] = degs[i] + ot.degs[i];
    }
    return res;
  }
  bool operator < (const Item& ot) const {
    return degs < ot.degs;
  }
  int get_sum(int a, int max_b, int m) {
    int res = k * m * a % mod;
    assert(degs[1] <= 1);
    if (degs[1] == 0) {
      return res * (2 * max_b + 1) % mod;
    }
    int b = max_b % mod;
    if (max_b >= mod || max_b < 0) {
      cout << b << " " << max_b << endl;
    }
    int mult = b * (b + 1) * (2 * b + 1) % mod * rev3 % mod;
    res = res * mult % mod;
    return res;
  }
  void print() {
    for (int x : degs) {
      cout << x << " ";
    }
    cout << k << endl;
  }
};

void norm(vector<Item>& cur) {
  sort(all(cur));
  vector<Item> now;
  for (int i = 0; i < cur.size(); ++i) {
    if (!now.empty() && now.back().degs == cur[i].degs) {
      now.back().k += cur[i].k;
      now.back().k %= mod;
      continue;
    }
    now.push_back(cur[i]);
  }
  now.swap(cur);
}

vector<Item> mult(vector<Item> q, vector<Item> w) {
  vector<Item> res;
  for (auto& a : q) {
    for (auto& b : w) {
      res.push_back(a * b);
    }
  }
  norm(res);
  return res;
}

void solve(bool read) {
  rev3 = binpow(3LL, mod - 2, mod);
  rev6 = binpow(6LL, mod - 2, mod);
  auto poly_m = Item(0, 0, 1, 1);
  auto poly_one = Item(0, 0, 0, 1);
  auto poly_minus_one = Item(0, 0, 0, -1);

  vector<vector<Item>> parts(4);
  parts[0] = mult( {poly_m, poly_one}, mult({poly_m, poly_minus_one}, {poly_m}));

  auto poly_square = {Item(1, 0, 0, 1), Item(0, 1, 0, 1)};
  auto poly_square_minus_one = {Item(1, 0, 0, 1), Item(0, 1, 0, 1), poly_minus_one};

  parts[1] = mult( {Item(0, 0, 1, -3)}, mult( poly_square, poly_square_minus_one ) );

  parts[2] = mult( mult({Item(0, 0, 0, 2)}, poly_square_minus_one), mult(poly_square, poly_square) );

  parts[3] = mult(mult(poly_square, poly_square_minus_one), {poly_minus_one});

  vector<Item> polynom;
  for (auto& vec : parts) {
    for (auto& x : vec) {
      polynom.push_back(x);
    }
  }
  norm(polynom);

  for (auto& item : polynom) {
    if (item.degs[1] > item.degs[0]) {
      swap(item.degs[0], item.degs[1]);
    }
  }
  norm(polynom);
  /*for (auto& item : polynom) {
    item.print();
  }*/

  int m;
  cin >> m;
  ++m;

  int res = 0;
  int max_b = (int)sqrt((ld)m) + 10;
  int cnt = 0;
  vector<int> powers(5, 1);
  for (int i = 1; i < powers.size(); ++i) {
    powers[i] = powers[i - 1] * (m % mod) % mod;
  }
  for (int a = 0; a * a < m; ++a) {
    while (a * a + max_b * max_b >= m) {
      --max_b;
    }
    int step_a = 1;
    int last = 0;
    for (auto& item : polynom) {
      while (last < item.degs[0]) {
        step_a = step_a * a % mod * a % mod;
        ++last;
      }
      //cout << a << " " << max_b << endl;
      ++cnt;
      int cur_val = item.get_sum(step_a, max_b, powers[item.degs[2]]);
      res += cur_val;
      res %= mod;
      if (a) {
        res += cur_val;
        res %= mod;
      }
    }
    //cout << "look " << a << " " << max_b << " " << res << endl;
  }

  //cout << cnt << endl;

  res = res * rev6 % mod;
  if (res < 0) {
    res += mod;
  }

  cout << res << endl;

}