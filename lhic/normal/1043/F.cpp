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

const int MAXN = 310000;

int n;
int a[MAXN];
vector<int> pr;
int bb[MAXN];
int go[MAXN];
int cc[MAXN];
int ans[MAXN];
vector<int> fc[MAXN];

int gcd(int a, int b) {
	while (b) {
		int q = a % b;
		a = b;
		b = q;
	}
	return a;
}


int dp[1 << 7];
int gg;
int gog[1 << 7];

void run(int x, int msk, int ml, int k) {
	if (x == k) {
		dp[msk] = cc[ml];
		gog[msk] = ml;
		return;
	}
	run(x + 1, msk, ml, k);
	run(x + 1, msk + (1 << x), ml * fc[gg][x], k);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 0; i < MAXN; ++i)
		bb[i] = i;
	for (int i = 2; i < MAXN; ++i) {
		if (bb[i] == i)
			pr.push_back(i);
		for (int j: pr) {
			if (j * i >= MAXN || bb[i] < j)
				break;
			bb[j * i] = j;
		}
	}
	for (int i = 1; i < MAXN; ++i) {
		int cur = 1;
		int x = i;
		while (x != 1) {
			int d = bb[x];
			while (x % d == 0)
				 x /= d;
			cur *= d;
			fc[i].push_back(d);
		}
		go[i] = cur;
	}
	cin >> n;
	int now = 0;
	fill(ans, ans + MAXN, 1000);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		now = gcd(now, a[i]);
		a[i] = go[a[i]];
		++cc[a[i]];
		ans[a[i]] = 1;
	}
	if (now != 1) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 2 * i; j < MAXN; j += i)
			cc[i] += cc[j];
	}
	for (int i = MAXN - 1; i > 1; --i) {
		if (go[i] != i)
			continue;
		int k = fc[i].size();
		gg = i;
		run(0, 0, 1, k);
		for (int i = (1 << k) - 1; i > 0; --i) {
			for (int j = (i - 1) & i; j > 0; j = (j - 1) & i)
				dp[j] -= dp[i];
			dp[0] -= dp[i];
		}
		for (int j = 0; j < (1 << k); ++j) 
			if (dp[j])
				ans[gog[j]] = min(ans[gog[j]], ans[i] + 1);
	}
	cout << ans[1] << "\n";
	return 0;
}