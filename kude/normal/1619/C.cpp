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
    string a, s;
    cin >> a >> s;
    string b;
    int asz = a.size();
    int ssz = s.size();
    int p = ssz - 1;
    bool ok = true;
    rrep(i, asz) {
      int x = a[i] - '0';
      if (p < 0) {
        ok = false;
        break;
      }
      int z = s[p--] - '0';
      if (x <= z) {
        b += '0' + (z - x);
      } else {
        if (p < 0) {
          ok = false;
          break;
        }
        z = 10 * (s[p--] - '0') + z;
        int y = z - x;
        if (y < 0 || y >= 10) {
          ok = false;
          break;
        }
        b += '0' + y;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      while(p >= 0) b += s[p--];
      while(b.back() == '0') b.pop_back();
      reverse(all(b));
      cout << b << '\n';
    }
  }
}