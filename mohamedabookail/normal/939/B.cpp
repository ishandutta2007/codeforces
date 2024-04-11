/**
 *    author:  Mohamed Abo_Okail
 *    created: O9/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
	ll n, k; cin >> n >> k;
	ll ans = 0, ind = 0, flag = 1e18;
	for (int i = 0; i < k; i++) {
		ll oo; cin >> oo;
		if(n % oo < flag) {
			flag = n % oo;
			ans = n / oo;
			ind = (i + 1);
		}
	}
	cout << ind << ' ' << ans << endl;
}