#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1e5;
ll height[N+2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	ll l;
	cin >> n >> m >> l;

	height[0] = -1;
	height[n+1] = -1;
	for (int i = 1; i <= n; ++i) cin >> height[i];

	int base = 0;
	for (int i = 1; i <= n; ++i) {
		if (height[i] > l && height[i-1] <= l) ++base;
	}

	for (int q = 0; q < m; ++q) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << base << '\n';
		} else {
			int x, d;
			cin >> x >> d;
			if (height[x] <= l && height[x]+d > l) {
				bool le = (height[x-1] <= l);
				bool ri = (height[x+1] <= l);
				if (le && ri) ++base;
				if ((!le) && (!ri)) --base;
			}
			height[x] += d;
		}
	}
}