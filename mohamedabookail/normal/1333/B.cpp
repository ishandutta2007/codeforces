/**
 *    author:  Mohamed Abo_Okail
 *    created: O8/O4/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < int > a(n), b(n);
		bool bol = 1, bol1 = 0, bol2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			if(b[i] > a[i] && !bol1) bol = 0;
			if(b[i] < a[i] && !bol2) bol = 0;
			if(a[i] == 1) bol1 = 1;
			if(a[i] == -1) bol2 = 1;
		}
		cout << (bol ? "YES" : "NO") << o_o;
	}
}