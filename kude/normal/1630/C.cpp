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
  int n;
  cin >> n;
  VI a(n);
  rep(i, n) cin >> a[i], a[i]--;
  VI pos_last(n, -1);
  rep(i, n) pos_last[a[i]] = i;
  int ans = 0;
  int nxt = 0;
  for(int i = 0; i < n;) {
    int j = nxt;
    ans++;
    nxt = j + 1;
    while(i <= j) chmax(nxt, pos_last[a[i++]]);
  }
  cout << n - ans << '\n';
}