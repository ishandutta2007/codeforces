#include <iostream>
#include <map>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

void extract(auto& m, char c, int am = 1) {
  if (!(m[c] -= am)) {
    m.erase(c);
  }
  cout << string(am, c);
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    map<char, int> m;
    int n;
    int mam = 1e9, mc;
    {
      string s = $;
      n = s.size();
      for (auto c: s) {
        ++m[c];
      }
    }
    for (auto [c, a]: m) {
      if (minb(mam, a)) {
        mc = c;
      }
//      s.emplace(a, c);
    }
    if (m.size() == 1) {
    } else if (mam == 1) {
      extract(m, mc);
    } else if (m.begin()->second * 2 - 2 <= n) {
      char f = m.begin()->first;
      extract(m, f, 2);
      while (m.begin()->first == f) {
        extract(m, next(m.begin())->first);
        extract(m, f);
      }
    } else if (char f = m.begin()->first, s = next(m.begin())->first; m.size() == 2) {
      extract(m, f);
      extract(m, s, m[s]);
    } else {
      extract(m, f);
      extract(m, s);
      extract(m, f, m[f]);
      extract(m, next(m.begin())->first);
    }
    for (auto [c, a]: m) {
      cout << string(a, c);
    }
    print();
  }
}