#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

const int MX = 7010;

using bs = bitset<MX>;


bs ad[MX];

bs gt[MX];

bs a[120000];


int n, q;
int mu[MX];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	mu[1] = 1;
	for (int i = 1; i < MX; ++i) {
		for (int j = i * 2; j < MX; j += i)
			mu[j] -= mu[i];
	}
	for (int i = 1; i < MX; ++i) {
		for (int j = 1; j <= i; ++j)
			if (i % j == 0)
				ad[i][j] = 1;
		for (int j = 1; i * j < MX; ++j) {
			if (mu[j] != 0)
				gt[i][i * j] = 1;
		}
	}
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		int t;
		int x, v;
		int y, z;
		cin >> t;
		if (t == 1) {
			cin >> x >> v;
			--x;
			a[x] = ad[v];
		}
		else if (t == 2) {
			cin >> x >> y >> z;
			--x, --y, --z;
			a[x] = a[y] ^ a[z];
		}
		else if (t == 3) {
			cin >> x >> y >> z;
			--x, --y, --z;
			a[x] = a[y] & a[z];
		}
		else {
			cin >> x >> v;
			--x;
			if ((a[x] & gt[v]).count() % 2 == 1)
				cout << 1;
			else
				cout << 0;
		}
	}
	cout << "\n";
	return 0;
}