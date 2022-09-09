#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
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
#ifndef AIM
  cout.sync_with_stdio(0);
cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
//cin  t;
  precalc();
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

//#define int li
//const li mod = 1000000007;

//using ull = unsigned long long;

const int LBase = 4;
const int Base = 10000;

struct BigInt {
  vector<int> a;
  BigInt() {
  }
  BigInt(string s) {
    reverse(all(s));
    for (int i = 0; i < s.length(); i += LBase) {
      int en = min((int)s.length(), i + LBase);
      int cur = 0;
      for (int j = en - 1; j >= i; --j) {
        cur = cur * 10 + s[j] - '0';
      }
      a.push_back(cur);
    }
  }
  void norm() {
    int carry = 0;
    for (int i = 0; i < a.size() || carry > 0; ++i) {
      if (i == a.size()) {
        a.push_back(0);
      }
      a[i] += carry;
      carry = a[i] / Base;
      a[i] -= carry * Base;
    }
    while (a.size() > 0 && a.back() == 0) {
      a.pop_back();
    }
  }
  bool operator < (const BigInt& ot) const {
    if (a.size() != ot.a.size()) {
      return a.size() < ot.a.size();
    }
    for (int i = 0; i < a.size(); ++i) {
      int q = a[a.size() - 1 - i], w = ot.a[a.size() - 1 - i];
      if (q != w) {
        return q < w;
      }
    }
    return false;
  }
  BigInt operator * (int c) const {
    BigInt res = *this;
    for (int& x : res.a) {
      x *= c;
    }
    res.norm();
    return res;
  }
};

const int L = 22;
const int N = 1 << L;
bool fft_initialized = false;

#define ld double

using base = complex<ld>;
using Poly = vector<ld>;

const ld pi = acosl(-1);
base angles[N + 1];
int bitrev[N];

// don't know why such eps, may be changed
const ld eps = 1e-7;

inline bool eq(ld x, ld y) {
  return abs(x - y) < eps;
}

void fft_init() {
  for (int i = 0; i <= N; ++i) {
    angles[i] = {cosl(2 * pi * i / N), sinl(2 * pi * i / N)};
  }

  for (int i = 0; i < N; ++i) {
    int x = i;
    for (int j = 0; j < L; ++j) {
      bitrev[i] = (bitrev[i] << 1) | (x & 1);
      x >>= 1;
    }
  }

  fft_initialized = true;
}

inline int revBit(int x, int len) {
  return bitrev[x] >> (L - len);
}

void fft(vector<base>& a, bool inverse = false) {
  assert(fft_initialized && "you fucking cunt just write fft_init()");
  int n = a.size();
  assert(!(n & (n - 1)));	// work only with powers of two
  int l = __builtin_ctz(n);

  for (int i = 0; i < n; ++i) {
    int j = revBit(i, l);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }

  for (int len = 1; len < n; len *= 2) {
    for (int start = 0; start < n; start += 2 * len) {
      for (int i = 0; i < len; ++i) {
        base x = a[start + i], y = a[start + len + i];
        int idx = N / 2 / len * i;
        base w = y * angles[inverse ? N - idx : idx];
        a[start + i] = x + w;
        a[start + len + i] = x - w;
      }
    }
  }

  if (inverse) {
    for (auto& x : a) {
      x /= n;
    }
  }
}

Poly multiply(Poly a, Poly b) {
  int n = 1;
  while (n < (int)a.size() || n < (int)b.size()) {
    n *= 2;
  }
  vector<base> ar(n + n), br(n + n);
  for (int i = 0; i < (int)a.size(); ++i) {
    ar[i] = a[i];
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    br[i] = b[i];
  }
  fft(ar);
  fft(br);
  for (int i = 0; i < n + n; ++i) {
    ar[i] = ar[i] * br[i];
  }
  fft(ar, true);
  while (!ar.empty() && eq(norm(ar.back()), 0)) {
    ar.pop_back();
  }
  a.resize(ar.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    a[i] = real(ar[i]);
  }
  return a;
}

BigInt multiply(const BigInt& a, const BigInt& b) {
  vector<ld> A(a.a.begin(), a.a.end()), B(b.a.begin(), b.a.end());
  auto C = multiply(A, B);
  BigInt res;
  res.a.resize(C.size());
  li carry = 0;
  for (int i = 0; i < C.size() || carry; ++i) {
    if (i < C.size()) {
      carry += (li) round(C[i]);
    }
    if (i == res.a.size()) {
      res.a.push_back(0);
    }
    res.a[i] = carry % Base;
    carry /= Base;
  }
  res.norm();
  return res;
}

BigInt get_power(BigInt cur, int what) {
    if (what == 0) {
        return BigInt("1");
    }
    cur = get_power(cur, what / 2);
    cur = multiply(cur, cur);
    if (what & 1) {
        cur = cur * 3;
    }
    return cur;
}

void solve(bool read) {
  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    s = string(1500000, '9');
    for (int i = 1; i < s.length(); ++i) {
      s[i] = (char)('0' + rand() % 10);
    }
  }
  if (s == "1") {
    cout << 1 << "\n";
    return;
  }
  BigInt num(s);
  double log_appr = ((int)s.length() - 1); // + log(num.a.back());
  log_appr = log_appr * log(10) / log(3);
  int b = max((int)(log_appr - 5), 0);
  if (b % 2 == 1) --b;
  fft_init();

  int need_b = b;
  BigInt three;
  three.a = vector<int>(1, 3);
  BigInt res = get_power(three, b);
  int ans = (int)1e9;

  auto relax = [&] (int mult, int a) {
    auto cur_res = res * mult;
    int cur_ans = 3 * b + a * 2;
    while (cur_res < num) {
      cur_res = cur_res * 3;
      cur_ans += 3;
    }
    ans = min(ans, cur_ans);
  };

  relax(1, 0);
  relax(2, 1);
  relax(4, 2);

  cout << ans << "\n";

}