#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 1e5;

struct { int operator ()() { return *this; } template <typename T> operator T() { T t; cin >> t; return t; } } $;

template <typename T>
struct StdInterface {
  auto begin() const { return ibody().begin(); }
  auto rbegin() const { return ibody().rbegin(); }
  auto end() const { return ibody().end(); }
  auto rend() const { return ibody().rend(); }
  auto empty() const { return ibody().empty(); }
  auto size() const { return ibody().size(); }
  auto clear() { return ibody().clear(); }
  auto pop_back() { return ibody().pop_back(); }
  auto pop() { return ibody().pop(); }
  template <typename S> auto push_back(S&& s) { return ibody().push_back(forward<S>(s)); }
  template <typename S> auto push(S&& s) { return ibody().push(forward<S>(s)); }
  template <typename... S> auto emplace_back(S&&... s) { return ibody().emplace_back(forward<S>(s)...); }
  template <typename... S> auto emplace(S&&... s) { return ibody().emplace(forward<S>(s)...); }
  auto& operator[](int i) { return ibody()[i]; }
  const auto& operator[](int i) const { return ibody()[i]; }
  auto& back() { return ibody().back(); }
  const auto& back() const { return ibody().back(); }
  auto& top() { return ibody().top(); }
  const auto& top() const { return ibody().top(); }
  auto& front() { return ibody().front(); }
  const auto& front() const { return ibody().front(); }

private:
  auto& ibody() { return static_cast<T*>(this)->body(); }
  const auto& ibody() const { return static_cast<const T*>(this)->body(); }
};

#include <type_traits>
#include <functional>
#include <utility>
#include <vector>
template <int8_t NewestEqualIncreasing = 0, typename Key = int, typename Val = int>
struct MonotonicVector : StdInterface<MonotonicVector<NewestEqualIncreasing, Key, Val>> {
  using Entry = pair<Key, Val>;
  constexpr static bool Newest = NewestEqualIncreasing >> 2, Equal = NewestEqualIncreasing >> 1 & 1, Increasing = NewestEqualIncreasing & 1;
  using Cmp = conditional_t<Increasing, conditional_t<Equal, greater_equal<Val>, greater<Val>>, conditional_t<Equal, less_equal<Val>, less<Val>>>;

  bool emplace_back(Val val) { return emplace_back(counter++, val); }

  bool emplace_back(Key key, Val val) {
    if constexpr (Newest) {
      while (!this->empty() && !cmp(val, this->back().second)) {
        this->pop_back();
      }
    } else if (!this->empty() && !cmp(val, this->back().second)) {
      return 0;
    }
    v.emplace_back(key, val);
    return 1;
  }

  void clear() { return counter = 0, v.clear(); }

  auto& body() { return v; }
  const auto& body() const { return v; }

private:
  vector<Entry> v;
  Cmp cmp;
  int counter;
};

MonotonicVector<> a;
MonotonicVector<1> b;

template <typename T, typename S> bool mini(T& a, S b) { return static_cast<T>(b) < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, S b) { return a < static_cast<T>(b)? a = b, 1: 0; }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  for (int testcase = $; testcase--; ) {
    int n = $;
    a.clear(), b.clear();
    for (int i = 0; i < n; ++i) {
      a.emplace_back($);
    }
    for (int i = 0; i < n; ++i) {
      b.emplace_back($);
    }
    int ans = 1e9, i = a.size() - 1, j = 0;
    while (i > -1 && j < b.size()) {
      if (a[i].second < b[j].second) {
        mini(ans, a[i].first + b[j].first);
        --i;
      } else {
        ++j;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}