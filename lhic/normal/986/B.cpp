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
const int MAXN = 1e6 + 10;

int was[MAXN];
int a[MAXN];

void dfs1(int v) {
	was[v] = 1;
	int u = a[v];
	if (!was[u])
		dfs1(u);
}

int n;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], --a[i];
	int sum = n;
	for (int i = 0; i < n; ++i) {
		if (!was[i])
			dfs1(i), --sum;
	}
	if (n % 2 == 0) {
		if (sum % 2 == 0) {
			cout << "Petr\n";
		}
		else {
			cout << "Um_nik\n";
		}
	}
	else {
		if (sum % 2 == 1) {
			cout << "Petr\n";
		}
		else {
			cout << "Um_nik\n";
		}
	}
	return 0;
}