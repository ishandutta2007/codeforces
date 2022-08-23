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

map<int, vector<int> > mm;

int ans[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = n - a[i];
		mm[a[i]].push_back(i);
	}
	int cc = 1;
	for (auto v: mm) {
		if (v.second.size() % v.first != 0) {
			cout << "Impossible\n";
			return 0;
		}
		for (int i = 0; i < v.second.size(); ++i) {
			ans[v.second[i]] = cc + i / v.first;
		}
		cc += v.second.size() / v.first;
	}
	cout << "Possible\n";
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}