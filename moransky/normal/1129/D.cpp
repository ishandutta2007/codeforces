// Skyqwq
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5, S = 325, P = 998244353;

typedef pair<int, int> PII;

int n, k, a[N], tag[N], c[N], L[N], R[N], pos[N], t, pre[N], cnt[N];
int f[N];

vector<PII> b[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

void inline rebuild(int p) {
	b[p].clear();
	for (int i = L[p]; i <= R[p]; i++) {
		c[i] += tag[p];
		b[p].pb(mp(c[i], f[i]));
	}
	tag[p] = 0;
	sort(b[p].begin(), b[p].end());
	for (int i = 1; i < b[p].size(); i++)
		add(b[p][i].se, b[p][i - 1].se);
}

void inline add(int l, int r, int k) {
	if (l == 0) l++;
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) {
			c[i] += k;
		}
		rebuild(p);
	} else {
		for (int i = l; i <= R[p]; i++) c[i] += k;
		rebuild(p);
		for (int i = p + 1; i < q; i++) {
			tag[i] += k;
		}
		for (int i = L[q]; i <= r; i++) c[i] += k;
		rebuild(q);
	}
}

int inline query(int l, int r) {
	int p = pos[l], q = pos[r], res = 0;
	if (p == q) {
		for (int i = l; i <= r; i++)
			if (c[i] + tag[p] <= k) add(res, f[i]);
	} else {
		for (int i = l; i <= R[p]; i++) 
			if (c[i] + tag[p] <= k) add(res, f[i]);
		for (int i = L[q]; i <= r; i++)
			if (c[i] + tag[p] <= k) add(res, f[i]);
		for (int i = p + 1; i < q; i++) {
			int t = upper_bound(b[i].begin(), b[i].end(), mp(k - tag[i] + 1, 0)) - b[i].begin() - 1;
			if (t >= 0) add(res, b[i][t].se);
		}
	}
	return res;
}

int main() {
	read(n), read(k); ++n; t = sqrt(n);
	for (int i = 1; i <= n; i++) {
		pos[i] = (i - 1) / t + 1;
		if (!L[pos[i]]) L[pos[i]] = i;
		R[pos[i]] = i;
	}
	for (int i = 2; i <= n; i++) {
		read(a[i]);
		pre[i] = cnt[a[i]];
		cnt[a[i]] = i;
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (pre[i]) {
			int t = pre[i];
			add(pre[t], t - 1, -1);
		}
		add(pre[i], i - 1, 1);
		f[i] = query(1, i - 1);
		if (R[pos[i]] == i) rebuild(pos[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}