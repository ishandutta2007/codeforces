/**
 *    author:  Mohamed Abo_Okail
 *    created: O2/O3/2O2O
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
	int sumA = 0, sumB = 0, cntA = 0, cntB = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sumA += v[i];
	}
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		sumB += oo;
		if(v[i] == oo) cntA++;
		if(v[i] && !oo) cntB++;
	}
	if(sumA > sumB) cout << 1;
	else if(cntA == n || sumB == n || !cntB) cout << -1;
	else cout << (sumB - sumA + cntB) / cntB + 1;
	cout << o_o;
}