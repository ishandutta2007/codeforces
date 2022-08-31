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

const int MAXN = 510000;

int m, k, n, s;
int a[MAXN];
int nd[MAXN];
int hv[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> m >> k >> n >> s;
	for (int i = 0; i < m; ++i)
		cin >> a[i];
	for (int i = 0; i < s; ++i) {
		int x;
		cin >> x;
		++nd[x];
	}
	int ls = s;
	int now = 0;
	int lf = m - k * n;
	for (int i = 0; i < m; ++i) {
		while (now < m && ls > 0) {
			++hv[a[now]];
			if (hv[a[now]] <= nd[a[now]])
				--ls;
			++now;
		}
		if (ls == 0) {
			int go = i % k;
			int df = i % k;
			if (i > k * (n - 1))
				go = i - k * (n - 1), df = i - k * (n - 1);
			if (now - i > k)
				go += (now - i) - k;
			if (go <= lf) {
				vector<int> del;
				for (int j = 0; j < df; ++j)
					del.push_back(j);
				int d = max(0, now - i - k);
				for (int j = i; j < now; ++j) {
					if (nd[a[j]])
						--nd[a[j]];
					else if (d)
						del.push_back(j), --d;
				}
				cout << del.size() << "\n";
				for (int i: del)
					cout << i + 1 << " ";
				cout << "\n";
				return 0;
			}
		}
		--hv[a[i]];
		if (hv[a[i]] < nd[a[i]])
			++ls;
	}
	cout << -1 << "\n";
	return 0;
}