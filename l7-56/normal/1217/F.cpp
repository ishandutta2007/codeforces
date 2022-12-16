#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 2e5 + 10;
int n,m;
struct ope {
	int op, x, y;
}a[maxn];

int fa[maxn],siz[maxn],tp;
pii sta[maxn];
int get(int x) { return x == fa[x] ? x : get(fa[x]); }
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (siz[x] > siz[y]) swap(x, y);
	sta[++tp] = {x, y};
	fa[x] = y, siz[y] += siz[x];
}
void undo(int tar) {
	while (tp > tar) {
		pii p = sta[tp--];
		fa[p.first] = p.first;
		siz[p.second] -= siz[p.first];
	}
}

int main() {
//	freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	read(n, m);
	int len = sqrt(m);
	for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; ++i) read(a[i].op, a[i].x, a[i].y);
	int cp = (m - 1) / len + 1;
	set <pii> pre;
	int lst = 0;
	for (int k = 1; k <= cp; ++k) {
		set <pii> now;
		int L = (k - 1) * len + 1, R = min(m, k * len);
		for (int i = L; i <= R; ++i) if (a[i].op == 1)
			for (int c = 0; c < 2; ++c) {
				int x = (a[i].x + c - 1) % n + 1, y = (a[i].y + c - 1) % n + 1;
				if (x > y) swap(x, y);
				auto it = pre.find({x, y});
				if (it != pre.end()) pre.erase(it), now.insert({x, y});
			}
		for (pii p : pre) merge(p.first, p.second);
		int t = tp;
		for (int i = L; i<= R; ++i) {
			if (a[i].op == 1) {
				int x = (a[i].x + lst - 1) % n + 1, y = (a[i].y + lst - 1) % n + 1;
				if (x > y) swap(x, y);
				auto it = now.find({x, y});
				if (it == now.end()) now.insert({x, y});
				else now.erase(it);
			}
			else {
				int x = (a[i].x + lst - 1) % n + 1, y = (a[i].y + lst - 1) % n + 1;
				for (pii p : now) merge(p.first, p.second);
				write(lst = get(x) == get(y));
				undo(t);
			}
		}
		undo(0);
		for (pii p : now) pre.insert(p);
	}
	write('\n');
	return 0;
}