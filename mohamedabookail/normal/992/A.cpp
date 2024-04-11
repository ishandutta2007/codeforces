/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O4/2O2O
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
	ll sm = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if(v[i]) {
			v[i] += sm;
			if(v[i] > 0) sm -= v[i], cnt++;
			if(v[i] < 0) sm -= v[i], cnt++;
		}
	}
	cout << cnt << o_o;
}