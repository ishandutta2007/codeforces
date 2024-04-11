/**
 *    author:  Mohamed Abo_Okail
 *    created: 1O/O2/2O2O
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
		ll n; cin >> n; n *= 2;
		vector < ll > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << v[n / 2] - v[n / 2 - 1] << o_o;
	}
}