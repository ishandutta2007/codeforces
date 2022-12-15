// Lynkcat.
// Problem: B. Palindromic Numbers
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
// #define int ll
// #define N 
using namespace std;
const int base = 1000000000;
const int base_digits = 9;
#define bg bigint_t 
struct bigint_t {
  vector<int> z;
  int sign;
 
  bigint_t() : sign(1) {}
 
  bigint_t(long long v) { *this = v; }
 
  bigint_t(const string &s) { read(s); }
 
  void operator=(const bigint_t &v) {
    sign = v.sign;
    z = v.z;
  }
 
  void operator=(long long v) {
    sign = 1;
    if (v < 0) {
      sign = -1, v = -v;
    }
    z.clear();
    for (; v > 0; v = v / base) {
      z.push_back(v % base);
    }
  }
 
  bigint_t operator+(const bigint_t &v) const {
    if (sign == v.sign) {
      bigint_t res = v;
 
      for (int i = 0, carry = 0; i < max(z.size(), v.z.size()) || carry; ++i) {
        if (i == res.z.size()) {
          res.z.push_back(0);
        }
        res.z[i] += carry + (i < z.size() ? z[i] : 0);
        carry = res.z[i] >= base;
        if (carry) {
          res.z[i] -= base;
        }
      }
      return res;
    } else {
      return *this - (-v);
    }
  }
 
  bigint_t operator-(const bigint_t &v) const {
    if (sign == v.sign) {
      if (abs() >= v.abs()) {
        bigint_t res = *this;
        for (int i = 0, carry = 0; i < v.z.size() || carry; ++i) {
          res.z[i] -= carry + (i < v.z.size() ? v.z[i] : 0);
          carry = res.z[i] < 0;
          if (carry) {
            res.z[i] += base;
          }
        }
        res.trim();
        return res;
      } else {
        return -(v - *this);
      }
    } else {
      return *this + (-v);
    }
  }
 
  void operator*=(int v) {
    if (v < 0) {
      sign = -sign, v = -v;
    }
    for (int i = 0, carry = 0; i < z.size() || carry; ++i) {
      if (i == z.size()) {
        z.push_back(0);
      }
      long long cur = (long long)z[i] * v + carry;
      carry = cur / base;
      z[i] = cur % base;
      // asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
    }
    trim();
  }
 
  bigint_t operator*(int v) const {
    bigint_t res = *this;
    res *= v;
    return res;
  }
 
  friend pair<bigint_t, bigint_t> divmod(const bigint_t &a1,
                                         const bigint_t &b1) {
    int norm = base / (b1.z.back() + 1);
    bigint_t a = a1.abs() * norm;
    bigint_t b = b1.abs() * norm;
    bigint_t q, r;
    q.z.resize(a.z.size());
 
    for (int i = a.z.size() - 1; i >= 0; i--) {
      r *= base;
      r += a.z[i];
      int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
      int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
      int d = ((long long)s1 * base + s2) / b.z.back();
      r -= b * d;
      while (r < 0) {
        r += b, --d;
      }
      q.z[i] = d;
    }
 
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }
 
