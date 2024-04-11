#include <iostream>

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

int mex(int n, int m) {
  int b = 1 << 31 - __builtin_clz(n | m);
  if (m & b) {
    return ~n & b | mex(n & ~b, m & ~b);
  } else {
    return 0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $;
    cout << mex(n, $ + 1) << '\n';
  }
}