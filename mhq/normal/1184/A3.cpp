// inversePoly(nlog), multipoint evaluation(nlog^2), poly mod(nlog)
#include <bits/stdc++.h>
using namespace std;
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;
    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
      value = normalize(x);
    }
    template <typename U>
    static Type normalize(const U& x) {
      Type v;
      if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
      else v = static_cast<Type>(x % mod());
      if (v < 0) v += mod();
      return v;
    }
    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }
    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
      uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
      uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
      asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
      );
      value = m;
#else
      value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
      return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
      int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
      value = normalize(value * rhs.value - q * mod());
      return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
      value = normalize(value * rhs.value);
      return *this;
    }
    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U>
    friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
private:
    Type value;
};
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

// make it understandable one day...
namespace fft {
    typedef long double dbl;
    struct num {
        dbl x, y;
        num() { x = y = 0; }
        num(dbl x_, dbl y_) : x(x_), y(y_) {}
    };
    inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }
    int base = 1;
    vector<num> roots = {{0, 0}, {1, 0}};
    vector<int> rev = {0, 1};
    const dbl PI = static_cast<dbl>(acosl(-1.0));
    void ensure_base(int nbase) {
      if (nbase <= base) {
        return;
      }
      rev.resize(1 << nbase);
      for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
      }
      roots.resize(1 << nbase);
      while (base < nbase) {
        dbl angle = 2 * PI / (1 << (base + 1));
//      num z(cos(angle), sin(angle));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
          roots[i << 1] = roots[i];
//        roots[(i << 1) + 1] = roots[i] * z;
          dbl angle_i = angle * (2 * i + 1 - (1 << base));
          roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
        }
        base++;
      }
    }
    void fft(vector<num>& a, int n = -1) {
      if (n == -1) {
        n = (int) a.size();
      }
      assert((n & (n - 1)) == 0);
      int zeros = __builtin_ctz(n);
      ensure_base(zeros);
      int shift = base - zeros;
      for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
          swap(a[i], a[rev[i] >> shift]);
        }
      }
      for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
          for (int j = 0; j < k; j++) {
            num z = a[i + j + k] * roots[j + k];
            a[i + j + k] = a[i + j] - z;
            a[i + j] = a[i + j] + z;
          }
        }
      }
    }
    vector<num> fa, fb;
    vector<int64_t> square(const vector<int>& a) {
      if (a.empty()) {
        return {};
      }
      int need = (int) a.size() + (int) a.size() - 1;
      int nbase = 1;
      while ((1 << nbase) < need) nbase++;
      ensure_base(nbase);
      int sz = 1 << nbase;
      if ((sz >> 1) > (int) fa.size()) {
        fa.resize(sz >> 1);
      }
      for (int i = 0; i < (sz >> 1); i++) {
        int x = (2 * i < (int) a.size() ? a[2 * i] : 0);
        int y = (2 * i + 1 < (int) a.size() ? a[2 * i + 1] : 0);
        fa[i] = num(x, y);
      }
      fft(fa, sz >> 1);
      num r(1.0 / (sz >> 1), 0.0);
      for (int i = 0; i <= (sz >> 2); i++) {
        int j = ((sz >> 1) - i) & ((sz >> 1) - 1);
        num fe = (fa[i] + conj(fa[j])) * num(0.5, 0);
        num fo = (fa[i] - conj(fa[j])) * num(0, -0.5);
        num aux = fe * fe + fo * fo * roots[(sz >> 1) + i] * roots[(sz >> 1) + i];
        num tmp = fe * fo;
        fa[i] = r * (conj(aux) + num(0, 2) * conj(tmp));
        fa[j] = r * (aux + num(0, 2) * tmp);
      }
      fft(fa, sz >> 1);
      vector<int64_t> res(need);
      for (int i = 0; i < need; i++) {
        res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
      }
      return res;
    }
    vector<int64_t> multiply(const vector<int>& a, const vector<int>& b) {
      if (a.empty() || b.empty()) {
        return {};
      }
      if (a == b) {
        return square(a);
      }
      int need = (int) a.size() + (int) b.size() - 1;
      int nbase = 1;
      while ((1 << nbase) < need) nbase++;
      ensure_base(nbase);
      int sz = 1 << nbase;
      if (sz > (int) fa.size()) {
        fa.resize(sz);
      }
      for (int i = 0; i < sz; i++) {
        int x = (i < (int) a.size() ? a[i] : 0);
        int y = (i < (int) b.size() ? b[i] : 0);
        fa[i] = num(x, y);
      }
      fft(fa, sz);
      num r(0, -0.25 / (sz >> 1));
      for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
        fa[i] = z;
      }
      for (int i = 0; i < (sz >> 1); i++) {
        num A0 = (fa[i] + fa[i + (sz >> 1)]) * num(0.5, 0);
        num A1 = (fa[i] - fa[i + (sz >> 1)]) * num(0.5, 0) * roots[(sz >> 1) + i];
        fa[i] = A0 + A1 * num(0, 1);
      }
      fft(fa, sz >> 1);
      vector<int64_t> res(need);
      for (int i = 0; i < need; i++) {
        res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
      }
      return res;
    }
    vector<int> multiply_mod(const vector<int>& a, const vector<int>& b, int m) {
      if (a.empty() || b.empty()) {
        return {};
      }
      int eq = (a.size() == b.size() && a == b);
      int need = (int) a.size() + (int) b.size() - 1;
      int nbase = 0;
      while ((1 << nbase) < need) nbase++;
      ensure_base(nbase);
      int sz = 1 << nbase;
      if (sz > (int) fa.size()) {
        fa.resize(sz);
      }
      for (int i = 0; i < (int) a.size(); i++) {
        int x = (a[i] % m + m) % m;
        fa[i] = num(x & ((1 << 10) - 1), x >> 10);
      }
      fill(fa.begin() + a.size(), fa.begin() + sz, num {0, 0});
      fft(fa, sz);
      if (sz > (int) fb.size()) {
        fb.resize(sz);
      }
      if (eq) {
        copy(fa.begin(), fa.begin() + sz, fb.begin());
      } else {
        for (int i = 0; i < (int) b.size(); i++) {
          int x = (b[i] % m + m) % m;
          fb[i] = num(x & ((1 << 10) - 1), x >> 10);
        }
        fill(fb.begin() + b.size(), fb.begin() + sz, num {0, 0});
        fft(fb, sz);
      }
      dbl ratio = 0.25 / sz;
      num r2(0, -1);
      num r3(ratio, 0);
      num r4(0, -ratio);
      num r5(0, 1);
      for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        num a1 = (fa[i] + conj(fa[j]));
        num a2 = (fa[i] - conj(fa[j])) * r2;
        num b1 = (fb[i] + conj(fb[j])) * r3;
        num b2 = (fb[i] - conj(fb[j])) * r4;
        if (i != j) {
          num c1 = (fa[j] + conj(fa[i]));
          num c2 = (fa[j] - conj(fa[i])) * r2;
          num d1 = (fb[j] + conj(fb[i])) * r3;
          num d2 = (fb[j] - conj(fb[i])) * r4;
          fa[i] = c1 * d1 + c2 * d2 * r5;
          fb[i] = c1 * d2 + c2 * d1;
        }
        fa[j] = a1 * b1 + a2 * b2 * r5;
        fb[j] = a1 * b2 + a2 * b1;
      }
      fft(fa, sz);
      fft(fb, sz);
      vector<int> res(need);
      for (int i = 0; i < need; i++) {
        int64_t aa = llround(fa[i].x);
        int64_t bb = llround(fb[i].x);
        int64_t cc = llround(fa[i].y);
        res[i] = static_cast<int>((aa + ((bb % m) << 10) + ((cc % m) << 20)) % m);
      }
      return res;
    }
}  // namespace fft
template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value, vector<Modular<T>>>::type operator*(
    const vector<Modular<T>>& a,
    const vector<Modular<T>>& b) {
  if (a.empty() || b.empty()) {
    return {};
  }
  if (min(a.size(), b.size()) < 150) {
    vector<Modular<T>> c(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int) a.size(); i++) {
      for (int j = 0; j < (int) b.size(); j++) {
        c[i + j] += a[i] * b[j];
      }
    }
    return c;
  }
  vector<int> a_mul(a.size());
  for (int i = 0; i < (int) a.size(); i++) {
    a_mul[i] = static_cast<int>(a[i]);
  }
  vector<int> b_mul(b.size());
  for (int i = 0; i < (int) b.size(); i++) {
    b_mul[i] = static_cast<int>(b[i]);
  }
  vector<int> c_mul = fft::multiply_mod(a_mul, b_mul, T::value);
  vector<Modular<T>> c(c_mul.size());
  for (int i = 0; i < (int) c.size(); i++) {
    c[i] = c_mul[i];
  }
  return c;
}
template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value, vector<Modular<T>>>::type& operator*=(
    vector<Modular<T>>& a,
    const vector<Modular<T>>& b) {
  return a = a * b;
}


