#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

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

const int MAXN = 230000;

string s, t;

int sm[MAXN];
int pr[MAXN];

pair<int, int> get(int l, int r) {
	int cnt1 = sm[r] - sm[l];
	int cnt0 = r - l;
	if (pr[r] >= l)
		cnt0 = r - pr[r] - 1;
	return make_pair(cnt1, cnt0);
}

int solve(pair<int, int> x, pair<int, int> y) {
	int a, b, c, d;
	tie(a, b) = x, tie(c, d) = y;
	if ((a + c) % 2 != 0)
		return 0;
	if (a > c)
		return 0;
	if (d > b)
		return 0;
	if (a == c)
		if (b % 3 != d % 3)
			return 0;
	if (c > a && a == 0 && b == d) {
		return 0;
	}
	return 1;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s >> t;
	int sh = s.size();
	s += t;
	int n = s.size();
	sm[0] = 0;
	pr[0] = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') {
			sm[i + 1] = sm[i];
			pr[i + 1] = pr[i];
		}
		else {
			sm[i + 1] = sm[i] + 1;
			pr[i + 1] = i;
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		--l1, --l2;
		l2 += sh, r2 += sh;
		if (solve(get(l1, r1), get(l2, r2)))
			cout << 1;
		else
			cout << 0;
	}
	cout << "\n";
	return 0;
}