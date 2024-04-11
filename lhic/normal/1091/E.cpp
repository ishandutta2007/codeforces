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

const int MAXN = 510000;

int n;

ll a[MAXN];
ll sum[MAXN];
ll ad[MAXN];

void del(ll l, ll r) {
	if (l <= r) {
		++ad[l];
		--ad[r + 1];
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	sum[0] = 0;
	for (int i = 0; i < n; ++i)
		sum[i + 1] = sum[i] + a[i];
	ll sm = 0;
	ll sm2 = 0;
	ll x = lower_bound(a, a + n, 1) - a;
	sm2 += sum[x] + ll(n - x) * 1;
	ll go = sm2 - sm;
	if (go < a[n - 1])
		del(a[n - 1], n);
	else
		del(go + 1, n);
	for (int i = n - 1; i >= 0; --i) {
		ll sm = sum[n] - sum[i];
		ll sm2 = ll(n - i) * (n - i - 1);
		if (i != 0) {
			ll x = lower_bound(a, a + i, n - i) - a;
			sm2 += sum[x] + ll(i - x) * (n - i);
		}
		ll go = max(0ll, sm - sm2);
		if (go > n - i || go > a[i])
			del(0, a[i]);
		else
			del(0, go - 1);
		sm2 = ll(n - i + 1) * (n - i);
		ll pr = 0;
		if (i != 0)
			pr = a[i - 1];
		if (i != 0) {
			ll x = lower_bound(a, a + i, n - i + 1) - a;
			sm2 += sum[x] + ll(i - x) * (n - i + 1);
		}
		go = sm2 - sm;
		if (go < pr)
			del(pr, n);
		else
			del(go + 1, n);
	}
	ll now = 0;
	vector<int> ans;
	for (int i = 0; i <= n; ++i) {
		now += ad[i];
		if (now == 0) {
			if ((sum[n] + i) % 2 == 0)
				ans.push_back(i);
		}
	}
	if (ans.empty())
		cout << -1 << "\n";
	else {
		for (int i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}