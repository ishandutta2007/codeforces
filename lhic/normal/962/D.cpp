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

int n;
ll a[220000];

map<ll, set<int>> mm;
int ds[220000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mm[a[i]].insert(i);
	}
	int cnt = n;
	for (auto it = mm.begin(); it != mm.end(); ++it) {
		while (it->second.size() >= 2) {
			int x = *(it->second.begin());
			int y = *(next(it->second.begin()));
			ds[x] = 1;
			--cnt;
			it->second.erase(x);
			it->second.erase(y);
			a[y] *= 2;
			mm[it->first * 2].insert(y);
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < n; ++i) {
		if (!ds[i])
			cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}