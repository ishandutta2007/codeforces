#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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
const int MK = 210;
const int MAXN = 31000;

int n, k;

int dd[MK][MAXN];
int go[MK];

int p[MAXN];
int sz[MAXN];
set<pair<int, int>> ed;

int get(int a) {
	if (a == p[a])
		return a;
	return p[a] = get(p[a]);
}

void un(int a, int b) {
	if (a > b)
		swap(a, b);
	if (ed.count({a, b}))
		return;
	ed.insert({a, b});
	a = get(a);
	b = get(b);
	if (a == b) {
		cout << -1 << "\n";
		exit(0);
	}
	if (sz[a] > sz[b])
		swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
}

int way[MAXN];
int was[MAXN];
map<ull, int> mm;
const ull P = 1e9 + 7;

ull geths(int x) {
	ull now = 0;
	for (int i = 0; i < k; ++i)
		now = (now * P + dd[i][x]);
	return now;
}

ull geths1(int x) {
	ull now = 0;
	for (int i = 0; i < k; ++i) {
		if (dd[i][x] == 0) {
			cout << -1 << "\n";
			exit(0);
		}
		now = (now * P + dd[i][x] - 1);
	}
	return now;
}

void no() {
	cout << -1 << "\n";
	exit(0);
}


int dp[MAXN];
vector<int> eds[MAXN];

void dfs1(int v, int h) {
	was[v] = 1;
	dp[v] = h;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u, h + 1);
	}
}

int main() {
#ifdef BZ
	freopen("in", "r", stdin);
#endif
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		p[i] = i, sz[i] = 1;
	for (int i = 0; i < k; ++i) {
		go[i] = -1;
		for (int j = 0; j < n; ++j) {
			cin >> dd[i][j];
			if (dd[i][j] == 0)
				go[i] = j;
		}
		if (go[i] == -1)
			no();
	}
	was[go[0]] = 1;
	for (int i = 1; i < k; ++i) {
		int len = dd[0][go[i]];
		for (int j = 0; j < n; ++j) {
			if (dd[0][j] + dd[i][j] == len) {
				way[dd[0][j]] = j;
			}
		}
		for (int i = 0; i <= len; ++i)
			was[way[i]] = 1;
		for (int i = 0; i + 1 <= len; ++i)
			un(way[i], way[i + 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (was[i]) {
			mm[geths(i)] = i;
		}
	}
	vector<pair<int, int>> vv;
	for (int i = 0; i < n; ++i)
		if (!was[i])
			vv.emplace_back(dd[0][i], i);
	sort(ALL(vv));
	for (int i = 0; i < vv.size(); ++i) {
		int x = vv[i].second;
		ull now = geths1(x);
		if (!mm.count(now))
			no();
		un(mm[now], x);
		mm[geths(x)] = x;
	}
	if (ed.size() != n - 1) {
		no();
	}
	for (auto x: ed) {
		eds[x.first].push_back(x.second);
		eds[x.second].push_back(x.first);
	}
	for (int i = 0; i < k; ++i) {
		memset(was, 0, sizeof(was));
		dfs1(go[i], 0);
		for (int j = 0; j < n; ++j)
			if (dp[j] != dd[i][j])
				no();
	}
	for (auto x: ed)
		cout << x.first + 1 << " " << x.second + 1 << "\n";
	return 0;
}