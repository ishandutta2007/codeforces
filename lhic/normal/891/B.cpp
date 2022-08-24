#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
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

int n;
vector<pair<int, int> > vv;

int a[100];
int b[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], vv.push_back(make_pair(a[i], i));
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size() - 1; ++i) {
		if (vv[i].first == vv[i + 1].first) {
			cout << -1 << "\n";
			return 0;
		}
	}
	vv.push_back(vv[0]);
	for (int i = 0; i < vv.size() - 1; ++i) {
		b[vv[i].second] = vv[i + 1].first;
	}
	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
	cout << "\n";
	return 0;
}