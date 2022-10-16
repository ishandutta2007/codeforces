#include <algorithm>
#include <iostream>

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

int a[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $;
    long double ans = -3e9;
    int64_t s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s += a[i];
    }
    sort(a, a + n);
    int64_t ps = 0;
    for (int i = 0; i < n - 1; ++i) {
      ps += a[i];
      maxi(ans, (s - ps) * 1.l / (n - i - 1) + ps * 1.l / (i + 1));
    }
    cout.precision(20);
    cout << ans << '\n';
  }
}