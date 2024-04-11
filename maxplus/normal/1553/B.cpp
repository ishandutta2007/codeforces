#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { ((cout << ts << ' '), ...) << '\n'; }
auto& mini(auto& a, const auto& b) { return b < a? a = b: a; } bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; }
auto& maxi(auto& a, const auto& b) { return a < b? a = b: a; } bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; }
auto unneg(auto a) { return max(a, {}); }

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    string s = $, t = $, rs(s.rbegin(), s.rend());
    bool ok = 0;
    for (int i = 0; i < s.size() && !ok; ++i)
    for (int r = 0; i + r < s.size() && r < t.size() && !ok; ++r) {
      ok |= s.substr(i, r + 1) + rs.substr(s.size() - i - r, t.size() - r - 1) == t;
    }
    cout << (ok? "YES\n": "NO\n");
  }
}