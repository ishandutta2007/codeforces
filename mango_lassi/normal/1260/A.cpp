#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int c, s;
		cin >> c >> s;
		// x^2 convex, Optimal to use same size for all
		int k = s / c;
		int res = (k+1)*(k+1) * (s % c) + k*k * (c - (s % c));
		cout << res << '\n';
	}
}