/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O3/2O2O
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
	int w, h; cin >> w >> h;
	int a1, b1; cin >> a1 >> b1;
	int a2, b2; cin >> a2 >> b2;
	int ans = w;
	if(b1 < b2) {
		swap(b1, b2);
		swap(a1, a2);
	}
	for (int i = h; i > 0; i--) {
		if(i != b1 && i != b2) {
			ans += i;
		}
		if(i == b1) {
			ans += i;
			ans -= a1;
			ans = max(ans, 0);
		}
		if(i == b2) {
			if(i == b1) ans -= i;
			ans += i;
			ans -= a2;
			ans = max(ans, 0);
		} 
	}
	cout << ans << o_o;
}