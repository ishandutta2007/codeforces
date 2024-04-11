#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const ll INF = 3e18;

ll cc[11][70][1025];
vector<int> vv;

ll get(int k, int b, int m) {
	return cc[b][k][m];
}


ll get(ll x, ll b) {
	vv.clear();
	while (x)
		vv.push_back(x % b), x /= b;
	int k = vv.size() - 1;
	if (k % 2 == 1)
		--k;
	ll ans = 0;
	for (int i = 2; i <= k; i += 2)
		ans += get(i, b, 0) - get(i - 1, b, 1);
	int cur = 0;
	for (int i = vv.size() - 1; i >= 0; --i) {
		for (int j = 0; j < vv[i]; ++j) {
			if (j == 0 && i == vv.size() - 1)
				continue;
			ans += get(i, b, cur ^ (1 << j));
		}
		cur ^= (1 << vv[i]);
	}
	return ans;
}

void init() {
	for (int i = 2; i <= 10; ++i) {
		cc[i][0][0] = 1;
		for (int j = 0; j < 65; ++j) {
			for (int k = 0; k < (1 << i); ++k) {
				for (int l = 0; l < i; ++l) {
					cc[i][j + 1][k ^ (1 << l)] = min(INF, cc[i][j + 1][k ^ (1 << l)] + cc[i][j][k]);
				}
			}
		}
	}
}

int main() {
	init();
	int q;
	scanf("%d", &q);
	while (q--) {
		int b;
		ll l, r;
		scanf("%d%lld%lld", &b, &l, &r);
		printf("%lld\n", get(r + 1, b) - get(l, b));
	}
	return 0;
}