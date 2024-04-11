/*
  Author: dendi239
  Time:   2021-10-07 18:12:18
*/

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")    // WINDOWS ONLY


#include <bits/stdc++.h>

#define requires(...) typename std::enable_if<__VA_ARGS__::value, int>::type = 0

using namespace std;

template<class U, class V>
istream &operator>>(istream &is, pair<U, V> &p) { return is >> p.first >> p.second; }

template<class U, class V>
ostream &operator<<(ostream &os, const pair<U, V> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<class Istream, class Container, requires(is_same<Istream, istream>)>
Istream &operator>>(Istream &is, Container &container) {
  for (auto &value : container) is >> value;
  return is;
}

template<class Ostream, class Container, requires(is_same<Ostream, ostream>)>
Ostream &operator<<(Ostream &os, const Container &container) {
  auto _begin = begin(container), _end = end(container);
  for (auto it = _begin; it != _end;)
  os << "{ "[it != _begin] << *it << ",}"[++it == _end];
  return os;
}

namespace io {
  template <class ...As> struct last {};
  template <class ...As> using last_t = typename last<As...>::type;
  template <class A> struct last<A> { using type = A; };
  template <class A, class ...As> struct last<A, As...> {
    using type = typename last<As...>::type;
  };

  template <class Z>
  Z read(Z z) { cin >> z; return z; }

  template <class A, class ...As>
  last_t<As...> read(A &a, As &...as) { return cin >> a, read(as...); }

  void log_rest() {}

  template <class A, class ...As>
  void log_rest(const A &a, const As &...as) { cerr << ", " << a; log_rest(as...); }

  template<class A, class ...As>
  void log(const string &pref, const A &a, const As &...as)
  { cerr << pref << a, log_rest(as...); }
}  // namespace io

#define A(xs) ::std::begin(xs), ::std::end(xs)
#define B(...) [&](auto &&lhs, auto &&rhs) { \
    return __VA_ARGS__;                      \
  }
#define U(...) [&](auto &&lhs, auto &&rhs) { \
  auto predicate = [&](auto &&x) {           \
    return __VA_ARGS__;                      \
  };                                         \
  return predicate(lhs) < predicate(rhs);    \
}
#define X  first
#define Y  second
#define PB push_back
#define EB emplace_back

#define R(...)        __VA_ARGS__ = io::read(__VA_ARGS__)
#define RC(name, ...) name(__VA_ARGS__); cin >> name

#define G3(_1, _2, _3, FUNC, ...) FUNC
#define F1(i, n)    for (typename remove_cv<decltype(n)>::type i = {}; i != n; ++i)
#define F2(i, a, b) for (typename common_type<decltype(a), decltype(b)>::type \
                         down = a > b, i = a - down; i + down != b;           \
                         down ? --i : ++i)

#define F(...) G3(__VA_ARGS__, F2, F1)(__VA_ARGS__)

#ifdef DEBUG
int recursion_depth = 0;
#  define D       for (bool _flag = true; _flag; _flag = !_flag)
#  define L(...)  (++recursion_depth,                  \
    io::log(string(recursion_depth - 1, '\t') +        \
        string(__func__) + ":" + to_string(__LINE__) + \
        " \t( "#__VA_ARGS__" ) := ",                   \
        __VA_ARGS__),                                  \
    --recursion_depth, cerr << "\n")
#  define dbg(...) [&](const string &func) -> auto && { \
      ++recursion_depth;                                \
      auto&& value = __VA_ARGS__;                       \
      --recursion_depth;                                \
      cerr << string(recursion_depth, '\t')             \
           << func << ":" << __LINE__                   \
           << " \t"#__VA_ARGS__" = " << value << endl;  \
      return forward<decltype(value)>(value);           \
    }(__func__)
#  define TEST(name)                    \
void test_##name();                     \
int test_result_##name = [] {           \
    test_##name();                      \
    cerr << #name" tests have passed!"  \
           << endl;                     \
    return 0;                           \
}();                                    \
void test_##name()
#else
#  define L(...)     while (false) cerr
#  define D          while (false)
#  define dbg(...)   (__VA_ARGS__)
#  define TEST(name) void test_##name()
#endif

template<class T>
T make_vec(T default_value) { return default_value; }

template<class T, class Arg, class ...Args>
auto make_vec(T default_value, Arg size, Args ...rest)
-> vector<decltype(make_vec(default_value, rest...))> {
  auto level = make_vec(default_value, rest...);
  return vector<decltype(level)>(size, level);
}

template<class Xs> int len(const Xs &xs) { return static_cast<int>(xs.size()); }

template <class T, class P>
auto bin_search(T l, T r, P p) -> T {
  for (T m; m = (l + r) / 2, m != l && m != r; (p(m) ? l : r) = m);
  return l;
}

using i64 = int64_t;
using f80 = long double;

