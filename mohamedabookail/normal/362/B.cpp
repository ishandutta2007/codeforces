/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
	int n, m; cin >> n >> m;
	vector < int > v(m);
	int mx = -1, cur = 1, flag = 1;
	for (int i = 0; i < m; i++) {
		cin >> v[i];
		if(v[i] == 1 || v[i] == n) flag = 0;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < m; i++) {
		if(v[i] - v[i - 1] == 1) cur++;
		else cur = 1;
		mx = max(mx, cur);
	}
	cout << (mx > 2 || !flag ? "NO" : "YES") << endl;
}