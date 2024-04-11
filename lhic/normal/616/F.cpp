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
typedef double ld;

using namespace std;

const int MAXN = 650000;
const int SYM = 256;

ll ans = 0;

char s[MAXN];
int nc[MAXN];
int gc[MAXN];
int cost[MAXN];
pair<int, int> rmq[MAXN * 4];
int fs[MAXN];
int p[MAXN];
int lcp[MAXN];
ll pr[MAXN];
set<int> ss;
int st[MAXN];
int en[MAXN];
int len[MAXN];
int m;
int newc[MAXN];
int cc[MAXN];
int newp[MAXN];
int c[MAXN];






void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = make_pair(lcp[tl], tl);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return make_pair(MAXN, 0);
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

void init() {
	for (int i = 0; i < m; ++i)
		nc[i] = gc[p[i]];
	pr[0] = 0;
	for (int i = 0; i < m; ++i)
		pr[i + 1] = pr[i] + nc[i];
	ss.clear();
	for (int i = 0; i < m; ++i)
		if (s[i] == '#' || s[i] == 1)
			ss.insert(i);
	for (int i = 0; i < m; ++i) {
		int x = *ss.lower_bound(p[i]);
		fs[i] = x - p[i];
	}
	for (int i = 0; i < m - 1; ++i)
		lcp[i] = min(lcp[i], min(fs[i], fs[i + 1]));
	lcp[m - 1] = 0;
	build(0, 0, m);
}


void dfs(int l, int r, int lst) {
	if (l == r) {
		if (fs[l] > lst)
			ans = max(ans, nc[l] * (ll)fs[l]);
		return;
	}
	auto gg = get(0, 0, m, l, r);
	if (gg.first > lst)
		ans = max((ll)gg.first * (ll)(pr[r + 1] - pr[l]), ans);
	dfs(l, gg.second, max(lst, gg.first));
	dfs(gg.second + 1, r, max(lst, gg.first));
}

int nm(int x, int n) {
	while (x < 0)
		x += n;
	while (x >= n)
		x -= n;
	return x;
}

void makesa(char *s, int n) {
	for (int i = 0; i < n; ++i)
		c[i] = s[i], ++cc[c[i] + 1];
	for (int i = 0; i < SYM; ++i)
		cc[i + 1] += cc[i];
	for (int i = 0; i < n; ++i)
		p[cc[c[i]]++] = i;
	for (int k = 0; (1 << k) < n; ++k) {
		for (int i = 0; i < n; ++i)
			p[i] = nm(p[i] - (1 << k), n);
		memset(cc, 0, sizeof(cc));
		for (int i = 0; i < n; ++i)
			++cc[c[i] + 1];
		for (int i = 0; i < max(n, SYM); ++i)
			cc[i + 1] += cc[i];
		for (int i = 0; i < n; ++i)
			newp[cc[c[p[i]]]++] = p[i];
		memcpy(p, newp, sizeof(newp[0]) * n);
		newc[p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			if (c[p[i]] == c[p[i - 1]] && c[nm(p[i] + (1 << k), n)] == c[nm(p[i - 1] + (1 << k), n)])
				newc[p[i]] = newc[p[i - 1]];
			else
				newc[p[i]] = newc[p[i - 1]] + 1;
		}
		memcpy(c, newc, sizeof(newc[0]) * n);
	}
	if (n == 1) {
		lcp[0] = 0;
		return;
	}
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		int now = c[i];
		if (now == n - 1) {
			lst = 0;
			continue;
		}
		--lst;
		if (lst < 0)
			++lst;
		while (s[i + lst] == s[p[now + 1] + lst])
			++lst;
		lcp[now] = lst;
	}
}


int n;

int main() {
	scanf("%d", &n);
	char *s2 = s;
	for (int i = 0; i < n; ++i) {
		scanf(" %s", s2);
		len[i] = strlen(s2);
		st[i] = s2 - s;
		en[i] = st[i] + len[i];
		s2 += len[i];
		s2[0] = '#';
		++s2;
	}

	for (int i = 0; i < n; ++i)
		scanf("%d", cost + i);

	for (int i = 0; i < n; ++i)
		for (int j = st[i]; j < en[i]; ++j)
			gc[j] = cost[i];

	m = s2 - s;
	s[m - 1] = 1;

	makesa(s, m); //array & lcp
	
	init(); //nc & pref sums & rmq on lcp & find first #

	dfs(0, m - 1, 0);

	cout << ans << "\n";

	return 0;
}