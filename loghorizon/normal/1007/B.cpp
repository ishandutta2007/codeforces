#include <bits/stdc++.h>

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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

const int N = 1e5 + 5;

int a[N], t, cnt[8];

int d(int x) {
	int v = 0;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			v++; a[++t] = i;
			if (x / i != i) v++, a[++t] = x / i;
		}
	}
	return v;
}

LL inline C(LL a, LL b) {
	if (a < 0 || b > a || b < 0) return 0;
	b = min(b, a - b);
	LL res = 1;
	for (int i = 0; i < b; i++) {
		res = res * (a - i) / (i + 1);
	}
	return res;
}

LL inline get(int k, int n) {
	if (n == 0 && k == 0) return 1;
	return C(n + k - 1, k - 1);
}

LL ans;

int s[N], top, p[4], f[8];

void add() {
	for (int i = 0; i < 8; i++)
		if (!cnt[i] && f[i]) return;
	for (int i = 1; i <= 3; i++) p[i] = s[i];
	bool o = 0;
	do {
		bool op = 1;
		for (int i = 1; i <= 3; i++) {
			if (!(p[i] >> (i - 1) & 1)) op = 0;
		}
		if (op) o = 1;
	} while (next_permutation(p + 1, p + 1 + 3));
	if (o) {
		LL v = 1;
		for (int i = 0; i < 8; i++) v *= get(cnt[i], f[i]);
		ans += v;
	}
}

void dfs(int u) {
	if (u == 8) {
		if (top != 3) return;
		add();
		return;
	}
	dfs(u + 1);
	
	int i = 0;
	while (top < 3) {
		++i;
		s[++top] = u;
		f[u] = i;
		dfs(u + 1);
	}
	f[u] = 0;
	while (top && s[top] == u) top--;
}

int main() {
	int T; read(T);
	while (T--) {
		memset(cnt, 0, sizeof cnt); ans = 0;
		memset(f, 0, sizeof f);
		t = 0; top = 0;
		int A, B, C;
		read(A), read(B), read(C);
		d(A), d(B), d(C);
		sort(a + 1, a + 1 + t);
		t = unique(a + 1, a + 1 + t) - a - 1;
		for (int i = 1; i <= t; i++) {
			int v = a[i], s = 0;
			if (A % v == 0) s |= 1;
			if (B % v == 0) s |= 2;
			if (C % v == 0) s |= 4;
			cnt[s]++;
		}
		dfs(0);
		printf("%lld\n", ans);
	}
}