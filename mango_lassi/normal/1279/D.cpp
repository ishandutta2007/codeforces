#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int M = 1e6;
ll weight[M];
int cou[M];

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b^1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll inv = modPow(n, MOD - 2);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		ll v = modPow(k, MOD - 2) * inv % MOD;
		for (; k; --k) {
			int a;
			cin >> a;
			--a;
			weight[a] = (weight[a] + v) % MOD;
			cou[a] += 1;
		}
	}
	ll res = 0;
	for (int j = 0; j < M; ++j) {
		ll mult = cou[j] * inv % MOD;
		res = (res + weight[j] * mult) % MOD;
	}
	cout << res << '\n';
}