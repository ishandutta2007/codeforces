#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 310000;

int rmq[N * 4];
int dd[N * 4];

void add(int v, int tl, int tr, int l, int r, int d) {
	if (r <= tl || tr <= l) {
		return;
	}
	if (l <= tl && tr <= r) {
		dd[v] += d;
		rmq[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	rmq[v] += dd[v];
}


int p[N];
int pl[N];
int q[N];
int n;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
		pl[p[i]] = i;
	}
	cout << n;
	int cur = n - 1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		if (i + 1 == n) {
			break;
		}

		add(0, 0, n, 0, x + 1, 1);
		while (rmq[0] >= 0) {
			add(0, 0, n, 0, pl[cur] + 1, -1);
			--cur;
		}
		cout << " " << cur + 2;
	}
	cout << "\n";
	return 0;
}