#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

ll capAdd(ll n, ll k, ll m) {
	return min(n*k, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, m;
	cin >> n >> k >> m;

	vector<int> power(n);
	for (int i = 0; i < n; ++i) cin >> power[i];
	sort(power.begin(), power.end());

	ld ans = 0;

	ll sum = 0;
	for (int i = 0; i < n; ++i) sum += power[i];
	ans = max(ans, ((ld)sum + capAdd(n, k, m)) / n);

	for (int i = 1; i < min(n, m+1); ++i) {
		sum -= power[i-1];
		ans = max(ans, ((ld)sum + capAdd(n-i, k, m-i)) / (n-i));
	}

	cout << fixed << setprecision(20) << ans << '\n';
}