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
  int n; cin >> n;
  vector < ll > a(n), b(n);
  ll ans = 0, mod = 1e4 + 7;
  for(int i = 0; i < n; i++) {
    cin >> a[i]; b[i] = a[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  for(int i = 0; i < n; i++) {
    ans += a[i] * b[i];
    ans %= mod;
  }
  cout << ans << endl;
}