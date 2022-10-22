#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

template <class T>
vector<int> KMP(const T& pattern) {
  const int n = pattern.size();
  vector<int> pi(n + 1);
  pi[0] = -1;
  int border = 0;
  for (int i = 1; i < n; i++, border++) {
    const auto c = pattern[i];
    if (pattern[border] == c) {
      pi[i] = pi[border];
    } else {
      pi[i] = border;
      while (border != -1 && pattern[border] != c) {
        border = pi[border];
      }
    }
  }
  pi[n] = border;
  return pi;
}

template <class T>
vector<int> MP(const T& pattern) {
  const int n = pattern.size();
  vector<int> pi(n + 1);
  pi[0] = -1;
  int border = 0;
  for (int i = 1; i < n; i++, border++) {
    const auto c = pattern[i];
    pi[i] = border;
    while (border != -1 && pattern[border] != c) {
      border = pi[border];
    }
  }
  pi[n] = border;
  return pi;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s_str;
  cin >> s_str;
  vector<char> s(all(s_str));
  int n = s.size();
  const int border_n = MP(s)[n];
  VI pi = KMP(s);
  const int strict_border_n = pi[n];
  int q;
  cin >> q;
  while(q--) {
    string t_str;
    cin >> t_str;
    s.insert(s.end(), all(t_str));
    int m = t_str.size();
    pi.resize(n + m + 1);
    int strict_border = pi[n];
    for(int i = n; i < n + m; i++, strict_border++) {
      const auto c = s[i];
      if (s[strict_border] == c) {
        pi[i] = pi[strict_border];
      } else {
        pi[i] = strict_border;
        while (strict_border != -1 && s[strict_border] != c) {
          strict_border = pi[strict_border];
        }
      }
    }
    pi[n + m] = strict_border;
    int border = border_n;
    for(int i = n; i < n + m; i++) {
      char c = s[i];
      while(border != -1 && s[border] != c) border = pi[border];
      border++;
      cout << border << " \n"[i + 1 == n + m];
    }
    s.resize(n);
    pi.resize(n + 1);
    pi[n] = strict_border_n;
  }
}