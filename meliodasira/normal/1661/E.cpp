#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 5e5 + 5;

struct atom {
	int f[7], ans;
} p[N << 2];

int f[13];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

atom merge(atom a, atom b) {
	memset(f, 0, sizeof(f));
	int res = a.ans + b.ans;
	rep(i, 1, 6) {
		if (a.f[i]) f[i] = a.f[i];
		if (b.f[i]) f[i + 6] = b.f[i] + 6;
	}
	rep(i, 4, 6) {
		if (f[i] && f[i + 3] && find(i) != find(i + 3)) {
			f[find(i)] = find(i + 3);
			--res;
		}
	}
	atom ans;
	ans.ans = res;
	rep(i, 1, 3) {
		if (!f[i]) {
			ans.f[i] = 0;
			continue;
		}
		rep(j, 1, i) {
			if (find(i) == find(j)) {
				ans.f[i] = j;
				break;
			}
		}
	}
	rep(i, 10, 12) {
		if (!f[i]) {
			ans.f[i - 6] = 0;
			continue;
		}
		int cando = 0;
		rep(j, 1, 3) {
			if (find(i) == find(j)) {
				ans.f[i - 6] = j;
				cando = 1;
				break;
			}
		}
		if (cando) continue;
		rep(j, 10, i) {
			if (find(i) == find(j)) {
				ans.f[i - 6] = j - 6;
				break;
			}
		}
	}
	return ans;
}

int a[N][3];
char c[N];
int n, q;

void build(int u, int l, int r) {
	if (l == r) {
		rep(i, 0, 2) {
			if (a[l][i]) {
				if (i != 0 && a[l][i - 1]) {
					p[u].f[i + 1] = p[u].f[i + 4] = i;
				} else {
					++p[u].ans;
					p[u].f[i + 1] = p[u].f[i + 4] = i + 1;
				}
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	p[u] = merge(p[u << 1], p[u << 1 | 1]);
}

atom query(int u, int L, int R, int l, int r) {
	if (l <= L && R <= r) return p[u];
	int mid = (L + R) >> 1;
	if (mid >= l && mid + 1 <= r) return merge(query(u << 1, L, mid, l, r), query(u << 1 | 1, mid + 1, R, l, r));
	if (mid >= l) return query(u << 1, L, mid, l, r);
	return query(u << 1 | 1, mid + 1, R, l, r);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	rep(i, 0, 2) {
		scanf("%s", c + 1);
		rep(j, 1, n) a[j][i] = c[j] - '0';
	}
	build(1, 1, n);
	q = read();
	while (q--) {
		int l = read(), r = read();
		printf("%d\n", query(1, 1, n, l, r).ans);
	}
}