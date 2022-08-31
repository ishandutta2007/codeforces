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

int n, q, m;
int a[220000];
vector<tuple<int, int, int> > vv;

int main() {
	scanf("%d%d%d", &n, &q, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < q; ++i) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		--l, --r;
		vv.push_back(make_tuple(t, l, r));
	}
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		for (int i = 0; i < vv.size(); ++i) {
			int t, l, r;
			tie(t, l, r) = vv[i];
			if (x < l || x > r)
				continue;
			if (t == 1) {
				if (x == l)
					x = r;
				else
					--x;
			}
			else {
				x = l + r - x;
			}
		}
		printf("%d ", a[x]);
	}
	printf("\n");
	return 0;
}