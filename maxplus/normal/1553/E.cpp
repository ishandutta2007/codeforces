#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

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

constexpr int N = 3e5;

int p[N], s[N];
int f[N];

bool verify(int n, int m, int k) {
  rotate(p, p + k, p + n);
  memset(f, 0, n * sizeof *f);
  int c = 0;
  for (int i = 0; i < n; ++i) if (!f[i]) {
    for (int j = i; !f[j]++; j = p[j]) {
    }
    ++c;
  }
  rotate(p, p + n - k, p + n);
  return m >= n - c;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  vector<int> ans;
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = $;
    ans.clear();
    memset(s, 0, n * sizeof *s);
    for (int i = 0; i < n; ++i) {
      p[i] = $ - 1;
      ++s[(i - p[i] + n) % n];
    }
    for (int i = 0; i < n; ++i) if (s[i] >= n - 2 * m && verify(n, m, i)) {
      ans.push_back(i);
    }
    cout << ans.size();
    for (auto i: ans) {
      cout << ' ' << i;
    }
    cout << '\n';
  }
}