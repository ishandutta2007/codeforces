// Skyqwq
#include <bits/stdc++.h>

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

const int N = 3e5 + 5, L = 19;

int n, q, k, a[N], mn[N][L], g[N];

LL ans[N];

void inline ST_prework() {
	g[0] = -1;
	for (int i = 1; i <= n; i++)
		mn[i][0] = a[i], g[i] = g[i >> 1] + 1;
	for (int j = 1; j <= g[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}

int inline queryMn(int l, int r) {
	if (l > r) return 0;
	int k = g[r - l + 1];
	return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

struct E{
	int x, y, id, p;
	bool operator < (const E &b) const {
		return x < b.x;
	}
};

vector<int> w[N];
vector<E> t[N]; 

int inline get(int x) {
	return (x - 1) / k;
}

int s[N], top, tag[N << 2], len[N << 2];
LL dat[N << 2];

#define ls p << 1
#define rs p << 1 | 1

void inline pushup(int p) {
	dat[p] = dat[ls] + dat[rs];
}

void inline add(int p, int k) {
	tag[p] += k, dat[p] += 1ll * len[p] * k;
}

void inline pushdown(int p) {
	if (tag[p]) {
		add(ls, tag[p]), add(rs, tag[p]);
		tag[p] = 0;
	}
}

void build(int p, int l, int r) {
	len[p] = r - l + 1;
	tag[p] = dat[p] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

void change(int p, int l, int r, int x, int y, int k) {
	if (x <= l && r <= y) {
		add(p, k);
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y, k);
	if (mid < y) change(rs, mid + 1, r, x, y, k);
	pushup(p);
}

LL query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return dat[p];
	pushdown(p);
	int mid = (l + r) >> 1; LL res = 0;
	if (x <= mid) res += query(ls, l, mid, x, y);
	if (mid < y) res += query(rs, mid + 1, r, x, y);
	return res;
}

void inline work(int c) {
	int len = w[c].size(), tas = t[c].size();
	if (!len || !tas) return;
	build(1, 0, len - 1);
	top = 0;
	s[0] = len;
	for (int i = len - 1, j = tas - 1; i >= 0; i--) {
		while (top && w[c][s[top]] >= w[c][i]) {
			change(1, 0, len - 1, s[top], s[top - 1] - 1, - w[c][s[top]]);
			top--;
		}
		s[++top] = i;
		change(1, 0, len - 1, s[top], s[top - 1] - 1, w[c][i]);
		while (j >= 0 && t[c][j].x == i) {
			E u = t[c][j];
			int val = a[u.p];
			ans[u.id] += query(1, 0, len - 1, i, u.y);
			j--;
		}
	}
}


int main() {
	read(n), read(q), read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	ST_prework();
	for (int i = 1; i <= q; i++) {
		int L, R; read(L), read(R);
		 
		int X = get(L);
		int l = get(L), r = get(R);
		if (((L - 1) % k) > ((R - 1) % k)) r--;
		int nr = r;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (queryMn(L, L + (mid - X) * k) == a[L]) l = mid;
			else r = mid - 1;
		}
		ans[i] += (r - get(L) + 1ll) * a[L];
		if (r <= nr - 1) {
			E u = (E) { r, nr - 1, i, L };
			int x = L % k;
			t[x].pb(u);
		}
	}
	for (int i = 0; i < k; i++) {
		sort(t[i].begin(), t[i].end());
		int nd = i == 0 ? k : i;
		for (int j = nd + k; j <= n; j += k) {
			w[i].pb(queryMn(j - k + 1, j));	
		}
		work(i);
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0; 
}