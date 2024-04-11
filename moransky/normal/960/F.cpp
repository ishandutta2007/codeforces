// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, m, rt[N], L = 1e5, idx;

struct T{
	int l, r, v;
} t[N * 18];

#define ls t[p].l
#define rs t[p].r

void change(int &p, int l, int r, int x, int y) {
	if (!p) p = ++idx;
	chkMax(t[p].v, y);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y);
	else change(rs, mid + 1, r, x, y);
}

int query(int p, int l, int r, int x, int y) {
	if (!p) return 0;
	if (x > y) return 0;
	if (x <= l && r <= y) return t[p].v;
	int mid = (l + r) >> 1, res = 0;
	if (x <= mid) chkMax(res, query(ls, l, mid, x, y));
	if (mid < y) chkMax(res, query(rs, mid + 1, r, x, y));
	return res;
}

int main() {
	read(n), read(m);
	int ans = 0;
	while (m--) {
		int a, b, w; read(a), read(b), read(w);
		int v = query(rt[a], 0, L, 0, w - 1);
		change(rt[b], 0, L, w, v + 1);
		chkMax(ans, v + 1);
	}
	printf("%d\n", ans);
    return 0;
}