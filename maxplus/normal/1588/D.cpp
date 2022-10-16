//#pragma GCC optimize "tree-vectorize"
#include <iostream>
#pragma GCC target "arch=skylake"
#include <algorithm>
#include <vector>
#include <array>
#include <cstring>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int A = 52, N = 10, M = 1 << N;

int cnt[A][N], fnd[A][N], rfnd[A][N], mcnt[A], cmask[A], mmask[A][M][A];
bool ok[A][M][A];
string ans[A][M];

int c2i(char c) {
  return c >= 'a'? A / 2 + c - 'a': c - 'A';
}

char i2c(int c) {
  return c >= A / 2? c - A / 2 + 'a': c + 'A';
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = 1 << n;
    vector<string> v(n);
    cin >> v;
    memset(cnt, 0, sizeof cnt);
    memset(cmask, 0, sizeof cmask);
    memset(ok, 1, sizeof ok);
    for (int i = 0; i < n; ++i)
    for (auto c: v[i]) {
      ++cnt[c2i(c)][i];
    }
    for (int c = 0; c < A; ++c) {
      mcnt[c] = *min_element(cnt[c], cnt[c] + n);
    }
    for (int i = 0; i < n; ++i) {
      auto r = v[i].begin(), w = r, e = v[i].end();
      do if (mcnt[c2i(*r)]) {
        *w++ = *r;
      } while (++r != e);
      v[i].erase(w, v[i].end());
      for (int c = 0; c < A; ++c) {
        fnd[c][i] = v[i].find(i2c(c));
        rfnd[c][i] = v[i].rfind(i2c(c));
      }
    }
    for (int c = 0; c < A; ++c)
    for (int mask = 0; mask < m; ++mask)
    for (int d = (ans[c][mask].clear(), 0); d < A; ++d)
    for (int i = (mmask[c][mask][d] = m - 1, 0); i < n; ++i) {
      uint32_t pos;
      if (mask & 1 << i) {
        if (cnt[c][i] != 2) {
          ok[c][mask][d] = 0;
          break;
        }
        pos = rfnd[c][i];
      } else {
        pos = fnd[c][i];
      }
      if (fnd[d][i] >= pos) {
        ok[c][mask][d] = 0;
        break;
      }
      if (cnt[d][i] != 2 || rfnd[d][i] >= pos) {
        mmask[c][mask][d] &= ~(1 << i);
      }
    }
    string lans;
    for (int c = 0; c < A; ++c) if (mcnt[c]) {
      for (int i = n - 1; i > -1; --i) {
        (cmask[c] *= 2) += cnt[c][i] == 2;
      }
      for (int mask = cmask[c]; ; mask = (mask - 1) & cmask[c]) {
        ans[c][mask] = lans = i2c(c);
        if (!mask) {
          break;
        }
      }
    }
    for (int i = 0; i < v[0].size(); ++i)
    for (int mask = 0, ci = c2i(v[0][i]); mask < m; ++mask)
    for (int j = 0; j < i; ++j) if (int cj = c2i(v[0][j]); ok[ci][mask][cj]) {
      if (ans[ci][mask].size() <= ans[cj][mmask[ci][mask][cj]].size()) {
        auto upd = ans[cj][mmask[ci][mask][cj]] + v[0][i];
        if (lans.size() < upd.size()) {
          lans = upd;
        }
        upd.swap(ans[ci][mask]);
      }
    }
    prints(lans);
  }
}