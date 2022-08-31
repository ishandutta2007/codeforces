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

const int MAXN = 1200;

int n;

vector<int> eds[1200];

int askx(int x) {
	cout << "A " << x + 1 << "\n";
	cout.flush();
	cin >> x;
	return x - 1;
}

int asky(int y) {
	cout << "B " << y + 1 << "\n";
	cout.flush();
	cin >> y;
	return y - 1;
}

int fl[MAXN];

int dfs1(int v, int p) {
	if (fl[v])
		return v;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		int x = dfs1(u, v);
		if (x != -1)
			return x;
	}
	return -1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	int k1;
	cin >> k1;
	vector<int> v1, v2;
	memset(fl, 0, sizeof(fl));
	for (int i = 0; i < k1; ++i) {
		int x;
		cin >> x;
		v1.push_back(x - 1);
		fl[x - 1] = 1;
	}
	int k2;
	cin >> k2;
	for (int i = 0; i < k2; ++i) {
		int x;
		cin >> x;
		v2.push_back(x - 1);
	}
	int st = v2[0];
	int x = asky(st);
	x = dfs1(x, -1);
	int y = askx(x);
	int fll = 0;
	for (int i: v2)
		if (i == y)
			fll = 1;
	if (fll) {
		cout << "C " << x + 1 << "\n";
		cout.flush();
	}
	else {
		cout << "C " << -1 << "\n";
		cout.flush();

	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}