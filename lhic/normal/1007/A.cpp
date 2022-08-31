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


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		vv.push_back(a);
	}
	sort(vv.rbegin(), vv.rend());
	int now = 1e9 + 100;
	int cnt = 0;
	int ans = 0;
	int cur = 0;
	for (int x: vv) {
		if (now > x) {
			cur += cnt;
			now = x;
			cnt = 0;
		}
		if (cur) {
			--cur;
			++ans;
		}
		++cnt;
	}
	cout << ans << "\n";
	return 0;
}