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

int n, t;

int ask(int l, int r) {
	cout << "? " << l + 1 << " " << r << "\n";
	cout.flush();
	int x;
	cin >> x;
	return x;
}

pair<int, int> get(int l, int r) {
	assert(l % 2 != (n - r) % 2);
	int a = 0;
	int b = 0;
	int cur = t;
	int gl = r;
	int gr = n - l;
	while (a != 1 || b != 0) {
		int nw = ask(l, r);
		if ((cur + nw) % 2 == gl % 2)
			a ^= 1;
		else
			b ^= 1;
		cur = nw;
	}
	int al = (gl - cur + t) / 2;
	while (a != 0 || b != 1) {
		int nw = ask(l, r);
		if ((cur + nw) % 2 == gl % 2)
			a ^= 1;
		else
			b ^= 1;
		cur = nw;
	}
	int ar = (gr - cur + t) / 2;
	while (a != 0 || b != 0) {
		int nw = ask(l, r);
		if ((cur + nw) % 2 == gl % 2)
			a ^= 1;
		else
			b ^= 1;
		cur = nw;
	}
	return {al, ar};
}

const int MAXN = 310;
int a[MAXN];
pair<int, int> d[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> t;
	if (n == 1) {
		cout << "! " << t << "\n";
		cout.flush();
		return 0;
	}
	if (n % 2 == 0) {
		for (int i = 0; i < n; ++i)
			a[i] = get(i, i + 1).first;
		for (int i = n - 1; i > 0; --i)
			a[i] = a[i] - a[i - 1];
		cout << "! ";
		for (int i = 0; i < n; ++i)
			cout << a[i];
		cout << "\n";
		cout.flush();
		return 0;
	}
	for (int i = 0; i + 1 < n; ++i) {
		d[i] = get(i, i + 2);
	}
	for (int i = 2; i < n; ++i)
		a[i] = d[i - 1].first - d[i - 2].first;
	int sum = 0;
	for (int i = 2; i < n; ++i)
		sum += a[i];
	a[1] = d[1].second - sum;
	sum += a[1];
	a[0] = d[0].second - sum;
	cout << "! ";
	for (int i = 0; i < n; ++i)
		cout << a[i];
	cout << "\n";
	cout.flush();
	return 0;
}