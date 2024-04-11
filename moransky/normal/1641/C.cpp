// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, q;

bool ban[N];

int f[N];

set<int> s;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

int d[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

void inline pushup(int p) {
	d[p] = max(d[ls], d[rs]);
}

void build(int p, int l, int r) {
	d[p] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

void change(int p, int l, int r, int x, int y) {
	if (l == r){
		chkMax(d[p], y);
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y);
	else change(rs, mid + 1, r, x, y);
	pushup(p);
}

int query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return d[p];
	int mid = (l + r) >> 1;
	int ret = 0;
	if (x <= mid) chkMax(ret, query(ls, l, mid, x, y));
	if (mid < y) chkMax(ret, query(rs, mid + 1, r, x, y));
	return ret;
}

void inline bd(int l, int r) {
	for (int i = find(l); i <= r; i = find(i)) {
		ban[i] = 1;
		s.erase(i);
		f[i] = i + 1;
	}
}

void inline ins(int l, int r) {
	change(1, 1, n, r, l);
}

void inline ask(int x) {
	if (ban[x]) puts("NO");
	else {
		auto o = s.lower_bound(x);
		--o;
		int L = max((*o) + 1, 1);
		o = s.lower_bound(x);
		++o; 
		int R = min((*o) - 1, n);
		if (query(1, 1, n, L, R) >= L) puts("YES");
		else puts("N/A");
	}
}

int main() {
	read(n), read(q);
	s.clear();
	for (int i = 0; i <= n + 1; i++) s.insert(i);
	for (int i = 1; i <= n + 1; i++) f[i] = i, ban[i] = 0;
	build(1, 1, n);
	while (q--) {
		int op; read(op);
		if (op == 0) {
		 	int l, r, x; read(l), read(r), read(x);
		 	if (!x) bd(l, r);
		 	else ins(l, r);
		} else {
			int x; read(x);
			ask(x);
		}
	}
	
    return 0;
}