  friend bigint_t sqrt(const bigint_t &a1) {
    bigint_t a = a1;
    while (a.z.empty() || a.z.size() % 2 == 1) {
      a.z.push_back(0);
    }
 
    int n = a.z.size();
 
    int firstDigit = sqrt((long long)a.z[n - 1] * base + a.z[n - 2]);
    int norm = base / (firstDigit + 1);
    a *= norm;
    a *= norm;
    while (a.z.empty() || a.z.size() % 2 == 1) {
      a.z.push_back(0);
    }
 
    bigint_t r = (long long)a.z[n - 1] * base + a.z[n - 2];
    firstDigit = sqrt((long long)a.z[n - 1] * base + a.z[n - 2]);
    int q = firstDigit;
    bigint_t res;
 
    for (int j = n / 2 - 1; j >= 0; j--) {
      for (;; --q) {
        bigint_t r1 =
            (r - (res * 2 * base + q) * q) * base * base +
            (j > 0 ? (long long)a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
        if (r1 >= 0) {
          r = r1;
          break;
        }
      }
      res *= base;
      res += q;
 
      if (j > 0) {
        int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
        int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
        int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
        q = ((long long)d1 * base * base + (long long)d2 * base + d3) /
            (firstDigit * 2);
      }
    }
 
    res.trim();
    return res / norm;
  }
 
  bigint_t operator/(const bigint_t &v) const { return divmod(*this, v).first; }
 
  bigint_t operator%(const bigint_t &v) const {
    return divmod(*this, v).second;
  }
 
  void operator/=(int v) {
    if (v < 0) {
      sign = -sign, v = -v;
    }
    for (int i = z.size() - 1, rem = 0; i >= 0; --i) {
      long long cur = z[i] + (long long)rem * base;
      z[i] = cur / v;
      rem = cur % v;
    }
    trim();
  }
 
  bigint_t operator/(int v) const {
    bigint_t res = *this;
    res /= v;
    return res;
  }
 
  int operator%(int v) const {
    if (v < 0) {
      v = -v;
    }
    int m = 0;
    for (int i = z.size() - 1; i >= 0; --i) {
      m = ((long long)m * base + z[i]) % v;
    }
    return m * sign;
  }
 
  void operator+=(const bigint_t &v) { *this = *this + v; }
  void operator-=(const bigint_t &v) { *this = *this - v; }
  void operator*=(const bigint_t &v) { *this = *this * v; }
  void operator/=(const bigint_t &v) { *this = *this / v; }
 
  bool operator<(const bigint_t &v) const {
    if (sign != v.sign) {
      return sign < v.sign;
    }
    if (z.size() != v.z.size()) {
      return z.size() * sign < v.z.size() * v.sign;
    }
    for (int i = z.size() - 1; i >= 0; i--) {
      if (z[i] != v.z[i]) {
        return z[i] * sign < v.z[i] * sign;
      }
    }
    return false;
  }
 
  bool operator>(const bigint_t &v) const { return v < *this; }
  bool operator<=(const bigint_t &v) const { return !(v < *this); }
  bool operator>=(const bigint_t &v) const { return !(*this < v); }
  bool operator==(const bigint_t &v) const {
    return !(*this < v) && !(v < *this);
  }
  bool operator!=(const bigint_t &v) const { return *this < v || v < *this; }
 
  void trim() {
    while (!z.empty() && z.back() == 0) {
      z.pop_back();
    }
    if (z.empty()) {
      sign = 1;
    }
  }
 
  bool isZero() const { return z.empty() || (z.size() == 1 && !z[0]); }
 
  bigint_t operator-() const {
    bigint_t res = *this;
    res.sign = -sign;
    return res;
  }
 
  bigint_t abs() const {
    bigint_t res = *this;
    res.sign *= res.sign;
    return res;
  }
 
  long long longValue() const {
    long long res = 0;
    for (int i = z.size() - 1; i >= 0; i--) {
      res = res * base + z[i];
    }
    return res * sign;
  }
 
  friend bigint_t gcd(const bigint_t &a, const bigint_t &b) {
    return b.isZero() ? a : gcd(b, a % b);
  }
  friend bigint_t lcm(const bigint_t &a, const bigint_t &b) {
    return a / gcd(a, b) * b;
  }
 
  void read(const string &s) {
    sign = 1;
    z.clear();
    int pos = 0;
    while (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {
      if (s[pos] == '-') {
        sign = -sign;
      }
      ++pos;
    }
    for (int i = s.size() - 1; i >= pos; i -= base_digits) {
      int x = 0;
      for (int j = max(pos, i - base_digits + 1); j <= i; j++) {
        x = x * 10 + s[j] - '0';
      }
      z.push_back(x);
    }
    trim();
  }
 
  friend istream &operator>>(istream &stream, bigint_t &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
  }
 
  friend ostream &operator<<(ostream &stream, const bigint_t &v) {
    if (v.sign == -1) {
      stream << '-';
    }
    stream << (v.z.empty() ? 0 : v.z.back());
    for (int i = v.z.size() - 2; i >= 0; --i) {
      stream << setw(base_digits) << setfill('0') << v.z[i];
    }
    return stream;
  }
 
  static vector<int> convert_base(const vector<int> &a, int old_digits,
                                  int new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for (int i = 1; i < p.size(); i++) {
      p[i] = p[i - 1] * 10;
    }
    vector<int> res;
    long long cur = 0;
    int cur_digits = 0;
    for (int i = 0; i < a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while (cur_digits >= new_digits) {
        res.push_back(cur % p[new_digits]);
        cur /= p[new_digits];
        cur_digits -= new_digits;
      }
    }
    res.push_back(cur);
    while (!res.empty() && res.back() == 0) {
      res.pop_back();
    }
    return res;
  }
 
  typedef vector<long long> vll;
 
  static vll karatsubaMultiply(const vll &a, const vll &b) {
    int n = a.size();
    vll res(n + n);
    if (n <= 32) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    }
 
    int k = n >> 1;
    vll a1(a.begin(), a.begin() + k);
    vll a2(a.begin() + k, a.end());
    vll b1(b.begin(), b.begin() + k);
    vll b2(b.begin() + k, b.end());
 
    vll a1b1 = karatsubaMultiply(a1, b1);
    vll a2b2 = karatsubaMultiply(a2, b2);
 
    for (int i = 0; i < k; i++) {
      a2[i] += a1[i];
    }
    for (int i = 0; i < k; i++) {
      b2[i] += b1[i];
    }
 
    vll r = karatsubaMultiply(a2, b2);
    for (int i = 0; i < a1b1.size(); i++) {
      r[i] -= a1b1[i];
    }
    for (int i = 0; i < a2b2.size(); i++) {
      r[i] -= a2b2[i];
    }
 
    for (int i = 0; i < r.size(); i++) {
      res[i + k] += r[i];
    }
    for (int i = 0; i < a1b1.size(); i++) {
      res[i] += a1b1[i];
    }
    for (int i = 0; i < a2b2.size(); i++) {
      res[i + n] += a2b2[i];
    }
    return res;
  }
 
  bigint_t operator*(const bigint_t &v) const {
    vector<int> a6 = convert_base(this->z, base_digits, 6);
    vector<int> b6 = convert_base(v.z, base_digits, 6);
    vll a(a6.begin(), a6.end());
    vll b(b6.begin(), b6.end());
    while (a.size() < b.size()) {
      a.push_back(0);
    }
    while (b.size() < a.size()) {
      b.push_back(0);
    }
    while (a.size() & (a.size() - 1)) {
      a.push_back(0);
      b.push_back(0);
    }
    vll c = karatsubaMultiply(a, b);
    bigint_t res;
    res.sign = sign * v.sign;
    for (int i = 0, carry = 0; i < c.size(); i++) {
      long long cur = c[i] + carry;
      res.z.push_back(cur % 1000000);
      carry = cur / 1000000;
    }
    res.z = convert_base(res.z, 6, base_digits);
    res.trim();
    return res;
  }
};
int n;
string st;
void BellaKira()
{
	cin>>n;
	cin>>st;
	bg now;
	now=bg(st);
	if (st[0]=='9')
	{
		string p="";
		if (n==2) p="111";
		else 
		{
			p+="11";
			for (int i=1;i<=n-3;i++) p+="0";
			p+="11";
		}
		bg nowp=bg(p);
		nowp-=now;
		cout<<nowp<<endl;
	}  else
	{
		string p="";
		if (n==2) p="101";
		else 
		{
			p+="1";
			for (int i=1;i<=n-1;i++) p+="0";
			p+="1";
		}
		bg nowp=bg(p);
		// cout<<nowp<<endl;
		nowp-=now;
		cout<<nowp<<endl;
	}
		
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}