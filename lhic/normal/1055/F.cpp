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


const int MAXN = 1e6 + 100;
int p[MAXN];
ll w[MAXN];
ll a[MAXN];
int n;

ll k;

vector<pair<pair<int, int>, pair<int, int>>> vv;
vector<pair<int, int>> tmp;
vector<pair<pair<int, int>, pair<int, int>>> vv2;

int get(pair<int, int> xx, int x) {
	int l = xx.first;
	int r = xx.second;
	int now = l;
	while (now < r && ((a[now] >> x) & 1) == 0)
		++now;
	return now;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	a[0] = 0;
	for (int i = 1; i < n; ++i) {
		cin >> p[i] >> w[i];
		--p[i];
		a[i] = a[p[i]] ^ w[i]; 
	}
	sort(a, a + n);
	vv.push_back({{0, n}, {0, n}});
	ll ans = 0;
	for (int it = 61; it >= 0; --it) {
		tmp.clear();
		ll sum = 0;
		for (int i = 0; i < vv.size(); ++i) {
			tmp.emplace_back(get(vv[i].first, it), get(vv[i].second, it));
			sum += ll(tmp[i].first - vv[i].first.first) * (tmp[i].second - vv[i].second.first);
			sum += ll(vv[i].first.second - tmp[i].first) * (vv[i].second.second - tmp[i].second);
		}
		vv2.clear();
		if (sum >= k) {
			for (int i = 0; i < vv.size(); ++i) {
				if (tmp[i].first != vv[i].first.first && tmp[i].second != vv[i].second.first)
					vv2.push_back({{vv[i].first.first, tmp[i].first}, {vv[i].second.first, tmp[i].second}});
				if (tmp[i].first != vv[i].first.second && tmp[i].second != vv[i].second.second)
					vv2.push_back({{tmp[i].first, vv[i].first.second}, {tmp[i].second, vv[i].second.second}});
			}
		}
		else {
			ans += (1ll << it);
			k -= sum;
			for (int i = 0; i < vv.size(); ++i) {
				if (tmp[i].first != vv[i].first.first && tmp[i].second != vv[i].second.second)
					vv2.push_back({{vv[i].first.first, tmp[i].first}, {tmp[i].second, vv[i].second.second}});
				if (tmp[i].first != vv[i].first.second && tmp[i].second != vv[i].second.first)
					vv2.push_back({{tmp[i].first, vv[i].first.second}, {vv[i].second.first, tmp[i].second}});
			}
		}
		vv = vv2;
	}
	cout << ans << "\n";
	return 0;
}