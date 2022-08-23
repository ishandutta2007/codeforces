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

const int MAXN = 212000;

ll c[MAXN];
ll t[MAXN];
int n;

vector<ll> v1, v2;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	for (int i = 0; i + 1 < n; ++i)
		v1.push_back(c[i + 1] - c[i]);
	for (int i = 0; i + 1 < n; ++i)
		v2.push_back(t[i + 1] - t[i]);
	sort(ALL(v1));
	sort(ALL(v2));
	if (t[0] == c[0] && t[n - 1] == c[n - 1] && v1 == v2)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}