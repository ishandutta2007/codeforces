#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 210000;

const int SQ = 400;

int n, q;

set<int> ss[N];

int a[N];

int lb[N];
int rb[N];

int sz[N];
int go[N];

vector<int> reb;

int nx[N];
int xx[N];
int ls[N];
int lg[N];
int gg[N];
int cc[N];

void rebuild(int k) {
	int l = lb[k];
	int r = rb[k];

	for (int  i = r - 1; i >= l; --i) {
		if (sz[i] == -1) {
			xx[i] = 0, nx[i] = i + 1;
		} else if (sz[i] == 1) {
			xx[i] = 1, nx[i] = i + 1;
		} else {
			int cur = i + 1;
			int now = go[i];
			int mx = sz[i];
			while (cur < r && cur < now) {
				mx = max(mx, xx[cur]);
				now = max(now, nx[cur]);
				cur = nx[cur];
			}
			nx[i] = now;
			xx[i] = mx;
		}
	}

	for (int i = r - 1; i >= l; --i) {
		if (nx[i] >= r || nx[nx[i]] >= r) {
			gg[i] = nx[i];
			cc[i] = xx[i];
		} else {
			gg[i] = gg[nx[i]];
			cc[i] = xx[i] + cc[nx[i]];
		}
	}


	int tmp = -1;
	for (int i = l + 1; i <= r; ++i) {
		tmp = max(tmp, nx[i - 1]);
		lg[i] = tmp;
	}
	tmp = -1;
	for (int i = l + 1; i <= r; ++i) {
		tmp = max(tmp, xx[i - 1]);
		ls[i] = tmp;
	}
}

int get() {
	int cur = 0;
	int ans = 0;
	while (cur < n) {
		int bl = cur / SQ;
		if (gg[cur] <= rb[bl]) {
			ans += cc[cur];
			cur = gg[cur];
			continue;
		}
		int now = gg[cur];
		int mx = cc[cur];
		++bl;
		while (true) {
			int r = min(now, rb[bl]);
			mx = max(mx, ls[r]);
			now = max(now, lg[r]);
			if (now <= rb[bl]) {
				ans += mx;
				cur = now;
				break;
			}
			++bl;
		}
	}
	return n - ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ss[a[i]].insert(i);
	}
	int bl = 0;
	for (int i = 0; i < n; i += SQ, ++bl) {
		lb[bl] = i;
		int r = min(n, i + SQ);
		rb[bl] = r;
	}
	for (int i = 0; i < n; ++i) {
		if (*ss[a[i]].begin() == i) {
			sz[i] = ss[a[i]].size();
			go[i] = *ss[a[i]].rbegin() + 1;
		} else {
			sz[i] = go[i] = -1;
		}
	}
	for (int i = 0; i < bl; ++i) {
		rebuild(i);
	}
	cout << get() << "\n";
	for (int i = 0; i < q; ++i) {
		reb.clear();
		int k, x;
		cin >> k >> x;
		--k;
		if (a[k] != x) {
			int b = *ss[a[k]].begin();
			sz[b] = go[b] = -1;
			reb.push_back(b / SQ);
			ss[a[k]].erase(k);
			if (!ss[a[k]].empty()) {
				int b = *ss[a[k]].begin();
				sz[b] = ss[a[k]].size();
				go[b] = *ss[a[k]].rbegin() + 1;
				reb.push_back(b / SQ);
			}
			a[k] = x;
			if (!ss[a[k]].empty()) {
				int b = *ss[a[k]].begin();
				sz[b] = go[b] = -1;
				reb.push_back(b / SQ);
			}
			ss[a[k]].insert(k);
			b = *ss[a[k]].begin();
			sz[b] = ss[a[k]].size();
			go[b] = *ss[a[k]].rbegin() + 1;
			reb.push_back(b / SQ);
			sort(ALL(reb));
			reb.resize(unique(ALL(reb)) - reb.begin());
			for (int i: reb)
				rebuild(i);
		}
		cout << get() << "\n";
	}
	return 0;
}