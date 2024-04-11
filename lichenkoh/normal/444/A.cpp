#include <iostream>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;

int main() {
	ll n, m;
	cin >> n;
	cin >> m;
	ll *x = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> x[i];
	}
	double ans = 0;
	for (ll i = 0; i < m; i++) {
		ll a,b;
		double c;
		cin >> a; cin >> b; cin >> c;
		double cand = ((double)(x[a] + x[b]))/c;
		ans = max(ans, cand);
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(100);
	cout << ans << endl;
}