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

int n, m, p[N], md;

bool inline ok(int x, int y) {
	if (x > y) swap(x, y);
	if (x + 1 == y && x % m) return 0;
	if (x + m == y) return 0;
	return 1;
}

bool inline chk() {
	for (int i = 1; i <= n * m; i++) {
		if (i % m != 1 && i > 1) {
			if (!ok(p[i], p[i - 1])) return 0;
		} 
		if (i > m) if (!ok(p[i], p[i - m])) return 0;
	}
	return 1;
}

void inline pt() {
	puts("YES");
	if (!md) {
		for (int i = 1; i <= n * m; i++) {
			printf("%d ", p[i]);
			if (i % m == 0) puts("");
		}
	} else {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				int v = (j - 1) * n + i;
				printf("%d ", p[v]);
			}
			puts("");
		}
	}
}

void inline baoli() {
	for (int i = 1; i <= n * m; i++) p[i] = i;
	do {
		if (chk()) {
			pt();
			return;
		}
	} while (next_permutation(p + 1, p + 1 + n * m));
	puts("NO");
}

string aa = "1 3 5 2 4\n7 9 6 8 10\n11 13 15 12 14";

int main() {
	read(n), read(m);
//	if (n > m) swap(n, m), md = 1;
	//if (n )
	if (n * m <= 10) {
		baoli();
	} else {
		int cnt = 0;
		for (int i = 1; i <= n * m; i++) {
			if (i & 1) p[i] = ++cnt;
		}
		for (int i = 1; i <= n * m; i++) {
			if (i % 2 == 0) p[i] = ++cnt;
		}
		if (chk()) {
			pt();
			return 0;
		}
		if (n == 2) {
			int c1 = 0, c2 = m;
			for (int i = 1; i <= 2 * m; i++)
				if (i & 1) {
					if (i <= m) p[++c1] = i;
					else p[++c2] = i;
				}
			for (int i = 1; i <= 2 * m; i++)
				if (i % 2 == 0) {
					if (i <= m) p[++c1] = i;
					else p[++c2] = i;
				}
			if (chk()) {
				pt();
				return 0;
			}
			c1 = 0, c2 = m;
			for (int i = 1; i <= 2 * m; i++)
				if (i % 2 && i <= m) p[++c1] = i;
				else if (i % 2 == 0 && i > m)p[++c2] = i;
			for (int i = 1; i <= 2 * m; i++)
				if (i % 2 == 0 && i <= m) p[++c1] = i;
				else if (i % 2 && i > m)p[++c2] = i;
			if (chk()) {
				pt();
				return 0;
			}
		}
		if (n == 3) {
			int c1 = 0, c2 = m, c3 = 2 * m;
			for (int i = 1; i <= 3 * m; i++)
				if (i & 1) {
					if (i <= m) p[++c1] = i;
					else if (i <= 2 * m) p[++c2] = i;
					else p[++c3] = i;
				}
			for (int i = 1; i <= 3 * m; i++)
				if (i % 2 == 0) {
					if (i <= m) p[++c1] = i;
					else if (i <= 2 * m) p[++c2] = i;
					else p[++c3] = i;
				}
			if (chk()) {
				pt();
				return 0;
			}
		}
		if (m == 2) {
			int c1 = 1, c2 = 2;
			for (int i = 1; i <= n * m; i++) {
				if (i % 4 == 1) {
					p[c1] = i;
					c1 += 2;
				}
				if (i % 4 == 0) {
					p[c2] = i;
					c2 += 2;
				}
			}
			for (int i = 1; i <= n * m; i++) {
				if (i % 4 == 3) {
					p[c1] = i;
					c1 += 2;
				}
				if (i % 4 == 2) {
					p[c2] = i;
					c2 += 2;
				}
			}
			if (chk()) {
				pt();
				return 0;
			}
		}
	}
    return 0;
}