#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <map>

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

constexpr int N = 2e5 + 2, L = 8;

int p[N], nxt[N];
int a[N], b[N];

int optl[L][N];
int64_t costl[L][N];

int optr[L][N];
int64_t costr[L][N];

map<int, int64_t> req;

int64_t cost0(int i, int j) {
  int64_t res = 0;
  if (i == j) {
    return res;
  }
  int ml = min((33 - __builtin_clz((j - i) * 2 - 1)) / 2, L - 1);
  while (optr[ml][i] > j && ml > -1) {
    --ml;
  }
  if (ml == L - 1)
  while (optr[L - 1][i] <= j && i != j) {
    res += costr[L - 1][i];
    i = optr[L - 1][i];
  }
  for (int l = min(ml, L - 2); l > -1 && i != j; --l) {
    if (optr[l][i] <= j) {
      res += costr[l][i];
      i = optr[l][i];
      if (optr[l][i] <= j) {
        res += costr[l][i];
        i = optr[l][i];
        if (optr[l][i] <= j) {
          res += costr[l][i];
          i = optr[l][i];
        }
      }
    }
  }
  if (i == j) {
    return res;
  }
  ml = min((33 - __builtin_clz((j - i) * 2 - 1)) / 2, L - 1);
  while (optl[ml][j] < i && ml > -1) {
    --ml;
  }
  if (ml == L - 1)
  while (optl[L - 1][j] >= i && i != j) {
    res += costl[L - 1][j];
    j = optl[L - 1][j];
  }
  for (int l = min(ml, L - 2); l > -1 && i != j; --l) {
    if (optl[l][j] >= i) {
      res += costl[l][j];
      j = optl[l][j];
      if (optl[l][j] >= i) {
        res += costl[l][j];
        j = optl[l][j];
        if (optl[l][j] >= i) {
          res += costl[l][j];
          j = optl[l][j];
        }
      }
    }
  }
  return res;
}

int64_t cost1(int i, int j) {
  int64_t res = 0;
  if (i == j) {
    return res;
  }
  int ml = min((33 - __builtin_clz((j - i) * 2 - 1)) / 2, L - 1);
  while (optl[ml][j] < i && ml > -1) {
    --ml;
  }
  if (ml == L - 1)
  while (optl[L - 1][j] >= i && i != j) {
    res += costl[L - 1][j];
    j = optl[L - 1][j];
  }
  for (int l = min(ml, L - 2); l > -1 && i != j; --l) {
    if (optl[l][j] >= i) {
      res += costl[l][j];
      j = optl[l][j];
      if (optl[l][j] >= i) {
        res += costl[l][j];
        j = optl[l][j];
        if (optl[l][j] >= i) {
          res += costl[l][j];
          j = optl[l][j];
        }
      }
    }
  }
  if (i == j) {
    return res;
  }
  ml = min((33 - __builtin_clz((j - i) * 2 - 1)) / 2, L - 1);
  while (optr[ml][i] > j && ml > -1) {
    --ml;
  }
  if (ml == L - 1)
  while (optr[L - 1][i] <= j && i != j) {
    res += costr[L - 1][i];
    i = optr[L - 1][i];
  }
  for (int l = min(ml, L - 2); l > -1 && i != j; --l) {
    if (optr[l][i] <= j) {
      res += costr[l][i];
      i = optr[l][i];
      if (optr[l][i] <= j) {
        res += costr[l][i];
        i = optr[l][i];
        if (optr[l][i] <= j) {
          res += costr[l][i];
          i = optr[l][i];
        }
      }
    }
  }
  return res;
}

int64_t cost(bool which, int i, int j) {
  return which? cost1(i, j): cost0(i, j);
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, q = $;
  reader(p + 1, n);
  reader(a + 1, n);
  reader(b + 1, n);
  p[n + 1] = n + 1;

  {
    vector<array<int, 2>> mv{{n + 1, n + 1}};
    for (int i = n; i > -1; --i) {
      while (mv.back()[0] < p[i]) {
        mv.pop_back();
      }
      nxt[i] = mv.back()[1];
      mv.emplace_back(array{p[i], i});
    }
  }
  int64_t sum = 0;
  {
    memset(costl, 63, sizeof costl);
    costl[0][0] = 0;
    optr[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
      if (minb(costl[0][i + 1], costl[0][i] + a[i])) {
        optl[0][i + 1] = i;
      }
      if (minb(costl[0][nxt[i]], costl[0][i] + b[i])) {
        optl[0][nxt[i]] = i;
      }
      sum -= optl[0][i];
    }
    for (int i = n + 1; i; --i) {
      costl[0][i] -= costl[0][optl[0][i]];
    }
    for (int l = 0; l < L - 1; ++l)
    for (int i = 0; i <= n + 1; ++i) {
      costl[l + 1][i] = costl[l][i];
      optl[l + 1][i] = optl[l][i];
      if (optl[l + 1][i]) {
        costl[l + 1][i] += costl[l][optl[l + 1][i]];
        optl[l + 1][i] = optl[l][optl[l + 1][i]];
        if (optl[l + 1][i]) {
          costl[l + 1][i] += costl[l][optl[l + 1][i]];
          optl[l + 1][i] = optl[l][optl[l + 1][i]];
          if (optl[l + 1][i]) {
            costl[l + 1][i] += costl[l][optl[l + 1][i]];
            optl[l + 1][i] = optl[l][optl[l + 1][i]];
          }
        }
      }
    }
  }

  {
    memset(costr, 63, sizeof costr);
    costr[0][n + 1] = 0;
    optr[0][n + 1] = n + 1;
    for (int i = n; i > -1; --i) {
      if (minb(costr[0][i], costr[0][i + 1] + a[i])) {
        optr[0][i] = i + 1;
      }
      if (minb(costr[0][i], costr[0][nxt[i]] + b[i])) {
        optr[0][i] = nxt[i];
      }
      sum += optr[0][i];
    }
    for (int i = 0; i <= n; ++i) {
      costr[0][i] -= costr[0][optr[0][i]];
    }
    for (int l = 0; l < L - 1; ++l)
    for (int i = 0; i <= n + 1; ++i) {
      costr[l + 1][i] = costr[l][i];
      optr[l + 1][i] = optr[l][i];
      if (optr[l + 1][i] != n + 1) {
        costr[l + 1][i] += costr[l][optr[l + 1][i]];
        optr[l + 1][i] = optr[l][optr[l + 1][i]];
        if (optr[l + 1][i] != n + 1) {
          costr[l + 1][i] += costr[l][optr[l + 1][i]];
          optr[l + 1][i] = optr[l][optr[l + 1][i]];
          if (optr[l + 1][i] != n + 1) {
            costr[l + 1][i] += costr[l][optr[l + 1][i]];
            optr[l + 1][i] = optr[l][optr[l + 1][i]];
          }
        }
      }
    }
  }

  sum = sum < 0;
  int64_t s = req[n + 1] = cost(sum, 0, n + 1);
  req[0] = 0;
  while (q--) {
    int x = $;
    if (auto it = req.lower_bound(x); it->first == x) {
      s -= it->second;
      it = req.erase(it);
      s += change(it->second, cost(sum, prev(it)->first, it->first));
    } else {
      s += change(it->second, cost(sum, x, it->first));
      s += req.emplace_hint(it, x, cost(sum, prev(it)->first, x))->second;
    }
    print(s);
  }
}
;