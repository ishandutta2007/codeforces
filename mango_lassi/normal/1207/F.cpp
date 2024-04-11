#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 5 * (int)1e5;
const int M = 1000;
ll dp[M+1][M];
ll vals[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			vals[x] += y;
			for (int m = 1; m <= M; ++m) {
				dp[m][x % m] += y;
			}
		} else if (t == 2) {
			if (x <= M) cout << dp[x][y] << '\n';
			else {
				ll res = 0;
				for (int i = y; i <= N; i += x) res += vals[i];
				cout << res << '\n';
			}
		}
	}
}