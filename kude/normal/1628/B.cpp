#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    bool ok = false;
    for(string si : s) {
      if (si.size() == 1 ||
         (si.size() == 2 && si[0] == si[1]) ||
         (si.size() == 3 && si[0] == si[2])) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
      continue;
    }
    set<string> seen2, seen3, seen33;
    for(string si: s)  {
      if (si.size() == 2) {
        swap(si[0], si[1]);
        if (seen2.count(si) || seen3.count(si)) {
          ok = true;
          break;
        }
        swap(si[0], si[1]);
        seen2.emplace(si);
      } else {
        string t;
        t += si[2];
        t += si[1];
        if (seen2.count(t)) {
          ok = true;
          break;
        }
        swap(si[0], si[2]);
        if (seen33.count(si)) {
          ok = true;
          break;
        }
        swap(si[0], si[2]);
        seen33.emplace(si);

        si.pop_back();
        seen3.emplace(si);
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}