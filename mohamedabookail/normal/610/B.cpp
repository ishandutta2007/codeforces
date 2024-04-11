/**
 *    author:  Mohamed Abo_Okail
 *    created: O5/O4/2O2O
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
	ll n; cin >> n;
	vector < ll > v(n);
	ll mn = 1e9, ans = 0, mx = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if(v[i] <= mn) mn = v[i];
	}
	ans = mn * n;
	for (int i = 0; i < n; i++) {
		v[i] -= mn;
	}
	for (int i = 0; i < n; i++) {
		if(v[i]) cnt++;
		else break;
	}
	for (int i = n - 1; i >= 0 ; i--) {
		if(v[i]) cnt++;
		else break;
	}
	mx = max(mx, cnt); cnt = 0;
	for (int i = 0; i < n; i++) {
		if(v[i]) cnt++;
		else mx = max(mx, cnt), cnt = 0;
	}
	ans += mx;
	cout << ans << o_o;
}