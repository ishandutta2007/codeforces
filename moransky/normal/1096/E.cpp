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

const int N = 2e7 + 5, P = 998244353;

int n, m, k, fact[N], infact[N], inv[N]; 

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return res;
}

void inline factPrework(int n) {
	inv[1] = 1;
	for (int i = 2; i <= n; i++) 
		inv[i] = ((LL)P - P / i) * inv[P % i] % P;
	infact[0] = fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % P;
		infact[i] = 1ll * infact[i - 1] * inv[i] % P;
	}
}

int inline C(int a, int b) {
	if (a < 0 || b > a || b < 0) return 0;
	return 1ll * fact[a] * infact[b] % P * infact[a - b] % P;
}

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int main() {
	read(n), read(m), read(k);
	factPrework(n + m);
	int s = 1ll * fact[n] * C(m - k - 1 + n, n - 1) % P;
	int v = 0;
	for (int i = 0; i < n; i++) {
		if ((i + 1ll) * k > m) continue;
		int o = 1ll * C(n - 1, i) * fact[i] % P * fact[n - i - 1] % P * C(n, i + 1) % P;
		int w = C(m - k * (i + 1) - 1 + n, n - 1);
		w = 1ll * w * o % P;
		if (i & 1) add(v, P - w);
		else add(v, w);
	}
	v = 1ll * v * power(s, P - 2) % P;
	printf("%d\n", v);
    return 0;
}