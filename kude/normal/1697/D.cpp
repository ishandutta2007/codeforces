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

int ask1(int i) {
  cout << "? 1 " << i + 1 << endl;
  char res;
  cin >> res;
  return res;
}

int ask2(int l, int r) {
  cout << "? 2 " << l + 1 << ' ' << r << endl;
  int res;
  cin >> res;
  return res;
}

void answer(const string& ans) {
  cout << "! " << ans << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string ans;
  vector<pair<char, int>> lasts;
  rep(i, n) {
    int sz = lasts.size();
    int l = -1, r = sz;
    while(r - l > 1) {
      int c = (r + l) / 2;
      int res = ask2(lasts[c].second, i + 1);
      if (res == sz - c) {
        l = c;
      } else {
        r = c;
      }
    }
    if (l == -1) {
      char c = ask1(i);
      ans += c;
      lasts.emplace_back(c, i);
    } else {
      char c = lasts[l].first;
      ans += c;
      lasts.erase(lasts.begin() + l);
      lasts.emplace_back(c, i);
    }
  }
  answer(ans);
}