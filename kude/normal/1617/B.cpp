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
    if (n % 2 == 0) {
      int c = 1;
      n--;
      int a = n / 2, b = n - a;
      cout << a << ' ' << b << ' ' << c << '\n';
    } else {
      int c = 1;
      n--;
      int n2 = n / 2;
      int a = n2 - 1, b = n2 + 1;
      if (a % 2 == 0) a--, b++;
      cout << a << ' ' << b << ' ' << c << '\n';
    }
  }
}