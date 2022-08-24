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

struct st {
	int c, l, n;
};

bool cmp(st a, st b) {
	return make_pair(a.c, -a.l) > make_pair(b.c, -b.l);
}

vector<st> vv;
int n, k, m, a;
int cc[1200];
int lst[1200];
int ans[1200];

int main() {
	cin >> n >> k >> m >> a;
	for (int i = 0; i < a; ++i) {
		int x;
		cin >> x;
		--x;
		++cc[x];
		lst[x] = i;
	}
	for (int i = 0; i < n; ++i)
		vv.push_back({cc[i], lst[i], i});
	sort(vv.begin(), vv.end(), cmp);
	for (int i = 0; i < n; ++i) {
		int c = 0;
		for (int j = 0; j < i; ++j) {
			if (vv[j].c >= vv[i].c + m - a)
				++c;
		}
		int c2 = i;
		int hv = m - a;
		for (int j = i + 1; j < n; ++j) {
			int go = vv[i].c + 1 - vv[j].c;
			if (hv >= go)
				++c2, hv -= go;
		}
		if (c >= k || (m - a == 0 && vv[i].c == 0))
			ans[vv[i].n] = 2;
		else {
			if (c2 < k && vv[i].c != 0)
				ans[vv[i].n] = 0;
			else
				ans[vv[i].n] = 1;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] + 1 << " ";
	cout << "\n";
	return 0;	
}