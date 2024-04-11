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

const int C2 = 19;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int C = 9 * 20 + 1;

using bb = bitset<C>;

vector<bb> vv;

unordered_set<bb> mapa1, mapa2;

bool cmp(const bb &a, const bb &b) {
	for (int i = 0; i < 9 * 20; ++i) {
		if (a[i] < b[i])
			return 1;
		if (b[i] < a[i])
			return 0;
	}
	return 0;
}

unordered_map<bb, int> mm;

int upd(int x, int j) {
	bb cur = (vv[x] << j) | (vv[x] >> j);
	for (int k = 0; k < j; ++k)
		if (vv[x][k])
			cur[j - k] = 1;
	auto it = mm.find(cur);
	if (it == mm.end())
		return -1;
	return it->second;
}
const int MX = 50000;

int go[MX][10];
ll dp[MX][10][20];
int nl;

ll get(ll x, int k) {
	vector<int> dg;
	for (int i = 0; i < C2; ++i)
		dg.push_back(x % 10), x /= 10;
	ll ans = 0;
	ll cur = nl;
	for (int i = C2 - 1; i >= 0; --i) {
		for (int j = 0; j < dg[i]; ++j) {
			ll tmp = go[cur][j];
			ans += dp[tmp][k][i];
		}
		cur = go[cur][dg[i]];
	}
	return ans;
}

int av[MX][10];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	bb tmp;
	tmp[0] = 1;
	mapa1.insert(tmp);
	for (int i = 0; i < C2; ++i) {
		mapa2.clear();
		for (auto msk: mapa1) {
			for (int j = 0; j <= 9; ++j) {
				bb cur = (msk << j) | (msk >> j);
				for (int k = 0; k < j; ++k)
					if (msk[k])
						cur[j - k] = 1;
				mapa2.insert(cur);
			}
		}
		mapa1 = mapa2;
	}
	for (auto x: mapa1)
		vv.push_back(x);
	sort(vv.begin(), vv.end(), cmp);
	for (int i = 0; i < vv.size(); ++i)
		mm[vv[i]] = i;
	nl = mm[tmp];
	av[nl][0] = 1;
	for (int i = 0; i < vv.size(); ++i) {
		go[i][0] = i;
		for (int j = 1; j <= 9; ++j) {
			go[i][j] = upd(i, j);
		}
		for (int j = 0; j <= 9; ++j)
			if (vv[i][j])
				av[i][j] = 1;
	}
	for (int i = vv.size() - 1; i >= 0; --i) {
		int x = 0;
		while (!av[i][x]) {
			++x;
		}
		for (int j = x; j <= 9; ++j)
			dp[i][j][0] = 1;
	}
	for (int ad = 1; ad <= C2; ++ad) {
		for (int i = 0; i < vv.size(); ++i) {
			for (int j = 0; j <= 9; ++j) {
				if (go[i][j] == -1)
					continue;
				for (int k = 0; k <= 9; ++k) {
					dp[i][k][ad] += dp[go[i][j]][k][ad - 1];
				}
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		int k;
		cin >> l >> r >> k;
		cout << get(r + 1, k) - get(l, k) << "\n";
	}
	return 0;
}