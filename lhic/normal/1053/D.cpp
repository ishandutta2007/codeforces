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
const int MX = 2e6 + 10;
const ll MOD = 1e9 + 7;

vector<int> pr;

int bb[MX];
int n;
int a[MX];
int p[210000];
int cnt[MX];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 0; i < MX; ++i)
		bb[i] = i;
	for (int i = 2; i < MX; ++i) {
		if (bb[i] == i)
			pr.push_back(i);
		for (int j: pr) {
			if (bb[i] < j || i * j >= MX)
				break;
			bb[i * j] = j;
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	sort(p, p + n);
	reverse(p, p + n);
	int gfl = 0;
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		if (!a[p[i]])
			++a[p[i]], ++cnt[p[i]];
		else {
			int x = p[i] - 1;
			vv.push_back(x);
			int fl = 0;
			while (x != 1) {
				int y = bb[x];
				int cc = 0;
				while (x % y == 0)
					x /= y, ++cc;
				if (a[y] < cc) {
					cnt[y] = 1;
					a[y] = cc;
					fl = 1;
				}
				else if (a[y] == cc)
					++cnt[y];
			}
			if (!fl)
				gfl = 1;
		}
	}
	if (!gfl) {
		for (int x: vv) {
			int fl = 0;
			while (x != 1) {
				int y = bb[x];
				int cc = 0;
				while (x % y == 0)
					x /= y, ++cc;
				if (a[y] == cc && cnt[y] == 1) {
					fl = 1;
				}
			}
			if (!fl)
				gfl = 1;
		}
	}
	ll ans = 1;
	for (int i = 0; i < MX; ++i)
		for (int j = 0; j < a[i]; ++j)
			ans = (ans * i) % MOD;
	if (gfl)
		ans = (ans + 1) % MOD;
	cout << ans << "\n";
	return 0;
}