int n, m;
bool pr(int i) {
  for (int j = 2; 1LL * j * j <= i; j++) {
    if (i % j == 0) return false;
  }
  return true;
}

int mod;


int mult(int a, int b) {
  return (1LL * a * b) % mod;
}

int pw(int a, int b) {
  if (b == 0) return 1;
  if (b & 1) return mult(a, pw(a, b - 1));
  int res = pw(a, b / 2);
  return mult(res, res);
}

int sub(int a, int b) {
  int s = a - b;
  if (s < 0) s += mod;
  return s;
}

int sum(int a, int b) {
  int s = a + b;
  if (s >= mod) s -= mod;
  return s;
}

const int maxN = 3 * (int)1e5 + 100;

int val[maxN];

vector < int > factor(int x) {
  vector < int > pr;
  for (int i = 2; 1LL * i * i <= x; i++) {
    if (x % i == 0) {
      pr.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) pr.push_back(x);
  return pr;
}

int calc(int a) {
  int res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int q = (val[i] % mod);
    if (q < 0) q += mod;
    res = (1LL * res * a + q) % mod;
    if (res < 0) res += mod;
  }
  return res;
}

void go() {
  auto primes = factor(mod - 1);
  int g = -1;
  for (int i = 2; ; i++) {
    bool ok = true;
    for (int v : primes) {
      if (pw(i, (mod - 1) / v) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      g = i;
      break;
    }
  }
  int z = mult(g, g);
  int n = mod - 1;
  vector < int > a(n), b(2 * n);
  for (int i = 0; i < n; i++) {
    int s = (val[i] % mod);
    if (s < 0) s += mod;
    int res = (1LL * i * i) % (mod - 1);
    a[i] = mult(s, pw(g, res));
    b[i + n] = pw(pw(g, mod - 2), res);
    b[-i + n] = b[i + n];
  }
  //
  vector < int > f = fft::multiply_mod(a, b, mod);
  for (int i = 0; i < n; i++) {
    if (f[i + n] % mod == 0) {
      int t = pw(z, i);
      if (t <= 1 || t >= mod - 1) continue;
      cout << mod << " " << t << '\n';
      assert(calc(t) == 0);
      exit(0);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input.txt", "r", stdin);
  cin >> n >> m;
  srand(24424);
  //n = 100000;
  //m = 100000;
  for (int iter = 0; iter < 2; iter++) {
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      //c = rand() % 26 + 'a';
      if (iter == 0) val[i] += c - 'a';
      else val[i] -= c - 'a';
    }
  }
  m = max(m, n) + 1;
  for (int i = m; ; i++) {
    if (pr(i)) {
      mod = i;
      go();
    }
  }
}