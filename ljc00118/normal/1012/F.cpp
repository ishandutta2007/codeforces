#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
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

const int N = 22, INF = 0x7f7f7f7f;

struct ele { int l, r, t, id; } a[N];

int f[1 << N], fr[1 << N], ans1[N], ans2[N], id[N], nxt[N];
int n, p;

bool operator < (const ele a, const ele b) { return a.l < b.l; }

void getans(int state, int id) {
	if (state == 0) return;
	int pos = fr[state];
	ans1[a[pos].id] = f[state] - a[pos].t;
	ans2[a[pos].id] = id;
	getans(state ^ (1 << pos), id);
}

int main() {
	memset(f, 0x7f, sizeof(f));
	read(n); read(p);
	for (int i = 0; i < n; i++) {
		read(a[i].l); read(a[i].r); read(a[i].t); a[i].id = i;
		a[i].r += (a[i].l - 1);
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		if (a[i - 1].l >= a[i].r) {
			printf("NO\n");
			return 0;
		}
	}
	f[0] = 1;
	for (int i = 0; i < n; i++) {
		if (a[i].t + 1 >= a[i].l) {
			printf("NO\n");
			return 0;
		}
		f[1 << i] = a[i].t + 1;
		fr[1 << i] = i;
	}
	for (int i = 1; i < (1 << n) - 1; i++) {
		if (f[i] == INF) continue;
		if (p == 2 && (f[i ^ ((1 << n) - 1)] != INF)) break;
		int fir = -1;
		for (int j = 0; j < n; j++) {
			if (a[j].r >= f[i]) {
				if (fir == -1) fir = j;
			}
		}
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) continue;
			int len = -1;
			for (int k = fir; k < n; k++) {
				if (a[k].l > f[i]) {
					if (((i >> k) & 1) || k == j || p == 1) id[++len] = k;
				}
			}
			if (f[i] < a[fir].l && (len == -1 || f[i] + a[j].t < a[id[0]].l) && f[i] + a[j].t < a[j].l) {
				if (f[i] + a[j].t < f[i | (1 << j)]) {
					f[i | (1 << j)] = f[i] + a[j].t;
					fr[i | (1 << j)] = j;
				}
				continue;
			}
			int now = 0;
			for (register int k = fir; k < n; ++k) {
				if (a[k].r + 1 + a[j].t >= min(f[i | (1 << j)], a[j].l)) break;
				while (now <= len && a[id[now]].r <= a[k].r) ++now;
				if ((k == n - 1 || a[k].r + 1 != a[k + 1].l) && (now == len + 1 || a[k].r + 1 + a[j].t < a[id[now]].l)) {
					f[i | (1 << j)] = a[k].r + 1 + a[j].t;
					fr[i | (1 << j)] = j;
					break;
				}
			}
		}
	}
	if (p == 1) {
		if (f[(1 << n) - 1] == INF) {
			printf("NO\n");
			return 0;
		}
		getans((1 << n) - 1, 1);
	} else {
		bool ok = 0;
		for (int i = 0; i < (1 << n); i++) {
			if (f[i] != INF && f[((1 << n) - 1) ^ i] != INF) {
				ok = 1;
				getans(i, 1); getans(((1 << n) - 1) ^ i, 2);
				break;
			}
		}
		if (!ok) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) print(ans2[i], ' '), print(ans1[i], '\n');
	return 0;
}