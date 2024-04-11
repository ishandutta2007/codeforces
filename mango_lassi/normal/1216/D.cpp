#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	sort(as.begin(), as.end());

	int k = 0;
	for (int i = 0; i < n; ++i) {
		as[i] = as[n-1] - as[i];
		k = gcd(k, as[i]);
	}
	ll cou = 0;
	for (int i = 0; i < n; ++i) {
		cou += as[i] / k;
	}
	cout << cou << ' ' << k << '\n';
}