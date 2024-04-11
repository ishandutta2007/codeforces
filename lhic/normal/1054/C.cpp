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

const int MAXN = 1200;

int n;
int l[MAXN];
int r[MAXN];
int a[MAXN];

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> l[i];
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	for (int i = 0; i < n; ++i) {
		a[i] = n - l[i] - r[i];
		if (a[i] <= 0)
			no();
	}
	for (int i = 0; i < n; ++i) {
		int c = 0;
		for (int j = 0; j < i; ++j)
			if (a[j] > a[i])
				++c;
		if (c != l[i])
			no();
		c = 0;
		for (int j = i + 1; j < n; ++j)
			if (a[j] > a[i])
				++c;
		if (c != r[i])
			no();
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}