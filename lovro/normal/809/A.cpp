#define NDEBUG
#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
class FastInput {
public:
  FastInput() : ptr_(buf_), end_(buf_) { }

  template<typename... Args>
  void read(Args&... args) { read_multi(args...); }
  template<typename T> T read() {
    T result; read_one(result); return result;
  }

private:
  static const int MAXBUF = 8192;
  char buf_[MAXBUF];
  char *ptr_, *end_;

  template<typename T, typename... Args>
  void read_multi(T& out, Args&... args) {
    read_one(out);
    read_multi(args...);
  }
  void read_multi() { }

  template<typename T>
  void read_one(T& out) {
    static_assert(std::is_integral<T>::value, "");
    unsigned char ch;
    while (isspace(ch = readchar())) ;

    bool neg = false;
    if (std::is_signed<T>::value && ch == '-') {
      neg = true;
      ch = readchar();
    }
    typename std::make_unsigned<T>::type result = ch - '0';
    while (isdigit(ch = readchar())) {
      result = 10 * result + ch - '0';
    }
    out = std::is_signed<T>::value && neg ? -result : result;
  }
  void read_one(char& out) { out = readchar(); }
  void read_one(std::string& out) {
    out.clear();
    unsigned char ch;
    while (!isspace(ch = readchar())) {
      out.push_back(ch);
    }
  }

  unsigned char readchar() {
    if (ptr_ == end_) {
      ptr_ = buf_;
      end_ = buf_ + ::read(0, buf_, MAXBUF);
      if (ptr_ == end_) { // Simulate newline at EOF
        return '\n';
      }
    }
    return *ptr_++;
  }
} fin;
template<typename IntType, IntType ModValue>
class modulo {
public:
  static constexpr IntType MOD = ModValue;
  static_assert(MOD-1 <= std::numeric_limits<IntType>::max() / 2,
                "IntType must be wide enough to fit 2*MOD");

  modulo() { }
  template<typename AnyInt>
  modulo(AnyInt x) {
    if (x >= MOD) {
      x %= MOD;
    } else if (x < 0) {
      x %= MOD;
      x += MOD;
    }
    val_ = x;
  }

  friend modulo& operator+=(modulo& m1, modulo m2) {
    m1.val_ += m2.val_;
    if (m1.val_ >= MOD) {
      m1.val_ -= MOD;
    }
    return m1;
  }
  friend modulo& operator-=(modulo& m1, modulo m2) {
    if (m1.val_ < m2.val_) {
      m1.val_ += MOD;
    }
    m1.val_ -= m2.val_;
    return m1;
  }
  friend modulo& operator*=(modulo& m1, modulo m2) {
    m1.val_ = int64_t(m1.val_) * m2.val_ % MOD;
    return m1;
  }
  friend modulo& operator/=(modulo& m1, modulo m2) {
    return m1 *= m2.inverse();
  }
  friend modulo& operator++(modulo& m) {
    if (++m.val_ == MOD) {
      m.val_ = 0;
    }
    return m;
  }
  friend modulo& operator--(modulo& m) {
    m.val_ = m.val_ > 0 ? m.val - 1 : MOD - 1;
    return m;
  }

  friend modulo operator+(modulo m1, modulo m2) { return m1 += m2; }
  friend modulo operator-(modulo m1, modulo m2) { return m1 -= m2; }
  friend modulo operator*(modulo m1, modulo m2) { return m1 *= m2; }
  friend modulo operator/(modulo m1, modulo m2) { return m1 /= m2; }

  // Multiplicative inverse, assumes prime MOD
  modulo inverse() const { return power(*this, MOD-2, modulo(1)); }

  IntType val() const { return val_; }
private:
  IntType val_;
};

using mod = modulo<int, 1000000007>;

int main() {
  int n = fin.read<int>();
  vector<int> x(n);
  for (int& r : x) {
    fin.read(r);
  }
  sort(ALL(x));

  vector<mod> p2(n+1);
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p2[i] = 2 * p2[i-1];
  }

  mod ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += x[i] * p2[i];
    ans -= x[i] * p2[n-i-1];
  }
  cout << ans.val() << '\n';
}