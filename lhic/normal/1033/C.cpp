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
const int MAXN = 120000;
int n;
int a[MAXN];
int dp[MAXN];
int pl[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pl[a[i]] = i;
	}
	for (int i = n; i >= 1; --i) {
		int x = pl[i];
		int fl = 0;
		for (int j = x + i; j < n; j += i) {
			if (a[j] > i && dp[j] == 0)
				fl = 1;
		}
		for (int j = x - i; j >= 0; j -= i) {
			if (a[j] > i && dp[j] == 0)
				fl = 1;
		}
		dp[x] = fl;
	}
	for (int i = 0; i < n; ++i) {
		if (dp[i])
			cout << "A";
		else
			cout << "B";
	}
	return 0;
}