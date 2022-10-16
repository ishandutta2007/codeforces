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

const int N = 1e5 + 5;

int n, a[N], q, k, L[N << 2], R[N << 2];

typedef unsigned long long ULL;

ULL pw[N], B = 100007, val[N];

struct Node {
	ULL ah, al, bh, bl;
	bool o;
} t[N << 2];

Node operator + (Node x, Node y) {
	Node z;	
	z.ah = x.ah, z.al = x.al;
	z.bh = y.bh, z.bl = y.bl;
	z.o = x.o | y.o;
	if (x.bl > y.al) {
		x.bl -= y.al;
		x.bh -= pw[x.bl] * y.ah;
		z.bh = z.bh * pw[x.bl] + x.bh;
		z.bl += x.bl;
	} else if (x.bl < y.al) {
		y.al -= x.bl;
		y.ah -= pw[y.al] * x.bh;
		z.ah = z.ah * pw[y.al] + y.ah;
		z.al += y.al;
	} else {
//		z.o |= (x.bh != y.ah);
	}
	return z;
}



Node inline get(int x) {
	if (x > 0) {
		return (Node) { 0, 0, val[x], 1, 0 };
	} else {
		return (Node) { val[-x], 1, 0, 0, 0 };
	}
}

#define ls (p << 1)
#define rs (p << 1 | 1)

Node now;

int K;

void inline getHl(int p, int l, int r) {
	if (now.al == K) return;
	if ((now + t[p]).al <= K) {
		now = now + t[p];
		return;
	}
	int mid = (l + r) >> 1;
	getHl(ls, l, mid);
	getHl(rs, mid + 1, r);
	return ;
}

void inline getHr(int p, int l, int r) {
	if (now.bl == K) return;
	if ((t[p] + now).bl <= K) {
		now = t[p] + now;
		return;
	}
	int mid = (l + r) >> 1;
	getHr(rs, mid + 1, r);
	getHr(ls, l, mid);
	return ;
}



void inline pushup(int p) {
	t[p] = t[ls] + t[rs];
	int w = min(t[ls].bl, t[rs].al);
	if (w) {
		K = w;
		now = (Node) { 0, 0, 0, 0, 0 };
		getHr(ls, L[ls], R[ls]);
		ULL A = now.bh;
		K = w;
		now = (Node) { 0, 0, 0, 0, 0 };
		getHl(rs, L[rs], R[rs]);
		ULL B = now.ah;
		if (A != B) t[p].o = 1;
	}
}


void build(int p, int l, int r) {
	L[p] = l, R[p] = r;
	if (l == r) {
		t[p] = get(a[r]);
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
void change(int p, int l, int r, int x, int y) {
	if (l == r) {
		t[p] = get(y);
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, y);
	else change(rs, mid + 1, r, x, y);
	pushup(p);
}
Node query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return t[p];
	int mid = (l + r) >> 1;
	if (y <= mid) return query(ls, l, mid, x, y);
	if (x > mid) return query(rs, mid + 1, r, x, y);
	Node X = query(ls, l, mid, x, y), Y = query(rs, mid + 1, r, x, y);
	Node ret = X + Y;
	int w = min(X.bl, Y.al);
	if (w) {
		K = w;
		now = (Node) { 0, 0, 0, 0, 0 };
		getHr(ls, L[ls], R[ls]);
		ULL A = now.bh;
		K = w;
		now = (Node) { 0, 0, 0, 0, 0 };
		getHl(rs, L[rs], R[rs]);
		ULL B = now.ah;
		if (A != B) ret.o = 1;
	}
	return ret;
}

mt19937 rnd(time(0) ^ ((unsigned long long)(new char)));

int main() {
	//freopen("1.in", "r", stdin);
	read(n); read(k);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) read(a[i]), pw[i] = pw[i - 1] * B;
	for (int i = 1; i <= k; i++) val[i] = i;
	shuffle(val + 1, val + k + 1, rnd);
	build(1, 1, n);
	read(q);
	while (q--) {
		int op, x, y; read(op), read(x), read(y);
		if (op == 1) {
			a[x] = y;
			change(1, 1, n, x, y);
		} else {
			Node u = query(1, 1, n, x, y);
			bool o = !u.ah && !u.bh && !u.al && !u.bl && !u.o;
			puts(o ? "Yes" : "No");
		}
	}
    return 0;
}