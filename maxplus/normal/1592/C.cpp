#include <iostream>
#include <vector>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} It begin() const { return first; } It end() const { return last; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e5;

int a[N], x;
vector<int> nei[N];

pair<int, int> subtree_x(int v, int p) {
  int x = a[v], c = 0;
  for (auto u: nei[v]) if (u != p) {
    auto [ux, uc] = subtree_x(u, v);
    x ^= ux;
    c += uc;
  }
  nei[v].clear();
  return {x, maxi(c += c && !x, x == ::x)};
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, k = $;
    x = 0;
    for (int i = 0; i < n; ++i) {
      x ^= a[i] = $;
    }
    for (int i = 1; i < n; ++i) {
      int u = $ - 1, v = $ - 1;
      nei[u].push_back(v);
      nei[v].push_back(u);
    }
    auto [_, c] = subtree_x(0, 0);
    cout << (x == 0 || c > 1 && k > 2? "YES": "NO") << '\n';
  }
}