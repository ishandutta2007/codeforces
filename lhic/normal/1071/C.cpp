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
vector<tuple<int, int, int>> ans;

void out() {
	cout << "YES\n";
	cout << ans.size() << "\n";
	for (auto t: ans) {
		int x, y, z;
		tie(x, y, z) = t;
		cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
	}
	exit(0);
}

void no() {
	cout << "NO\n";
	exit(0);
}

void add(int x, int y, int z) {
	vector<int> tmp = {x, y, z};
	sort(ALL(tmp));
	x = tmp[0], y = tmp[1], z = tmp[2];
	ans.emplace_back(x, y, z);
	a[x] ^= 1;
	a[y] ^= 1;
	a[z] ^= 1;
}

void add(int x, int y) {
	assert(x > y);
	int d = x - y;
	add(y - d, y, x);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int tmpn = n;
	while (n >= 12) {
		if (!a[n - 1]) {
			n -= 1;
			continue;
		}
		if (a[n - 2]) {
			if (a[n - 3]) {
				add(n - 3, n - 2, n - 1);
				n -= 3;
			}
			else {
				vector<int> ps;
				for (int i = n - 4; i >= n - 6; --i)
					if (a[i])
						ps.push_back(i);
				if (ps.size() == 0) {
					add(n - 1, n - 6);
					add(n - 2, n - 6);
				}
				else if (ps.size() == 1) {
					add(n - 2, n - 7);
					add(n - 1, ps[0]);
				}
				else if (ps.size() == 2) {
					add(n - 1, ps[0]);
					add(n - 2, ps[1]);
				}
				else {
					add(n - 2, n - 4);
					add(n - 1, n - 5);
				}
				n -= 6;
			}
		}
		else {
			if (a[n - 3]) {
				add(n - 5, n - 3, n - 1);
				n -= 3;
			}
			else {
				add(n - 7, n - 4, n - 1);
				n -= 3;
			}
		}
	}
	for (int i = n - 1; i - 2 >= 0; --i)
		if (a[i])
			add(i - 2, i - 1, i);
	if (a[1]) {
		if (tmpn <= 7)
			no();
		add(1, 4, 7);
		add(4, 5, 6);
		add(5, 6, 7);
	}
	if (a[0]) {
		if (tmpn <= 7)
			no();
		add(0, 3, 6);
		add(3, 4, 5);
		add(4, 5, 6);
	}
	out();
	for (int i = 0; i < tmpn; ++i)
		assert(a[i] == 0);
	assert(ans.size() <= tmpn / 3 + 12);
	return 0;
}