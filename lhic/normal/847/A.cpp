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
int l[120];
int r[120];
vector<pair<int, int> > vv;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		--l[i], --r[i];
	}
	for (int i = 0; i < n; ++i) {
		if (l[i] == -1) {
			int st = i;
			int cur = i;
			while (r[cur] != -1)
				cur = r[cur];
			vv.push_back(make_pair(st, cur));
		}
	}
	for (int i = 0; i < vv.size() - 1; ++i) {
		int x = vv[i].second;
		int y = vv[i + 1].first;
		r[x] = y;
		l[y] = x;
	}
	for (int i = 0; i < n; ++i) {
		cout << l[i] + 1 << " " << r[i] + 1 << "\n";
	}
	return 0;
}