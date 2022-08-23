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

int go[MAXN];
int pl[MAXN];
int en[MAXN];
int pr[MAXN];
vector<int> gg[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], --a[i], pl[a[i]] = i;
	memset(en, 0, sizeof(en[0]) * n);
	int k = 0;
	while (k * (k + 1) / 2 <= n)
		++k;
	--k;
	int cur = n;
	vector<vector<int>> ansv;
	while (k && cur) {
		fill(go, go + n + 1, n);
		go[0] = -1;
		int ans = 0;
		int st = -1;
		for (int i = 0; i < n; ++i) {
			if (en[i])
				continue;
			int x = lower_bound(go, go + n, a[i]) - go;
			pr[i] = go[x - 1];
			go[x] = a[i];
			if (x > ans)
				ans = x, st = i;
		}
		if (ans > k) {
			cur -= ans;
			int now = st;
			vector<int> vv;
			while (true) {
				en[now] = 1;
				vv.push_back(a[now]);
				if (pr[now] == -1)
					break;
				now = pl[pr[now]];
			}
			reverse(ALL(vv));
			ansv.push_back(vv);
			--k;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		gg[i].clear();
	set<pair<int, int>> ss;
	int cc = 0;
	for (int i = 0; i < n; ++i) {
		if (en[i])
			continue;
		auto it = ss.lower_bound(make_pair(a[i], 0));
		if (it == ss.end()) {
			gg[cc].push_back(a[i]);
			ss.emplace(a[i], cc);
			++cc;
		}
		else {
			int x = it->second;
			gg[x].push_back(a[i]);
			ss.erase(it);
			ss.emplace(a[i], x);
		}
	}
	for (int i = 0; i < cc; ++i) {
		ansv.push_back(gg[i]);
	}
	cout << ansv.size() << "\n";
	for (auto &vv: ansv) {
		cout << vv.size() << " ";
		for (int i: vv)
			cout << i + 1 << " ";
		cout << "\n";
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