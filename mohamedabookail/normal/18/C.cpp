/**
*    author:  Mohamed Abo_Okail
*    created: 24/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < int > v(n);
	int cnt = 0, sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum2 += v[i];
	}
	for (int i = 0; i < n - 1; i++) {
		sum1 += v[i];
		sum2 -= v[i];
		if(sum1 == sum2) cnt ++;
	}
	cout << cnt << endl;
}