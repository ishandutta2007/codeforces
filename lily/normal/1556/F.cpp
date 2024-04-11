#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
const int N = 15;

LL power (LL x, LL y) {
	LL ret = 1;
	for ( ; y ; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}
int n;
int a[N];
LL w[N][N], an[1 << N];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			w[i][j] = a[i] * power (a[i] + a[j], MOD - 2) % MOD;
		}
	}
	LL ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		vector <int> L, R;
		LL p = 1;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) L.push_back(j);
			else R.push_back(j);
		}
		for (auto j : L) {
			for (auto k : R) {
				p = p * w[j][k] % MOD; 
			}
		}
		LL q = 1;
		for (int j = 1; j < (1 << L.size()) - 1; j++) {
			int ss = 0;
			vector <int> U, V;
			for (int k = 0; k < L.size(); k++) {
				if ((j >> k) & 1) U.push_back(L[k]), ss |= 1 << L[k];
				else V.push_back(L[k]);
			}
			LL now = 1;
			for (auto j : U) {
				for (auto k : V) {
					now = now * w[j][k] % MOD;
				}
			}
			q = (q - an[ss] * now) % MOD;
		}
		p = p * q % MOD;
		an[i] = q;
		ans = (ans + p * (int)L.size()) % MOD;
	}
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
}