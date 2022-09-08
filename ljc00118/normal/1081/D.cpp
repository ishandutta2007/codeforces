#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

struct ele {
	int l, r, val;
	bool operator < (const ele A) const { return val < A.val; }
} G[N];

int f[N], tag[N], t[N], ans[N], qwq[N];
int n, m, k, cnt;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); } 

int main() {
	read(n); read(m); read(k);
	for(register int i = 1; i <= n; i++) f[i] = i;
	for(register int i = 1; i <= k; i++) { int a; read(a); qwq[i] = a; tag[a] = a; } cnt = k;
	for(register int i = 1; i <= m; i++) {
		int a, b, c; read(a); read(b); read(c);
		G[i] = (ele) {a, b, c};
	}
	sort(G + 1, G + m + 1); int maxn;
	for(register int i = 1; i <= m; i++) {
		if(cnt == 1) break;
		int x = find(G[i].l), y = find(G[i].r);
		if(x == y) continue;
		if(tag[x] > 0 && tag[y] > 0) tag[x] = tag[y] = 1, f[x] = y, cnt--, maxn = G[i].val;
		else f[x] = y, tag[y] |= tag[x];
	}
	for(register int i = 1; i <= k; i++) print(maxn, i == k ? '\n' : ' ');
	return 0;
}

// Rotate Flower Round.