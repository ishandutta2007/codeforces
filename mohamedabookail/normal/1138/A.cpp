/**
 *    author:  Mohamed Abo_Okail
 *    created: 2O/O3/2O2O
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
	int n; cin >> n;
	vector < int > v(n);
	ll ans = -1, cntA = 0, cntB = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if(v[0] == 1) cntA++; else cntB++;
	for (int i = 1; i < n; i++) {
		if(v[i] != v[i - 1] && cntA && cntB) {
			ans = max(ans, min(cntA, cntB) * 2);
			if(v[i] == 1) cntA = 0;
			else cntB = 0;
		}
		if(v[i] == 1) cntA++;
		else cntB++;
	}
	ans = max(ans, min(cntA, cntB) * 2);
	cout << ans << o_o;
}