/**
 *    author:  Mohamed Abo_Okail
 *    created: 1O/O4/2O2O
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
		int n, x; cin >> n >> x;
		vector < int > v(n);
		ll sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			sum += v[i];
			if(sum / (i + 1) >= x) cnt++;
		}
		cout << cnt << o_o;
	}
}