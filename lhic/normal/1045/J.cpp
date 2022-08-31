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

using hsh = ull;
const int MAXN = 120000;
const int LOG = 20;
const hsh P = 23917;

int n;
vector<pair<int, char>> eds[MAXN];
int aa[MAXN];
int bb[MAXN];
string s[MAXN];
int up[MAXN][LOG];
char pc[MAXN];
int tm1;
int tin[MAXN];
int tout[MAXN];
int h[MAXN];

void dfs1(int v, int p) {
	tin[v] = tm1++;
	up[v][0] = p;
	for (int i = 1; i < LOG; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (auto e: eds[v]) {
		if (e.first == p)
			continue;
		h[e.first] = h[v] + 1;
		pc[e.first] = e.second;
		dfs1(e.first, v);
	}
	tout[v] = tm1;
}

bool is_p(int a, int b) {
	return tin[a] <= tin[b] && tin[b] < tout[a];
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

int goup(int a, int h) {
	for (int i = LOG - 1; i >= 0; --i) {
		if (h >= (1 << i))
			h -= (1 << i), a = up[a][i];
	}
	return a;
}

hsh geths(const string &s) {
	hsh hs = 0;
	for (int i = 0; i < s.size(); ++i)
		hs = hs * P + s[i];
	return hs;
}

hsh pw[MAXN];
int ans[MAXN];
vector<hsh> vv;
vector<tuple<hsh, int, int>> go[MAXN];

void add(int v, hsh hs, int k, int d) {
	go[v].emplace_back(hs, k, d);
}

int lst[MAXN * 2];
int cc[MAXN * 2];
vector<char> st;

void dfs2(int v, int p) {
	if (v != 0)
		st.push_back(pc[v]);
	vector<pair<int, int>> undo;
	hsh hs = 0;
	for (int i = (int)st.size() - 1; i >= 0 && i >= (int)st.size() - 100; --i) {
		hs = hs * P + st[i];
		int pos = lower_bound(ALL(vv), hs) - vv.begin();
		if (pos == vv.size() || vv[pos] != hs)
			continue;
		undo.emplace_back(pos, lst[pos]);
		++cc[pos];
	}

	for (auto q: go[v]) {
		hsh hs; int k, d;
		tie(hs, k, d) = q;
		int pos = lower_bound(ALL(vv), hs) - vv.begin();
		if (pos == vv.size() || vv[pos] != hs)
			continue;
		ans[k] += d * cc[pos];
	}
	for (auto e: eds[v]) {
		if (e.first == p)
			continue;
		dfs2(e.first, v);
	}

	for (auto p: undo) {
		--cc[p.first];
		lst[p.first] = p.second;
	}
	if (v != 0)
		st.pop_back();
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	pw[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pw[i] = (pw[i - 1] * P);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		char c;
		cin >> a >> b;
		--a, --b;
		cin >> c;
		eds[a].emplace_back(b, c);
		eds[b].emplace_back(a, c);
	}
	dfs1(0, 0);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> aa[i] >> bb[i];
		--aa[i], --bb[i];
		cin >> s[i];
		int x = lca(aa[i], bb[i]);
		int a = aa[i];
		int b = bb[i];
		int ga = a;
		if (h[a] - h[x] > s[i].size() - 1)
			ga = goup(a, h[a] - h[x] - (s[i].size() - 1));
		int gb = b;
		if (h[b] - h[x] > s[i].size() - 1)
			gb = goup(b, h[b] - h[x] - (s[i].size() - 1));
		string s2;
		string tmp;
		int cur = ga;
		while (cur != x)
			s2 += pc[cur], cur = up[cur][0];
		cur = gb;
		while (cur != x)
			tmp += pc[cur], cur = up[cur][0];
		reverse(ALL(tmp));
		s2 += tmp;
		hsh hs = geths(s[i]);
		if (s2.size() >= s[i].size()) {
			hsh now = 0;
			for (int j = 0; j < s[i].size(); ++j)
				now = now * P + s2[j];
			if (now == hs)
				++ans[i];
			for (int j = s[i].size(); j < s2.size(); ++j) {
				now = now * P + s2[j];
				now -= pw[s[i].size()] * s2[j - s[i].size()];
				if (now == hs)
					++ans[i];
			}
		}
		vv.push_back(hs);
		add(a, hs, i, 1);
		add(ga, hs, i, -1);
		reverse(ALL(s[i]));
		hs = geths(s[i]);
		vv.push_back(hs);
		add(b, hs, i, 1);
		add(gb, hs, i, -1);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv)) - vv.begin());
	for (int i = 0; i < vv.size(); ++i)
		lst[i] = -1, cc[i] = 0;
	dfs2(0, -1);
	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
	return 0;
}