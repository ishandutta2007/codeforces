#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

const int N = 2e5 + 15;

// hash.cpp @ fstqwq/CodeForcesTemplate
const int HA = 2;
const int PP[] = {318255569, 259906247, 66604919, 19260817},
	 	  QQ[] = {1010451419, 1011111133, 1021111159, 1033111117};
int pw[HA][N];
struct hashInit { hashInit () {
	for (int h = 0; h < HA; h++) {
		pw[h][0] = 1;
		for (int i = 1; i < N; i++) pw[h][i] = int((LL)pw[h][i - 1] * PP[h] % QQ[h]);
	}
} } __init_hash;
struct Hash {
	int v[HA], len;
	Hash () {memset(v, 0, sizeof v); len = 0;}
	Hash (int x) { for (int h = 0; h < HA; h++) v[h] = x; len = 1; }
	friend Hash operator + (const Hash &a, const Hash &b) {
		Hash ret; ret.len = a.len + b.len;
		for (int h = 0; h < HA; h++) 
			ret.v[h] = int(((LL)a.v[h] * pw[h][b.len] + b.v[h]) % QQ[h]);
		return ret;
	}
	friend Hash operator + (const Hash &a, const int &b) {
		Hash ret; ret.len = a.len + 1;
		for (int h = 0; h < HA; h++) 
			ret.v[h] = int(((LL)a.v[h] * PP[h] + b) % QQ[h]);
		return ret;
	}
	friend Hash operator + (const int &a, const Hash &b) {
		Hash ret; ret.len = b.len + 1;
		for (int h = 0; h < HA; h++) 
			ret.v[h] = int(((LL)a * pw[h][b.len] + b.v[h]) % QQ[h]);
		return ret;
	}
	friend Hash operator - (const Hash &a, const Hash &b) {
		Hash ret; ret.len = a.len - b.len;
		for (int h = 0; h < HA; h++) {
			ret.v[h] = int((a.v[h] - (LL)pw[h][b.len] * b.v[h]) % QQ[h]);
			if (ret.v[h] < 0) ret.v[h] += QQ[h];
		}
		return ret;
	}
	friend bool operator == (const Hash &a, const Hash &b) {
		for (int h = 0; h < HA; h++) 
			if (a.v[h] != b.v[h]) return false;
		return a.len == b.len;
	}
};


char a[N];

// segtree.cpp @ fstqwq/CodeForcesTemplate
template <class V> class Tree {
	struct Node {
		int l, r;
		V v;
	} t[N * 2] ;
	int tcnt, L, R;
	int build(int l, int r) {
		int x = ++tcnt;
		if (l < r) {
			int mid = (l + r) / 2;
			t[x].l = build(l, mid);
			t[x].r = build(mid + 1, r);
			t[x].v = t[t[x].l].v + t[t[x].r].v;
		}
		else {
			t[x].l = t[x].r = 0;
			if (a[l] == '1') t[x].v = V(Hash(), Hash());
			else t[x].v = V(Hash(l % 2 + 1), Hash((l + 1) % 2 + 1)); 
		}
		return x;
	}
	V qry(int x, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return t[x].v;
		int mid = (l + r) / 2;
		if (qr <= mid) return qry(t[x].l, l, mid, ql, qr);
		if (ql >  mid) return qry(t[x].r, mid + 1, r, ql, qr);
		return qry(t[x].l, l, mid, ql, mid) + qry(t[x].r, mid + 1, r, mid + 1, qr);
	}
public:
	Tree () {}
	void init(int l, int r) {
		L = l, R = r;
		tcnt = 0;
		build(l, r);
	}
	inline V qry(int l, int r) {return qry(1, L, R, l, r);}
};


struct V {
	Hash a, b;
	V () {}
	V (Hash x, Hash y) {a = x, b = y;}
	friend V operator + (const V &c, const V &d) {
		return V(c.a + d.a, c.b + d.b);
	}
};


int n, Q;
Tree<V> t;
int main() {
	read(n);
	scanf("%s", a + 1);
	t.init(1, n);
	read(Q);
	for (int i = 1; i <= Q; i++) {
		int l, r, len;
		read(l); read(r); read(len);
		V a1 = t.qry(l, l + len - 1);
		V a2 = t.qry(r, r + len - 1);
	//	cerr << a1.a.v[0] << " " << a2.a.v[0] << endl;
		puts((l & 1 ? a1.a : a1.b) == (r & 1 ? a2.a : a2.b) ? "YES" : "NO");
	}

}