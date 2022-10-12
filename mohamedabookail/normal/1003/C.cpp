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
	int n, k; cin >> n >> k;
	vector < double > v(n);
	double ans = 0.00;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		int cnt = 0;
		for (int j = i; j < n; j++) {
			sum += v[j];
			cnt ++;
			if(cnt >= k) ans = max(ans, sum / cnt); 
		}
	}
	cout << fixed << setprecision(15) << ans << endl;
}