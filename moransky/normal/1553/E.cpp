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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

const int N = 3e5 + 5;

int n, m, f[N], cnt[N], a[N], d[N], t;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	f[find(x)] = find(y);
}

bool inline check(int k) {
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		int tt = a[i] + k;
		if (tt > n) tt -= n;
		merge(tt, i);
	}
	int s = 0;
	for (int i = 1; i <= n; i++)
		if (find(i) == i) s++;
	return s + m >= n;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m); 
		for (int i = 1; i <= n; i++) f[i] = i, cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			int o = i - a[i];
			if (o < 0) o += n;
			cnt[o]++;
		}
		for (int i = 0; i < n; i++) {
			if (cnt[i] + 2 * m >= n && check(i)) {
				d[++t] = i;
			}
		}
		printf("%d\n", t);
		for (int i = 1; i <= t; i++) printf("%d ", d[i]);
		puts("");
		t = 0;
	}
	return 0;
}