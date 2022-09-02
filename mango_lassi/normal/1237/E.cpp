#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int D = 22;
const int K = 2;
int cou[D][K][2]; // count of valid with depth D, size N, and odd size right child
int as[D];

ll ask(int d, int n, int p) {
	if (n < as[d] || as[d]+1 < n) return 0;
	else return cou[d][n - as[d]][p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	as[0] = 0;
	cou[0][0][0] = 1;
	cou[0][1][0] = 1;
	for (int d = 1; d < D; ++d) {
		as[d] = MOD;
		for (int x = as[d-1]; x < as[d-1] + K; ++x) {
			for (int y = as[d-1]; y < as[d-1] + K; ++y) {
				int off = x + y + 1;
				ll add = ask(d-1, x, 0) * ask(d-1, y, y & 1) % MOD;
				if (add > 0) as[d] = min(as[d], off);
			}
		}
		for (int x = as[d-1]; x < as[d-1] + K; ++x) {
			for (int y = as[d-1]; y < as[d-1] + K; ++y) {
				int off = x + y + 1;
				ll add = ask(d-1, x, 0) * ask(d-1, y, y & 1) % MOD;
				if (add > 0) cou[d][off - as[d]][y & 1] = (cou[d][off - as[d]][y & 1] + add) % MOD;
			}
		}
	}

	//      6
	//   3     8
	//  2  5  7  10
	// 1  4     9

	int n;
	cin >> n;

	int d = 0;
	while((1<<(d+1)) - 1 < n) ++d;
	
	ll res = ask(d, n, 0) + ask(d, n, 1);
	cout << res % MOD << '\n';
}