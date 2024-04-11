#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 410000;

struct st {
	int l, r, n, ans;
};

st qq[MAXN];
int n;
int tm;
int h[MAXN];
vector<int> eds[MAXN];
int go[MAXN];
int ans[MAXN];
int was[MAXN];

bool cmp(st a, st b) {
	return a.r != b.r ? a.r > b.r : a.l < b.l;
}

struct node {
	int go[26];
	int suf, len;
};

node mem[MAXN];
int last;
int memcnt;
int newn() {
	memset(mem[memcnt].go, 255, sizeof(mem[memcnt].go));
	mem[memcnt].suf = -1;
	mem[memcnt].len = 0;
	return memcnt++;
}


void addc(int c) {
	int p = last;
	last = newn();
	mem[last].len = mem[p].len + 1;
	while (p != -1 && mem[p].go[c] == -1)
		mem[p].go[c] = last, p = mem[p].suf;
	if (p == -1) {
		mem[last].suf = 0;
		return;
	}
	int q = mem[p].go[c];
	if (mem[q].len == mem[p].len + 1) {
		mem[last].suf = q;
	}
	else {
		int cl = newn();
		mem[cl] = mem[q];
		mem[q].suf = cl;
		mem[last].suf = cl;
		mem[cl].len = mem[p].len + 1;
		while (p != -1 && mem[p].go[c] == q)
			mem[p].go[c] = cl, p = mem[p].suf;
	}
}

vector<int> qv[MAXN];

pair<int, int> rmq[MAXN * 4];
int gr[MAXN];
int pl[MAXN];
int pp[MAXN];
int tin[MAXN];
int tout[MAXN];


void build(int v, int tl, int tr) {
	rmq[v] = make_pair(-1, -1);
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

void upd(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		if (qv[x].empty())
			rmq[v] = make_pair(-1, -1);
		else
			rmq[v] = make_pair(qq[qv[x].back()].l, qv[x].back());
		return;
	}
	int m = (tl + tr) >> 1;
	if (tin[x] < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

pair<int, int> get(int v, int tl, int tr, int x) {
	if (tr <= tin[x] || tout[x] <= tl)
		return make_pair(-1, -1);
	if (tin[x] <= tl && tr <= tout[x])
		return rmq[v];
	int m = (tl + tr) >> 1;
	return max(get(v * 2 + 1, tl, m, x), get(v * 2 + 2, m, tr, x));
}

void buildrmq() {
	build(0, 0, n);
}

void dfs(int v) {
	tin[v] = tm++;
	h[v] = 0;
	for (int u: eds[v]) {
		dfs(u);
		h[v] = max(h[v], h[u] + 1);
	}
	tout[v] = tm;
}

int cls = 1;

struct hld {
	vector<int> vv;
	vector<pair<int, int> > ed;
	vector<pair<int, int> > rmq;
	vector<pair<int, int> > rmqed;
	vector<int> nx;
	int p;
	void add(int v) {
		vv.push_back(v);
	}
	void init(int k) {
		for (int i = 0; i < (int)vv.size(); ++i)
			gr[vv[i]] = k, pl[vv[i]] = i;
		nx.resize(vv.size());
		for (int i = 0; i < (int)vv.size(); ++i) {
			for (int u: eds[vv[i]])
				if (i == (int)vv.size() - 1 || u != vv[i + 1])
					ed.push_back(make_pair(vv[i], u)), pp[u] = ed.size() - 1;
			nx[i] = ed.size();
		}
		rmq.resize(vv.size() * 4, make_pair(-1, -1));
		rmqed.resize(ed.size() * 4, make_pair(-1, -1));
	}
	void updv(int v, int tl, int tr, int x, pair<int, int> y) {
		if (tl + 1 == tr) {
			rmq[v] = y;
			return;
		}
		int m = (tl + tr) >> 1;
		if (x < m)
			updv(v * 2 + 1, tl, m, x, y);
		else
			updv(v * 2 + 2, m, tr, x, y);
		rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	}
	void updv(int x, pair<int, int> y) {
		updv(0, 0, (int)vv.size(), x, y);
	}
	void upde(int v, int tl, int tr, int x, pair<int, int> y) {
		if (tl + 1 == tr) {
			rmqed[v] = y;
			return;
		}
		int m = (tl + tr) >> 1;
		if (x < m)
			upde(v * 2 + 1, tl, m, x, y);
		else
			upde(v * 2 + 2, m, tr, x, y);
		rmqed[v] = max(rmqed[v * 2 + 1], rmqed[v * 2 + 2]);
	}
	void upde(int x, pair<int, int> y) {
		upde(0, 0, (int)ed.size(), x, y);
	}
	pair<int, int> getv(int v, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l)
			return make_pair(-1, -1);
		if (l <= tl && tr <= r)
			return rmq[v];
		int m = (tl + tr) >> 1;
		return max(getv(v * 2 + 1, tl, m, l, r), getv(v * 2 + 2, m, tr, l, r));
	}
	pair<int, int> getv(int l, int r) {
		return getv(0, 0, (int)vv.size(), l, r);
	}
	pair<int, int> gete(int v, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l)
			return make_pair(-1, -1);
		if (l <= tl && tr <= r)
			return rmqed[v];
		int m = (tl + tr) >> 1;
		return max(gete(v * 2 + 1, tl, m, l, r), gete(v * 2 + 2, m, tr, l, r));
	}
	pair<int, int> gete(int x) {
		return gete(0, 0, (int)ed.size(), 0, nx[x]);
	}
};