using Str = string;
template<class T = int> using Vec = vector<T>;
template<class K = int, class H = hash<K>> using US = unordered_set<K, H>;
template<class K, class V, class H = hash<K>> using UM = unordered_map<K, V, H>;

template<class U = int, class V = U> using P = pair<U, V>;
using G = Vec<Vec<int>>;

constexpr int BLOCK_SIZE = 512;
const int max_n = 1000000000 / BLOCK_SIZE * BLOCK_SIZE;


//deque<bitset<BLOCK_SIZE>> sets{bitset<BLOCK_SIZE>{}};
bitset<max_n> bs;

int used = 0;
Vec<int> spare;
Vec<int> spare2;

struct Bitset {
  int index;
  bitset<BLOCK_SIZE>* cur_bs;

  Bitset() {
    if (spare.empty()) {
        sort(spare2.begin(), spare2.end());
        spare.swap(spare2);
    }
    if (spare.empty()) {
      exit(228);
    } else {
      index = spare.back();
      spare.pop_back();
      cur_bs = reinterpret_cast<bitset<BLOCK_SIZE>*>((char*)(&bs) + (BLOCK_SIZE * index) / 8);
    }
  }

  ~Bitset() noexcept {
    spare2.PB(index);
  }

  void insert(int value) {
    cur_bs->set(value);
  }

  void erase(int value) {
    cur_bs->reset(value);
  }

  bool empty() const {
    return !cur_bs->any();
  }

  int min() const {
    if (!cur_bs->any()) return -1;
    F(i, BLOCK_SIZE) {
      if (cur_bs->test(i)) {
        return i;
      }
    }
  }

  int max() const {
    if (!cur_bs->any()) return -1;
    F(i, BLOCK_SIZE, 0) {
      if (cur_bs->test(i)) {
        return i;
      }
    }
  }
};


struct Block {
  i64 shift = 0;
  UM<i64, Bitset> ids;
  Vec<i64> values;

  template <class It>
  Block(It begin, It end) : values(begin, end) {
    ids.reserve(4 * len(values));
    F(i, len(values)) {
      ids[values[i]].insert(i);
    }
  }

  int size() const {
    return len(values);
  }

  void add_all(i64 diff) {
    shift += diff;
  }

  void add(int diff, int l, int r) {
    F(i, l, r) {
      ids[values[i]].erase(i);
      if (ids[values[i]].empty()) {
        //spare.PB(ids[values[i]].index);
        ids.erase(values[i]);
      }

      values[i] += diff;
      ids[values[i]].insert(i);
    }
  }

  int left(i64 value) {
    value -= shift;
    if (!ids.count(value)) return -1;
    return ids[value].min();
  }

  int right(i64 value) {
    value -= shift;
    if (!ids.count(value)) return -1;
    return ids[value].max();
  }
};

int main() {
  for (int i = 0; i < max_n; i += BLOCK_SIZE) {
    spare.push_back(i / BLOCK_SIZE);
  }
  int R(n, q);
  Vec<i64> RC(as, n);

  Vec<Block> blocks;

  const int block_size = BLOCK_SIZE;// min(2048, max(1, int(sqrt(10 * n))));
  Vec<int> limits;

  /*

   get: block_count * log(block_size)
   add: block_count + block_size * log(block_size)

   */

  for (int i = 0; i < n; i += block_size) {
    blocks.emplace_back(as.begin() + i, as.begin() + min(i + block_size, n));
    limits.PB(i);
  }

  limits.PB(n);

  auto locate = [&](int i) -> P</*block, inside*/> {
    auto block_it = --upper_bound(A(limits), i);
    return P<>(block_it - limits.begin(), i - *block_it);
  };

  F(_, q) {
    int R(t);
    if (t == 1) {
      int R(l, r); --l;
      i64 R(x);

      auto s = locate(l), f = locate(r);
      if (s.X == f.X) {
        blocks[s.X].add(x, s.Y, f.Y);
      } else {
        blocks[s.X].add(x, s.Y, len(blocks[s.X]));
        blocks[f.X].add(x, 0, f.Y);

        F(i, s.X+1, f.X) {
          blocks[i].add_all(x);
        }
      }
    } else {
      i64 R(value);
      int begin = -1, end = -1;

      F(i, len(blocks)) {
        auto p = blocks[i].left(value);
        if (p != -1) {
          begin = p + limits[i];
          break;
        }
      }

      F(i, len(blocks), 0) {
        auto p = blocks[i].right(value);
        if (p != -1) {
          end = p + limits[i];
          break;
        }
      }

      if (begin == -1) {
        cout << "-1\n";
      } else {
        cout << end - begin << '\n';
      }
    }
  }
}

namespace {
auto fast_io = [] {
#ifndef DEBUG
#  ifndef INTERACTIVE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#  endif // INTERACTIVE
#  ifdef FILES
    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);
#  endif // FILES
#endif // DEBUG
    cout << setprecision(20) << fixed;
    cerr << boolalpha << setprecision(4) << fixed;

    return 0;
}();
} // namespace