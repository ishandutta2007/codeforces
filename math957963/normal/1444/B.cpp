#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	ll n;
	vector<ll>a;
	ll x, y, z, ans;
	ll re, rr;
	cin >> n;
	x = 1;
	for (ll i = 1; i <= n; i++) {
		x = (x*i) % MOD;
	}
	y = x;
	for (ll i = 1; i <= n; i++) {
		y = (y*(n + i)) % MOD;
	}
	re = MOD - 2;
	z = 1;
	rr = x;
	while (re > 0) {
		if (re % 2 == 1) {
			z = (z*rr) % MOD;
		}
		rr = (rr*rr) % MOD;
		re /= 2;
	}
	n *= 2;
	for (ll i = 1; i <= n; i++) {
		cin >> x;
		a.pb(x);
	}
	sort(all(a));
	n /= 2;
  ans=0;
	for (ll i = 0; i < n; i++) {
		ans = (ans + MOD + MOD - a[i]) % MOD;
		ans = (ans + a[n + i]) % MOD;
	}
	ans = (ans*y) % MOD;
	ans = (ans*z) % MOD;
	ans = (ans*z) % MOD;
    	cout << ans << endl;
	return 0;
}