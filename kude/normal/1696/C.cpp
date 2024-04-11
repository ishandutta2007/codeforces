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
void rle_push_back(vector<pair<T, ll>>& a, pair<T, ll> vl) {
  if (!a.empty() && a.back().first == vl.first) a.back().second += vl.second;
  else a.emplace_back(vl);
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> a, b;
    rep(i, n) {
      int x;
      cin >> x;
      ll cnt = 1;
      while(x % m == 0) x /= m, cnt *= m;
      rle_push_back(a, pair(x, cnt));
    }
    int k;
    cin >> k;
    rep(i, k) {
      int x;
      cin >> x;
      ll cnt = 1;
      while(x % m == 0) x /= m, cnt *= m;
      rle_push_back(b, pair(x, cnt));
    }
    cout << (a == b ? "YES\n" : "NO\n");
  }
}