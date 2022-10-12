/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O2/2O2O
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
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > v(n);
		ll nemo = 0, mn = 1e8;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			if(v[i] > mn) nemo++;
			mn = min(mn, v[i]);
		}
		cout << nemo << o_o;
	}
}