hld gg[MAXN];

void updv(int v) {
	if (qv[v].empty())
		gg[gr[v]].updv(pl[v], make_pair(-1, -1));
	else
		gg[gr[v]].updv(pl[v], make_pair(mem[v].len + qq[qv[v].back()].l, qv[v].back()));
}

void upde(int u, int v) {
	assert(gr[u] != gr[v]);
	pair<int, int> x = get(0, 0, n, v);
	x.first += mem[u].len;
	gg[gr[u]].upde(pp[v], x);
}

void dfs2(int v, int cnt) {
	was[v] = 1;
	gg[cnt].add(v);
	if (eds[v].empty()) {
		gg[cnt].init(cnt);
		return;
	}
	int mx = -1;
	for (int u: eds[v])
		if (mx == -1 || h[u] > h[mx])
			mx = u;
	dfs2(mx, cnt);
	for (int u: eds[v])
		if (!was[u]) {
			gg[cls].p = v;
			dfs2(u, cls++);
		}
}

void addq(int x) {
	qv[go[qq[x].r]].push_back(x);
	upd(0, 0, n, go[qq[x].r]);
	x = go[qq[x].r];
	updv(x);
	while (gg[gr[x]].p != -1)
		upde(gg[gr[x]].p, gg[gr[x]].vv[0]), x = gg[gr[x]].p;
}

void delq(int x, int p) {
	qq[x].ans = p;
	assert(qv[go[qq[x].r]].back() == x);
	qv[go[qq[x].r]].pop_back();
	upd(0, 0, n, go[qq[x].r]);
	x = go[qq[x].r];
	updv(x);
	while (gg[gr[x]].p != -1)
		upde(gg[gr[x]].p, gg[gr[x]].vv[0]), x = gg[gr[x]].p;
}

void solve(int v, int p) {
	while (true) {
		pair<int, int> x = get(0, 0, n, v);
		if (x.first + mem[v].len >= p)
			delq(x.second, p);
		else
			break;
	}
	while (true) {
		pair<int, int> x = gg[gr[v]].getv(0, pl[v] + 1);
		if (x.first >= p)
			delq(x.second, p);
		else
			break;
	}
	while (true) {
		pair<int, int> x = gg[gr[v]].gete(pl[v]);
		if (x.first >= p)
			delq(x.second, p);
		else
			break;
	}
	if (gg[gr[v]].p != -1)
		solve(gg[gr[v]].p, p);
}

char s[MAXN];
string t;
int hv[30];
int nnx[MAXN];
int ppr[MAXN];
int nx[MAXN];
int pr[MAXN];


namespace aba {


void zf(const string &s, int *z) {
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (r > i)
			z[i] = min(r - i, z[i - l]);
		else
			z[i] = 0;
		while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}
	z[s.size()] = 0;
}

const int MAXN = 210000;

vector<int> gl[MAXN];
vector<int> gr[MAXN];
int fl1[MAXN];
int fl2[MAXN];
int fl[MAXN];
int tm1;
vector<pair<int, int>> dtmp;

void add(int l, int len) {
	gl[l].push_back(l + len * 2);
	gr[l + 2 * len].push_back(l);
}

int z1[MAXN];
int z2[MAXN];

vector<pair<int, int> > run2(string s, int len, int fll) {
	string tmp = s.substr(0, len);
	reverse(tmp.begin(), tmp.end());
	zf(tmp, z1);
	tmp = s.substr(len) + s.substr(0, len);
	zf(tmp, z2);
	++tm1;
	vector<pair<int, int> > ans;
	for (int i = 1; i < len; ++i) {
		if (fl[i] == tm1)
			continue;
		int go = z1[i];
		for (int j = 2 * i; j <= i + go; j += i)
			fl[j] = tm1;
	}
	for (int i = 0; i < len; ++i) {
		int k = len - i;
		if (fl[k] == tm1)
			continue;
		if (s[i] != s[len])
			continue;
		int gl = z1[k];
		int gr = z2[s.size() - len + i];
		gl = min(gl, k - 1);
		for (int j = gl; j >= fll; --j) {
			if (j + gr < k)
				break;
			ans.emplace_back(i - j, k);
		}
	}
	return ans;
}

