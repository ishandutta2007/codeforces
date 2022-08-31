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
const int MX = 1 << 12;
const int MX2 = 1 << 14;
const int MXC = MX * 2;

bitset<MX> bb[MX2];

int cl[MX];
int clp[MX];
char buf[MX2];
int p[MXC];
int sz[MXC];
bitset<MXC> us;
int n, m;
int ans;

int get(int a) {
	if (p[a] == a)
		return a;
	return p[a] = get(p[a]);
}

int un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return 0;
	if (sz[a] < sz[b])
		swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", buf);
		for (int j = 0; j < m / 4; ++j) {
			char c = buf[j];
			int x = 0;
			if (isdigit(c))
				x = c - '0';
			else
				x = 10 + c - 'A';
			bb[j * 4][i] = (x >> 3) & 1;
			bb[j * 4 + 1][i] = (x >> 2) & 1;
			bb[j * 4 + 2][i] = (x >> 1) & 1;
			bb[j * 4 + 3][i] = x & 1;
		}
	}
	for (int i = 0; i < n; ++i)
		clp[i] = -1;
	for (int i = 0; i < m; ++i) {
		us.reset();
		for (int j = 0; j < MXC; ++j)
			p[j] = j, sz[j] = 1;
		for (int j = 0; j < n; ++j)
			if (clp[j] != -1)
				us[clp[j]] = 1;
		for (int j = 0; j < n; ++j)
			cl[j] = -1;
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			if (!bb[i][j])
				continue;
			if (j && bb[i][j - 1]) {
				cl[j] = cl[j - 1];
			}
			else {
				while (us[cur])
					++cur;
				cl[j] = cur;
				us[cur] = 1;
				++ans;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (clp[j] != -1 && cl[j] != -1) {
				ans -= un(clp[j], cl[j]);
			}
		}
		for (int j = 0; j < n; ++j) {
			if (cl[j] != -1)
				clp[j] = get(cl[j]);
			else
				clp[j] = -1;
		}
	}
	cout << ans << "\n";
	return 0;
}