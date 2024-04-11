#include <bits/stdc++.h>

using namespace std;

	const int N = 300300;

long long ans;

struct Info {
	vector<pair<int*,int>> val;
	void go() {
		for (auto p : val) {
			*p.first = p.second;
		}
	}
};

vector<Info> val;
int par[N + N], cnt[2][N + N];

int anc(int u) {
	return par[u] == u ? u : anc(par[u]);
}

bool join(int u,int v,long long &ans) {
	u = anc(u);
	v = anc(v);
	if (u == v) {
		return 0;
	}
	vector<pair<int*,int>> nw;
	if (cnt[0][u] + cnt[1][u] < cnt[0][v] + cnt[1][v]) {
		swap(u, v);
	}
	nw.push_back({par + v, v});
	nw.push_back({cnt[0] + u, cnt[0][u]});
	nw.push_back({cnt[1] + u, cnt[1][u]});
	val.push_back({nw});
	par[v] = u;
	ans -= 1LL * cnt[0][u] * cnt[1][u];
	ans -= 1LL * cnt[0][v] * cnt[1][v];
	cnt[0][u] += cnt[0][v];
	cnt[1][u] += cnt[1][v];
	ans += 1LL * cnt[0][u] * cnt[1][u];	 
	return 1;
}

void rollback() {
	val.back().go();
	val.pop_back();
}

void init() {
	for (int i = 0; i < N + N; ++i) {
		par[i] = i;
		cnt[i >= N][i] = 1;
	}
}

vector<pair<int,int>> t[N << 2];
long long res[N];
map<pair<int,int>, int> lst;

void add(int v,int l,int r,int L,int R,pair<int,int> e) {
	if (L > r || R < l) return;
	if (L <= l && r <= R) {
		t[v].push_back(e);
		return;
	}
	int md = (l + r) >> 1;
	add(v << 1, l, md, L, R, e);
	add(v << 1 | 1, md + 1, r, L, R, e);
}

void solve(int v,int l,int r,long long cur) {
	int nw = 0;
	for (auto e : t[v]) {
		nw += join(e.first, e.second, cur);
	}
	if (l == r) {
		res[l] = cur;
	} else {
		int md = (l + r) >> 1;
		solve(v << 1, l, md, cur);
		solve(v << 1 | 1, md + 1, r, cur);
	}
	while (nw--) {
		rollback();
	}
}

int main() {
	int q;
	scanf("%d", &q);
	init();
	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		y += N;
		pair<int, int> e = {x, y};
		if (lst.count(e)) {
			add(1, 1, q, lst[e], i - 1, e);
			lst.erase(e);
		} else {
			lst[e] = i;
		}
	}
	for (auto e : lst) {
		add(1, 1, q, e.second, q, e.first);
	}
	solve(1, 1, q, 0);
	for (int i = 1; i <= q; ++i) {
		printf("%lld ", res[i]);
	}
}