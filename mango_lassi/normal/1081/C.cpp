#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

const int N = 2000;
const int K = 2000;
ll choose[N+1][N+1];
ll cpow[K+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	choose[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % MOD;
		}
	}

	cpow[0] = 1;
	for (int j = 1; j <= k; ++j) {
		cpow[j] = (cpow[j-1] * (m-1)) % MOD;
	}

	ll res = (cpow[k] * choose[n-1][k]) % MOD;
	res = (res * m) % MOD;
	cout << res << '\n';
}