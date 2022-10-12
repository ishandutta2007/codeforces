/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

ll _gcd(ll x, ll y) {
	return ((!y) ? x : _gcd(y, x % y));
} 

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vector < ll > v(n), ans;
	ll mx = -1, g = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	for (int i = 0; i < n; i++) {
		if(v[i] != mx) {
			ans.push_back(mx - v[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		g = _gcd(g, ans[i]);
		sum += ans[i];
	}
	cout << sum / g << ' ' << g << o_o;
}