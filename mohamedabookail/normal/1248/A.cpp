/**
 *    author:  Mohamed Abo_Okail
 *    created: 27/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			if(oo % 2) { a++; }
		}
		ll m; cin >> m;
		ll c = 0, d = 0;
		for (int i = 0; i < m; i++) {
			int oo; cin >> oo;
			if(oo % 2) { c++; }
		}
		b = n - a; d = m - c;
		cout << (a * c) + (b * d) << o_o;
	}
}