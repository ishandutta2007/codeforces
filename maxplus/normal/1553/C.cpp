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

int solve(string s, int b = 0) {
  if (((int)s.size() + 1) / 2 + b < 0 || b - (int)s.size() / 2 > 0 || s.empty()) {
    return 0;
  }
  int res = s.size();
  if (s[0] == '0' || s[0] == '?') {
    mini(res, solve(s.substr(1), b));
  }
  if (s[0] == '1' || s[0] == '?') {
    mini(res, solve(s.substr(1), b + 2 * (s.size() & 1) - 1));
  }
  return res + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    cout << solve($) << '\n';
  }
}