string s;
int n;

void run(int l, int r) {
	if (l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	run(l, mid);
	run(mid, r);
	auto tt = s.substr(l, r - l);
	vector<pair<int, int>> tmp = run2(tt, mid - l, 0);
	for (auto p: tmp)
		add(p.first + l, p.second);
	reverse(tt.begin(), tt.end());
	tmp = run2(tt, r - mid, 1);
	int xx = r - l - 1;
	for (auto p: tmp) {
		int oth = xx - p.first - 2 * p.second + 1;
		add(l + oth, p.second);
	}
}

vector<tuple<int, ll, ll> > dd[MAXN];
const ll MOD = 1e9 + 7;
ll dp[MAXN];


void solve() {
	s = t;
	n = s.size();
	run(0, n);
	for (int i = 0; i < n; ++i) {
		sort(gl[i].begin(), gl[i].end());
		if (!gl[i].empty()) {
			nnx[i] = gl[i][0];
		}
		else {
			nnx[i] = n + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		sort(gr[i].begin(), gr[i].end());
		if (!gr[i].empty()) {
			ppr[i] = gr[i].back();
		}
		else {
			ppr[i] = -1;
		}
	}
}

};

int rrr[MAXN * 4];

void build2(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rrr[v] = nnx[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build2(v * 2 + 1, tl, m);
	build2(v * 2 + 2, m, tr);
	rrr[v] = min(rrr[v * 2 + 1], rrr[v * 2 + 2]);
}

int rmqget(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return n + 1;
	if (l <= tl && tr <= r) {
		return rrr[v];
	}
	int m = (tl + tr) >> 1;
	return min(rmqget(v * 2 + 1, tl, m, l, r), rmqget(v * 2 + 2, m, tr, l, r));
}


int tmp[26];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int qqq;
	int q = 0;
	cin >> n;
	cin >> t;
	aba::solve();
	build2(0, 0, n);
	fill(tmp, tmp + 26, n);
	for (int i = t.size() - 1; i >= 0; --i) {
		nx[i] = tmp[t[i] - 'a'];
		tmp[t[i] - 'a'] = i;
	}
	fill(tmp, tmp + 26, -1);
	for (int i = 0; i < t.size(); ++i) {
		pr[i] = tmp[t[i] - 'a'];
		tmp[t[i] - 'a'] = i;
	}
	for (int i = 0; i < n; ++i)
		s[i] = t[i];
	//for (int i = 0; i < q; ++i)
	//	scanf("%d%d", &qq[i].l, &qq[i].r), qq[i].n = i, --qq[i].l;
	
	cin >> qqq;

	for (int i = 0; i < qqq; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		if (r - l <= 26) {
			memset(hv, 0, sizeof(hv));
			int fl = 0;
			for (int i = l; i < r; ++i) {
				if (hv[t[i] - 'a'])
					fl = 1;
				hv[t[i] - 'a'] = 1;
			}
			if (!fl) {
				ans[i] = -1;
				continue;
			}
		}
		ans[i] = 4;
		if (nx[l] < r || pr[r - 1] >= l)
			ans[i] = 3;
		if (rmqget(0, 0, n, l, r) <= r)
			ans[i] = 3;
		if (nnx[l] <= r || ppr[r] >= l)
			ans[i] = 2;
		qq[q].l = l;
		qq[q].r = r;
		qq[q].n = i;
		++q;
	}

	//begin
	sort(qq, qq + q, cmp);
	last = newn();
	for (int i = 0; i < n; ++i)
		addc(s[i] - 'a');
	int now = 0;
	go[0] = now;
	for (int i = 0; i < n; ++i)
		now = mem[now].go[s[i] - 'a'], go[i + 1] = now;
	for (int i = 0; i < memcnt; ++i)
		if (mem[i].suf != -1)
			eds[mem[i].suf].push_back(i);
	int n2 = n;
	n = memcnt;
	dfs(0);
	buildrmq();
	gg[0].p = -1;
	dfs2(0, 0);
	now = 0;
	for (int i = n2 - 1; i >= 0; --i) {
		while (now < q && qq[now].r > i)
			addq(now++);
		solve(go[i], i);
	}
	//end


	for (int i = 0; i < q; ++i) {
		int go = qq[i].ans - qq[i].l;
		int l = qq[i].l;
		int r = qq[i].r;
		if (go * 2 >= r - l && (r - l) % (r - l - go) == 0)
			ans[qq[i].n] = 1;
		else if (go != 0)
			ans[qq[i].n] = 2;
	}
	for (int i = 0; i < qqq; ++i)
		cout << ans[i] << "\n";
	return 0;
}