/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		ll ans = 0, cnt = 0, x = 1;
		while(ans < n) {
			if(ans + x > n) break;
			ans += x;
			x += 2;
			cnt++;
		}
		ll f = n - ans;
		if(cnt == k && f % 2) cout << "NO";
		else if(cnt == k && !(f % 2)) cout << "YES";
		else if(cnt < k) cout << "NO";
		else {
			ll a = cnt - k;
			if(a % 2 && f % 2) cout << "YES";
			else if(!(a % 2) && !(f % 2)) cout << "YES";
			else cout << "NO";
		}
		cout << o_o;
	}
}