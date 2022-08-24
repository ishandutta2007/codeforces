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

const int MX = 5032107 + 5;

int go[MX][8];

int gl[20];
int bb[MX];
vector<int> primes;
int ans[1200000];

vector<int> vv;
int gst = 0;
int n, q;
int a[200000];
vector<pair<int, int>> gg[200000];

void run(int x, int cur, int cnt) {
	if (x == vv.size()) {
		for (int i = 0; i < 8; ++i)
			gl[i + cnt] = max(gl[i + cnt], go[cur][i]);
		go[cur][cnt] = gst;
		return;
	}
	run(x + 1, cur, cnt + 1);
	run(x + 1, cur * vv[x], cnt);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 1; i < MX; ++i)
		bb[i] = i;
	for (int i = 2; i < MX; ++i) {
		if (bb[i] == i)
			primes.push_back(i);
		for (int j: primes) {
			if (i * j >= MX || bb[i] < j)
				break;
			bb[i * j] = j;
		}
	}
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		gg[r].emplace_back(l, i);
	}
	for (int i = 1; i <= n; ++i) {
		gst = i;
		int now = a[i];
		vv.clear();
		while (now != 1) {
			int x = bb[now];
			int fl = 0;
			while (now % x == 0)
				now /= x, fl ^= 1;
			if (fl)
				vv.push_back(x);
		}
		run(0, 1, 0);
		for (auto qq: gg[i]) {
			int ns = 20;
			for (int j = 0; j < 20; ++j)
				if (gl[j] >= qq.first) {
					ns = min(ns, j);
				}
			ans[qq.second] = ns;
		}
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
	return 0;
}