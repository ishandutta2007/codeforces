#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { int operator ()() { return *this; } template <typename T> operator T() { T t; cin >> t; return t; } } $;
template <typename T, typename S> bool mini(T& a, S b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, S b) { return a < b? a = b, 1: 0; }
template <typename T> T unneg(T a) { return max(T{}, a); }

constexpr int N = 1e5;

int a[N], b[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, k = $, ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    iota(b, b + n, 0);
    sort(b, b + n, [](int x, int y) { return a[x] < a[y];});
    for (int i = 1; i < n; ++i) {
      ans += b[i] != b[i - 1] + 1;
    }
    cout << (ans < k? "Yes\n": "No\n");
  }
}