#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
	x *= f;
}

const int N = 205;

int n, c[N], L[N], R[N], t, d[N], len;

bool inline cross(int x, int y) {
	if (L[x] > L[y]) swap(x, y);
	return R[x] > L[y] && R[x] < R[y];
}

int main() {
	int T; read(T);
	while (T--) {
		memset(c, 0, sizeof c);
		len = 0;
		read(n), read(t);
		for (int i = 1; i <= t; i++) read(L[i]), read(R[i]), c[L[i]] = 1, c[R[i]] = 1;
		for (int i = 1; i <= 2 * n; i++)
			if (!c[i]) d[++len] = i;
		for (int i = 1; i <= len / 2; i++) {
			L[++t] = d[i], R[t] = d[i + len / 2];
		}
		for (int i = 1; i <= n; i++) if (L[i] > R[i]) swap(L[i], R[i]);
		int ans = 0; 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (cross(i, j)) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}