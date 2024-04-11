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

bool solve() {
  int n, c;
  cin >> n >> c;
  vector<char> x(c + 1);
  rep(i, n) {
    int ai;
    cin >> ai;
    x[ai] = true;
  }
  if (!x[1]) return false;
  VI d(c + 2);
  for(int i = 1; i <= c; i++) {
    if (x[i]) {
      if (d[i]) return false;
      for(int j = i, q = 1; j <= c; j += i, q++) {
        if (!x[q]) {
          d[j]++;
          d[min(c + 1, j + i)]--;
        }
      }
    }

    d[i + 1] += d[i];
  }
  return true;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cout << (solve() ? "Yes\n" : "No\n");
  }
}