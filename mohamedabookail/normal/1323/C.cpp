/**
 *    author:  Mohamed Abo_Okail
 *    created: O8/O3/2O2O
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
	ll n; string s; cin >> n >> s;
	ll a = 0, b = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == ')') a++;
		else b++;
	}
	if(n % 2 || a != b) return cout << -1 << o_o, 0;
	a = 0, b = 0; int inx1 = 0, inx2 = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '(') {
			a++;
			inx1 = i;
		}
		else {
			b++;
			inx2 = i;
		}
		if(a == b) {
			if(inx2 < inx1) ans += a * 2;
			a = 0; b = 0;
		}
	}
	cout << ans << o_o;
}