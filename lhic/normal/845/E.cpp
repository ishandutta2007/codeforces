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

const int MAXN = 2000;

ll n, m;
int k;

ll x[MAXN];
ll y[MAXN];
ll ad[MAXN][MAXN];

ll lbx[MAXN];
ll lby[MAXN];
ll rbx[MAXN];
ll rby[MAXN];
vector<ll> vx, vy;

int gx(int x) {
	return lower_bound(vx.begin(), vx.end(), x) - vx.begin();
}
int gy(int x) {
	return lower_bound(vy.begin(), vy.end(), x) - vy.begin();
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i];
		--x[i], --y[i];
	}
	ll l = -1;
	ll r = 1e9 + 100;
	while (r - l > 1) {
		ll mid = (l + r) >> 1;
		vx.clear(), vy.clear();
		vx.push_back(0);
		vx.push_back(n);
		vy.push_back(0);
		vy.push_back(m);
		for (int i = 0; i < k; ++i) {
			lbx[i] = max(0ll, x[i] - mid);
			rbx[i] = min(n, x[i] + mid + 1);
			lby[i] = max(0ll, y[i] - mid);
			rby[i] = min(m, y[i] + mid + 1);
			vx.push_back(lbx[i]);
			vx.push_back(rbx[i]);
			vy.push_back(lby[i]);
			vy.push_back(rby[i]);
		}
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
		vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
		for (int i = 0; i <= vx.size(); ++i)
			for (int j = 0; j <= vy.size(); ++j)
				ad[i][j] = 0;
		for (int i = 0; i < k; ++i) {
			lbx[i] = gx(lbx[i]);
			rbx[i] = gx(rbx[i]);
			lby[i] = gy(lby[i]);
			rby[i] = gy(rby[i]);
			++ad[lbx[i]][lby[i]];
			--ad[lbx[i]][rby[i]];
			--ad[rbx[i]][lby[i]];
			++ad[rbx[i]][rby[i]];
		}
		for (int i = 0; i < vx.size(); ++i)
			for (int j = 0; j < vy.size(); ++j) {
				if (i)
					ad[i][j] += ad[i - 1][j];
				if (j)
					ad[i][j] += ad[i][j - 1];
				if (i && j)
					ad[i][j] -= ad[i - 1][j - 1];
			}
		ll lx = n;
		ll rx = -1;
		ll ly = m;
		ll ry = -1;
		for (int i = 0; i < vx.size() - 1; ++i)
			for (int j = 0; j < vy.size() - 1; ++j) {
				if (!ad[i][j]) {
					lx = min(lx, vx[i]);
					ly = min(ly, vy[j]);
					rx = max(rx, vx[i + 1] - 1);
					ry = max(ry, vy[j + 1] - 1);
				}
			}
		if (rx - lx <= 2 * mid && ry - ly <= 2 * mid)
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
	return 0;
}