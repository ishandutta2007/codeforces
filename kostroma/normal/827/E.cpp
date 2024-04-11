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
  cin >> t;
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

typedef complex<double> base;

double PI = acos((double)-1.0);

void fft(vector<base> & a, bool invert) {
  int n = (int)a.size();

  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1)
      j -= bit;
    j += bit;
    if (i < j)
      swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    base wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      base w(1);
      for (int j = 0; j < len / 2; ++j) {
        base u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (invert)
    for (int i = 0; i<n; ++i)
      a[i] = a[i] / base(n);
}

vector <double> multiply(const vector<double>& a, const vector<double>& b) {
  int n = 1;
  while (n <= a.size() || n <= b.size())
    n <<= 1;
  n <<= 1;
  vector<base> input[2];
  for (int w = 0; w < 2; ++w)
    input[w].assign(n, base(0, 0));
  for (int i = 0; i < a.size(); ++i)
    input[0][i] = a[i];
  for (int i = 0; i < b.size(); ++i)
    input[1][i] = b[i];
  for (int w = 0; w < 2; ++w) {
    fft(input[w], false);
  }
  vector <base> res(n);
  for (int i = 0; i < n; ++i)
    res[i] = input[0][i] * input[1][i];
  fft(res, true);
  vector<double> answer;
  for (int i = 0; i < n; ++i)
    answer.push_back(res[i].real());
  return answer;
}

void solve(bool read) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<double> first(n, 0.0), second(n, 0.0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'V') {
      first[i] = 1.0;
    } else if (s[i] == 'K') {
      second[n - 1 - i] = 1.0;
    }
  }
  auto mult = multiply(first, second);

  vector<int> has(mult.size(), 0);
  for (int i = 0; i < mult.size(); ++i) {
    int diff = abs(i - (n - 1));
    if (fabs(mult[i]) > 0.5) {
      has[diff] = 1;
    }
  }

  for (int d = 1; d < has.size(); ++d) {
    for (int cur = d; cur < has.size(); cur += d) {
      if (has[cur]) {
        has[d] = 1;
        break;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (!has[i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

}