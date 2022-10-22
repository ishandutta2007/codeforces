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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    VI ds, dt;
    string sr, tr;
    rep(_, 2) {
      int now = 0;
      for(char c: s) {
        if (c == 'b') now++;
        else {
          ds.emplace_back(now);
          sr += c;
          now = 0;
        }
      }
      ds.emplace_back(now);
      swap(s, t);
      swap(ds, dt);
      swap(sr, tr);
    }
    if (sr != tr) {
      cout << "NO\n";
      continue;
    }
    int m = sr.size();
    rep(i, m) {
      ds[i+1] += ds[i];
      dt[i+1] += dt[i];
    }
    bool ok = true;
    rep(i, m) {
      if (sr[i] == 'a') {
        if (ds[i] > dt[i]) {
          ok = false;
        }
      } else {
        if (ds[i] < dt[i]) {
          ok = false;
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}