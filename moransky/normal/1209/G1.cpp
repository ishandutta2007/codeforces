#include <iostream>
#include <cstdio>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

typedef pair<int, int> PII;

const int N = 2e5 + 5;

int n, t, q, S = 2e5, f[N], sz[N], mx[N], L[N], R[N], a[N];

PII e[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x, y);
	f[x] = y, chkMax(mx[y], mx[x]), sz[y] += sz[x];
}

int main() {
	read(n), read(q);
	for (int i = 1; i <= S; i++) f[i] = i, L[i] = 2e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sz[a[i]]++, mx[a[i]]++;
		chkMin(L[a[i]], i);
		R[a[i]] = i;
	}
	for (int i = 1; i <= S; i++) {
		if (L[i] <= R[i]) e[++t] = mp(L[i], R[i]);
	}
	sort(e + 1, e + 1 + t);
	int L = e[1].fi, R = e[1].se;
	for (int i = 2; i <= t; i++) {
		if (e[i].fi <= R) {
			chkMax(R, e[i].se);
		} else {
			for (int k = L + 1; k <= R; k++)
				merge(a[L], a[k]);
			L = e[i].fi, R = e[i].se;
		}
	}
	for (int k = L + 1; k <= R; k++)
		merge(a[L], a[k]);
	int ans = 0;
	for (int i = 1; i <= S; i++)
		if (find(i) == i && sz[i]) ans += sz[i] - mx[i];
	printf("%d\n", ans);
}