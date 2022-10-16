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

const int P = 998244353;

int inline power(int a, LL b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int inline ask(int q, int n) {
	int res = power((q + 1) % P, n);
	return (res - 1 + P) % P;
}

const int N = 1e6 + 5;

int n, ans, fact[N], infact[N];

int inline C(int a, int b) {
	return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int main() {
	read(n);
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
	infact[n] = power(fact[n], P - 2);
	for (int i = n - 1; i; i--) infact[i] = (LL)infact[i + 1] * (i + 1) % P;
	ans = power(3, (LL)n * n);
	for (int i = 1; i <= n; i++) {
		int v = 2ll * power(3, i) % P * C(n, i) % P * power(3, (LL)n * (n - i)) % P;
		if (i & 1) ans = (ans - v + P) % P;
		else ans = (ans + v) % P;
	}
	
	int s = 0;
	
	for (int i = 1; i <= n; i++) {
		int t = (P - power(power(3, n - i), P - 2)) % P;
		int v = (LL)power(3, (LL)n * (n - i)) * C(n, i) % P * ask(t, n) % P;
		if (i & 1) v = (P - v) % P;
		add(s, v);
	}

	ans = (ans + 3ll * s) % P;
	ans = (power(3, (LL)n * n) - ans + P) % P;
	
	printf("%d\n", ans);
}