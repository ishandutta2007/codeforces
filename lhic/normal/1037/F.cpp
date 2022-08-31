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
const ll MOD = 1e9 + 7;

int n, k;
ll a[MAXN];
int gl[MAXN];
int gr[MAXN];

ll get(ll l, ll r) {
	ll lb = l / k;
	l %= k;
	ll rb = r / k;
	r %= k;
	ll ans = k * lb % MOD * rb % MOD;
	ans = (ans + l * rb + r * lb) % MOD;
	if (l && r) {
		--l;
		--r;
		ans = (ans + 1) % MOD;
		if (l + r >= k - 1)
			ans = (ans + l + r - (k - 1)) % MOD;
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	--k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && a[st.back()] < a[i])
			st.pop_back();
		if (st.empty())
			gl[i] = i;
		else
			gl[i] = i - st.back() - 1;
		st.push_back(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && a[st.back()] <= a[i])
			st.pop_back();
		if (st.empty())
			gr[i] = n - 1 - i;
		else
			gr[i] = st.back() - i - 1;
		st.push_back(i);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + get(gl[i] + 1, gr[i] + 1) * a[i]) % MOD;
	}
	for (int i = 0; i < n; ++i)
		ans = (ans - a[i] + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}