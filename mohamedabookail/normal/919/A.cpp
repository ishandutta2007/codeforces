/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define line "\n"
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
	double ans = 1e9;
	for (int i = 0; i < n; i++) {
		double a, b; cin >> a >> b;
		double flag = m / b * a;
		ans = min(ans, flag);
	}
	cout << fixed << setprecision(8) << ans << line;
}