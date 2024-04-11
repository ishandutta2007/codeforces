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
const int MAXN = 410000;
int gl[MAXN];
int gr[MAXN];
vector<ll> vv;
ll L;
int n;
ll a[MAXN];

bool check(ll x) {
	for (int i = 0; i < n; ++i) {
		gr[i] = upper_bound(vv.begin(), vv.end(), a[i] + x) - vv.begin();
		gl[i] = lower_bound(vv.begin(), vv.end(), a[i] - x) - vv.begin();
	}
	deque<pair<int, int>> dq;
	for (int i = 2 * n - 1; i >= n; --i) {
		int xx = gr[i - n] + n - i;
		while (!dq.empty() && dq.back().first >= xx)
			dq.pop_back();
		dq.push_back(make_pair(xx, i));
	}
	for (int i = n - 1; i >= 0; --i) {
		int xx = gr[i] - i;
		int xl = gl[i] - i + 1;
		while (!dq.empty() && dq.back().first >= xx)
			dq.pop_back();
		dq.push_back(make_pair(xx, i));
		while (dq.front().second >= i + n)
			dq.pop_front();
		if (dq.front().first < xl)
			return 0;
	}
	return 1;
}

ll b[MAXN];
int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> L;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i], vv.push_back(b[i]), vv.push_back(b[i] + L), vv.push_back(b[i] - L), vv.push_back(b[i] + 2 * L);
	sort(vv.begin(), vv.end());
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		a[i + n] = a[i] + L;
	ll lb = -1;
	ll rb = L / 2;
	while (rb - lb > 1) {
		ll mid = (lb + rb) >> 1;
		if (check(mid))
			rb = mid;
		else
			lb = mid;
	}
	cout << rb << "\n";
	return 0;
}