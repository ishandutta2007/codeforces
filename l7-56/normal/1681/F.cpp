#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 5e5 + 10;
int n;
namespace LCT {
	struct node {
		int son[2], fa, rev, siz, siz2;
	} t[maxn];
	#define pa t[x].fa
	#define ls t[x].son[0]
	#define rs t[x].son[1]
	bool get(int x) { return t[pa].son[1] == x; }
	bool isroot(int x) { return t[pa].son[0] != x && t[pa].son[1] != x; }
	void push_up(int x) {
		t[x].siz = t[ls].siz + t[rs].siz + 1 + t[x].siz2;
	}
	void tagrev(int x) { t[x].rev ^= 1, swap(ls, rs); }
	void push_down(int x) {
		if (t[x].rev) {
			if (ls) tagrev(ls);
			if (rs) tagrev(rs);
			t[x].rev = 0;
		}
	}
	void pushall(int x) { if (!isroot(x)) pushall(pa); push_down(x); }
	void rotate(int x) {
		int y = t[x].fa, z = t[y].fa, f = get(x);
		if (!isroot(y)) t[z].son[get(y)] = x;
		t[x].fa = z, t[y].son[f] = t[x].son[!f], t[t[y].son[f]].fa = y;
		t[x].son[!f] = y, t[y].fa = x, push_up(y), push_up(x);
	}
	void splay(int x) {
		pushall(x);
		for (; !isroot(x); rotate(x))
			if (!isroot(pa)) rotate(get(x) == get(pa) ? pa : x);
		push_up(x);
	}
	void access(int x) {
		for (int y = 0; x; y = x, x = pa)
			splay(x), t[x].siz2 += t[rs].siz - t[y].siz, rs = y, push_up(x);
	}
	void makeroot(int x) { access(x), splay(x), tagrev(x); }
	int findroot(int x) {
		access(x), splay(x);
		while (ls) push_down(x), x = ls;
		splay(x);
		return x;
	}
	void link(int x, int y) { makeroot(x), makeroot(y), t[x].fa = y, t[y].siz2 += t[x].siz; }
	void split(int x, int y) { makeroot(x), access(y), splay(y); }
	void cut(int x, int y) { split(x, y), t[x].fa = t[y].son[0] = 0, push_up(x); }
}

vector <pii> a[maxn];

int main() {
	read(n);
	for (int i = 1; i < n; ++i) {
		int u, v, x; read(u, v, x);
		LCT :: link(u, v), a[x].push_back({u, v});
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (pii p : a[i]) LCT :: cut(p.fir, p.sec);
		for (pii p : a[i]) {
			LCT :: makeroot(p.fir);
			LCT :: makeroot(p.sec);
			ans += 1ll * (LCT :: t[p.fir].siz) * (LCT :: t[p.sec].siz);
		}
		for (pii p : a[i]) LCT :: link(p.fir, p.sec);
	}
	write(ans, '\n');
	return 0;
}