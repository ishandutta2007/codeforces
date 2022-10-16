#include <iostream>
#include <unordered_map>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { using X = int; template <typename T = X> auto operator ()() const { T t; cin >> t; return t; } operator X() const { return this->operator()<X>(); } template <typename T> operator T() const { return this->operator()<T>(); } } $;
template <typename T, typename S> bool mini(T& a, const S& b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, const S& b) { return a < b? a = b, 1: 0; }
template <typename T> T unneg(T a) { return max(T{}, a); }

pair<string, char> solve(int n) {
  string s;
  char c, d;
  switch (n % 3) {
  case 0:
    if (n == 0) {
      return {"", 'a'};
    } else if (n == 3) {
      return {"abc", 'd'};
    } else if (n == 6) {
      return {"aabacd", 'e'};
    }
    tie(s, c) = solve(n / 3 - 2);
    d = c + 1;
    return {s + c + d + d + s + d + c + c + s, c + 2};
  case 1:
    if (n == 1) {
      return {"a", 'b'};
    } else if (n == 4) {
      return {"aaba", 'c'};
    } else if (n == 7) {
      return {"aabacbb", 'd'};
    } else if (n == 10) {
      return {"aabacbbccd", 'e'};
    }
    tie(s, c) = solve(n / 3 - 3);
    d = c + 1;
    return {""s + c + d + s + c + d + c + d + s + c + d + s + c + d, c + 2};
  default:
    if (n == 2) {
      return {"ab", 'c'};
    }
    tie(s, c) = solve(n / 3);
    return {s + c + s + char(c + 1) + s, c + 2};
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    cout << solve($).first << '\n';
  }
}