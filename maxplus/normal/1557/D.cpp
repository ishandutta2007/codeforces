#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

struct UnsafeInput {
  static constexpr int bufsz = 1 << 17;

  UnsafeInput() {
//    freopen("out", "r", stdin);
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
  void operator()(Ts&... xs) {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr < '0') {
        ++b;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { int operator ()() { return *this; } template <typename T> operator T() { T t; reader(t); return t; } } $;
template <typename T, typename S> bool mini(T& a, const S& b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, const S& b) { return a < b? a = b, 1: 0; }
template <typename T> T unneg(T a) { return max(T{}, a); }

constexpr int N = 3e5;

template <typename Val = int, typename Tag = int> struct TaggedValue { Val val; Tag tag; constexpr TaggedValue(const Val& val = {}, const Tag& tag = {}) : val{val}, tag{tag} { } constexpr bool operator==(const TaggedValue& oth) const { return val == oth.val; } constexpr bool operator<(const TaggedValue& oth) const { return val < oth.val; } }; using Tagged = TaggedValue<>;

#include <type_traits>
#include <map>
struct SegmentMap {
  using T = int;
  using Val = Tagged;
  using MVal = pair<T, Val>;
  static constexpr Val default_val = {};

  template <typename It>
  void modify_key(It it, It next, T new_key) {
    auto node = m.extract(it);
    node.key() = new_key;
    m.insert(next, move(node));
  }

  void emplace(T l, T r, Val val) {
    auto it = m.upper_bound(l);
    while (it != m.end() && it->second.first <= r) {
      it = m.erase(it);
    }
    if (it != m.end() && it->first <= r) {
      if (it->second.second == val) {
        r = it->second.first;
        it = m.erase(it);
      } else if (it->first != r) {
        modify_key(it, next(it), r);
      }
    }
    if (it != m.begin()) if (auto prv = prev(it); prv->second.first >= l) {
      if (prv->second.second == val) {
        maxi(prv->second.first, r);
        return;
      } else if (prv->first != l) {
        if (prv->second.first > r) {
          it = m.emplace_hint(it, r, prv->second);
        }
        prv->second.first = l;
      } else if (prv->second.first > r) {
        modify_key(prv, it, r);
      } else {
        m.erase(prv);
      }
    }
    m.emplace_hint(it, l, MVal{r, val});
  }

  auto cquery(T l, T r) const {
    return query_impl(m, l, r);
  }

  auto dquery(T l, T r) {
    return query_impl(m, l, r);
  }

private:
  map<T, MVal> m;

  template <typename Map>
  static Val query_impl(Map& m, T l, T r) {
    auto it = m.lower_bound(l);
    auto res = default_val;
    if (it != m.begin()) if (auto prv = prev(it); prv->second.first > l) {
      maxi(res, prv->second.second);
    }
    while (it != m.end() && it->first < r) {
      maxi(res, it->second.second);
      if constexpr (!is_const_v<Map>) {
        if (it->second.first <= r) {
          it = m.erase(it);
        } else {
          ++it;
        }
      } else {
        ++it;
      }
    }
    return res;
  }
} sm;

vector<pair<int, int>> segments[N];
Tagged dp[N];

bool good[N];

int main() {
  int n = $, m = $;
  for (int i = 0; i < m; ++i) {
    int s = $, l = $, r = $;
    segments[s - 1].emplace_back(l, r + 1);
  }
  for (int i = 0; i < n; ++i) {
    for (auto& [l, r]: segments[i]) {
      maxi(dp[i], sm.dquery(l, r));
    }
    ++dp[i].val;
    for (auto [l, r]: segments[i]) {
      sm.emplace(l, r, {dp[i].val, i});
    }
  }
  auto last = max_element(dp, dp + n) - dp;
  cout << n - dp[last].val << '\n';
  for (int i = last; ; i = dp[i].tag) {
    good[i] = 1;
    if (dp[i].val == 1) {
      break;
    }
  }
  for (int i = 0; i < n; ++i) if (!good[i]) {
    cout << i + 1 << ' ';
  }
  cout << '\n';
}