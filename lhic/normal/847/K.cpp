#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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

int n, a, b, k, f;
string sa[400];
string sb[400];
map<pair<string, string>, ll> mm;
vector<ll> vv;
ll ans = 0;

int main() {
	cin >> n >> a >> b >> k >> f;
	for (int i = 0; i < n; ++i) {
		cin >> sa[i] >> sb[i];
		string as = sa[i], bs = sb[i];
		if (as > bs)
			swap(as, bs);
		if (i == 0 || sb[i - 1] != sa[i])
			mm[make_pair(as, bs)] += a, ans += a;
		else
			mm[make_pair(as, bs)] += b, ans += b;
	}
	for (auto it: mm) {
		vv.push_back(it.second);
	}
	sort(vv.rbegin(), vv.rend());
	for (int i = 0; i < vv.size() && i < k; ++i) {
		if (vv[i] > f)
			ans -= vv[i] - f;
	}
	cout << ans << "\n";
	return 0;
}