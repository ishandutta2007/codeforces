//#pragma GCC optimize "tree-vectorize"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <array>
#pragma GCC target "arch=skylake"

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

auto canonize(string s, int k) {
  vector<array<int, 2>> ops;
  int n = count(s.begin(), s.end(), '1');
  if (n < k || !k || n == s.size()) {
    return pair{s, ops};
  } else if (n == k) {
    int r = s.rfind('1');
    reverse(s.begin(), s.begin() + r + 1);
    ops.push_back({1, r + 1});
    r = s.rfind('1');
    auto s2 = s;
    reverse(s2.begin(), s2.begin() + r + 1);
    if (minb(s, s2)) {
      ops.push_back({1, r + 1});
    }
    return pair{s, ops};
  }
  int p = n;
  while (p > k) {
    int am = 0, r = s.size() - n + p, l = r;
    while (am < k) {
      am += s[--l] == '1';
    }
    reverse(s.begin() + l, s.begin() + r);
    ops.push_back({l + 1, r});
    --p;
  }
  for (int i = k % 2? k + 1: k / 2; i--; ) {
    int am = 1, l = s.find('1'), r = l;
    while (am <= k) {
      am += s[++r] == '1';
    }
    reverse(s.begin() + l, s.begin() + r);
    ops.push_back({l + 1, r});
    l = s.find('1', l) + 1;
    r = k % 2? n == k + 1? s.size(): s.find('1', r + 1): r + 1;
    reverse(s.begin() + l, s.begin() + r);
    ops.push_back({l + 1, r});
  }
  return pair{s, ops};
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, k = $;
    auto [s, sops] = canonize($, k);
    auto [t, tops] = canonize($, k);
    if (s != t) {
      print(-1);
    } else {
      copy(tops.rbegin(), tops.rend(), back_insert_iterator(sops));
      prints(sops);
    }
  }
}