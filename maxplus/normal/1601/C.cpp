#include <algorithm>
#include <iostream>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr == '-') {
        sign = 1;
      } else if (*bufptr < '0') {
        *b++ *= sign? -1: 1, sign = 0;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e6;

int a[N], b[N], c[2 * N], * cptr = c;

void insert_b(const range<int*>& a, const range<int*>& b) {
  if (b.size() == 0) {
    cptr = copy(a.begin(), a.end(), cptr);
    return;
  }
  int* midb = b.begin() + b.size() / 2, cb = *midb;
  int inv = 0;
  for (auto ca: a) {
    inv += ca < cb;
  }
  int* bp = a.begin(), binv = inv;
  for (auto& ca: a) {
    if (minb(binv, inv += (ca > cb) - (ca < cb))) {
      bp = &ca + 1;
    }
  }
  while (midb-- != b.begin() && *midb == cb);
  insert_b({a.begin(), bp}, {b.begin(), ++midb});
  do {
    *cptr++ = *midb++;
  } while (midb != b.end() && *midb == cb);
  insert_b({bp, a.end()}, {midb, b.end()});
}

int64_t calc_inv(int first, int last, bool where) {
  int* from = c, * to = min(&*a, &*b);
  if (last - first <= 1) {
    if (where) {
      copy(c + first, c + last, to + first);
    }
    return {};
  }
  int mid = first + (last - first) / 2;
  int64_t ans = calc_inv(first, mid, !where) + calc_inv(mid, last, !where);
  if (!where) {
    swap(from, to);
  }
  int i = first, j = mid, w = first;
  while (i != mid && j != last) {
    if (from[i] <= from[j]) {
      to[w++] = from[i++];
    } else {
      ans += mid - i;
      to[w++] = from[j++];
    }
  }
  w = copy(from + i, from + mid, to + w) - to;
  copy(from + j, from + last, to + w);
  return ans;
}

int main() {
  for (int testcase = $; testcase; --testcase) {
    cptr = c;
    int n = $, m = $;
    reader(a, n);
    reader(b, m);
    sort(b, b + m);
    insert_b({a, n}, {b, m});
    bool where = __builtin_clz(n + m - 1) & 1;
    where ^= (n + m) * 3 < (1 << 33 - __builtin_clz(n + m - 1));
    print(calc_inv(0, n + m, where));
  }
}