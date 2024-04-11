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
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    string s = $, t = $;
    int i = s.size() - 1, j = t.size() - 1;
    while (i > -1 && j > -1) {
      if (s[i] == t[j]) {
        --i, --j;
      } else {
        ----i;
      }
    }
    cout << (j == -1? "YES\n": "NO\n");
  }
}