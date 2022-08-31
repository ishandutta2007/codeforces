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

const int MAXN = 510000;

int n;
char s[MAXN];
int dd[MAXN * 4];
int mn[MAXN * 4];
int rmq[MAXN * 4];
int p[MAXN];
int p2[MAXN];
int c[MAXN];
int c2[MAXN];
int lcp[MAXN];
int gg[MAXN];
int cnt[MAXN];
vector<int> vv[MAXN * 2];

void add(int v, int tl, int tr, int l, int r, int d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] += d;
		mn[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]) + dd[v];
}

int findm(int v, int tl, int tr, int x) {
	if (mn[v] >= x)
		return tl - 1;
	if (tl + 1 == tr)
		return tl;
	int m = (tl + tr) >> 1;
	if (mn[v * 2 + 2] + dd[v] < x)
		return findm(v * 2 + 2, m, tr, x - dd[v]);
	else
		return findm(v * 2 + 1, tl, m, x - dd[v]);
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = lcp[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

int get2(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return MAXN;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get2(v * 2 + 1, tl, m, l, r), get2(v * 2 + 2, m, tr, l, r));
}

int nm(int a, int b) {
	return (a >= b ? a - b : (a < 0 ? a + b : a));
}

void init() {
	reverse(s, s + n);
	s[n] = 0;
	++n;
	//calc sufarray
	
	for (int i = 0; i < n; ++i)
		c[i] = s[i];

	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i)
		++cnt[c[i] + 1];
	for (int i = 1; i < MAXN; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[cnt[c[i]]++] = i;

	for (int k = 1; k < n; k *= 2) {
		for (int i = 0; i < n; ++i)
			p[i] = nm(p[i] - k, n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i)
			++cnt[c[i] + 1];
		for (int i = 1; i < MAXN; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i)
			p2[cnt[c[p[i]]]++] = p[i];
		memcpy(p, p2, sizeof(p[0]) * n);
		c2[p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			if (c[p[i]] == c[p[i - 1]] && c[nm(p[i] + k, n)] == c[nm(p[i - 1] + k, n)])
				c2[p[i]] = c2[p[i - 1]];
			else
				c2[p[i]] = c2[p[i - 1]] + 1;
		}
		memcpy(c, c2, sizeof(c[0]) * n);
	}

	//calc lcp
	
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		lst = max(0, lst - 1);
		if (c[i] == n - 1)
			continue;
		while (s[i + lst] == s[p[c[i] + 1] + lst])
			++lst;
		lcp[c[i]] = lst;
	}
	

	--n;
	reverse(s, s + n);
	for (int i = 0; i < n; ++i)
		p[i] = p[i + 1], lcp[i] = lcp[i + 1];
	for (int i = 0; i < n; ++i)
		p[i] = n - 1 - p[i];
	vector<int> st;
	build(0, 0, n);
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && p[st.back()] > p[i])
			st.pop_back();
		if (!st.empty())
			gg[p[i]] = max(gg[p[i]], get2(0, 0, n, st.back(), i));
		st.push_back(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && p[st.back()] > p[i])
			st.pop_back();
		if (!st.empty())
			gg[p[i]] = max(gg[p[i]], get2(0, 0, n, i, st.back()));
		st.push_back(i);
	}
}


int get(int x) {
	return gg[x] + 1;
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	init();
	vv[MAXN].push_back(-1);
	int now = MAXN;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			add(0, 0, n, 0, i + 1, -1);
			now += 1;
		}
		else {
			add(0, 0, n, 0, i + 1, 1);
			now -= 1;
		}
		int lb = findm(0, 0, n, 0);
		int len = get(i);
		int rb = i - len + 1;
		rb = max(rb, lb);
		ans += lower_bound(vv[now].begin(), vv[now].end(), rb) - lower_bound(vv[now].begin(), vv[now].end(), lb);
		vv[now].push_back(i);
	}

	cout << ans << "\n";

	return 0;
}