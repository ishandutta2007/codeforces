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

vector<pair<ll, char> > vv;
int n;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	int cur = -1;
	int fst = n;
	for (int i = 0; i < n; ++i) {
		ll x;
		char c;
		cin >> x >> c;
		vv.push_back({x, c});
		if (c == 'P') {
			cur = i;
			fst = min(fst, i);
		}
	}
	ll ans = 0;
	int pr1 = cur;
	int pr2 = cur;
	for (int i = cur + 1; i < vv.size(); ++i) {
		if (vv[i].second == 'B') {
			if (pr1 != -1)
				ans += vv[i].first - vv[pr1].first;
			pr1 = i;
		}
		else {
			if (pr2 != -1)
				ans += vv[i].first - vv[pr2].first;
			pr2 = i;
		}
	}
	if (cur == -1) {
		cout << ans << "\n";
		return 0;
	}
	while (cur != fst) {
		int now = cur - 1;
		while (vv[now].second != 'P')
			--now;
		ll v = 2 * (vv[cur].first - vv[now].first);
		ll mx1 = 0;
		ll mx2 = 0;
		int pr1 = now;
		int pr2 = now;
		for (int i = now + 1; i <= cur; ++i) {
			if (vv[i].second != 'B') {
				mx1 = max(mx1, vv[i].first - vv[pr1].first);
				pr1 = i;
			}
			if (vv[i].second != 'R') {
				mx2 = max(mx2, vv[i].first - vv[pr2].first);
				pr2 = i;
			}
		}
		v = min(v, 3 * (vv[cur].first - vv[now].first) - mx1 - mx2);
		ans += v;
		cur = now;
	}
	pr1 = cur;
	pr2 = cur;
	for (int i = cur - 1; i >= 0; --i) {
		if (vv[i].second == 'B') {
			ans -= vv[i].first - vv[pr1].first;
			pr1 = i;
		}
		else {
			ans -= vv[i].first - vv[pr2].first;
			pr2 = i;
		}
	}
	cout << ans << "\n";
	return 0;
}