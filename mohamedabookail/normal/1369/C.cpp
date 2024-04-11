/**
*    author:  Mohamed Abo_Okail
*    created: 23/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main() {
  std::ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t --) {
    ll n, k; cin >> n >> k;
    vector < ll > a(n), b;
    ll ans = 0, indx1 = 0, indx2 = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
      ll oo; cin >> oo;
      if(oo == 1) cnt ++;
      else b.push_back(oo);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    indx2 = n - cnt - 1;
    for(int i = sz(b) - 1; i >= 0; i--) {
      ans += a[indx2] + a[indx1];
      indx2 --;
      indx1 += b[i] - 1;
    }
    for(int i = n - cnt; i < n; i++) {
      ans += a[i] * 2;
    }
    cout << ans << endl;
  }
}