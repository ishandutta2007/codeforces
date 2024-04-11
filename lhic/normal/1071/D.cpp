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
const int MX = 1e6 + 1;
const int D = 1000;
const int INF = 1e9;

map<vector<int>, int > mm;
vector<vector<int>> gg;

int tmp[D];
int tmp2[D];
int ds[300][D];
int aa[300][300];

int bb[MX];
vector<int> pr;

int ggg[MX];
int cnt = 0;

int get(vector<int> vv) {
	if (mm.count(vv))
		return mm[vv];
	else {
		gg.push_back(vv);
		return mm[vv] = cnt++;
	}
}

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
			if (j * i >= MX || bb[i] < j)
				break;
			bb[i * j] = j;
		}
	}
	for (int i = 1; i < MX; ++i) {
		vector<int> vv;
		int x = i;
		while (x != 1) {
			int j = bb[x];
			int cnt = 0;
			while (x % j == 0)
				x /= j, ++cnt;
			vv.push_back(cnt + 1);
		}
		sort(ALL(vv));
		reverse(ALL(vv));
		ggg[i] = get(vv);
	}
	for (int i = 0; i < gg.size(); ++i) {
		fill(tmp, tmp + D, INF);
		tmp[1] = 0;
		for (int j: gg[i]) {
			fill(tmp2, tmp2 + D, INF);
			for (int k = 1; k <= j + 10; ++k) {
				for (int x = 1; x * k < D; ++x)
					tmp2[x * k] = min(tmp2[x * k], tmp[x] + abs(k - j));
			}
			memcpy(tmp, tmp2, sizeof(tmp));
		}
		for (int i = 1; i < D; ++i) {
			if (tmp[i] >= INF)
				continue;
			for (int j = 2; i * j < D; ++j)
				tmp[i * j] = min(tmp[i * j], tmp[i] + j - 1);
		}
		for (int j = 0; j < D; ++j)
			ds[i][j] = tmp[j];
	}
//	int mx = 0;
	for (int i = 0; i < gg.size(); ++i) {
		for (int j = 0; j < gg.size(); ++j) {
			int ans = INF;
			for (int k = 0; k < D; ++k)
				ans = min(ans, ds[i][k] + ds[j][k]);
			aa[i][j] = ans;
			//cout << ans << " ";
		//	mx = max(mx, ans);
		}
		//cout << "\n";
	}
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		int a, b;
		cin >> a >> b;
		a = ggg[a], b = ggg[b];
		cout << aa[a][b] << "\n";
	}
	return 0;
}