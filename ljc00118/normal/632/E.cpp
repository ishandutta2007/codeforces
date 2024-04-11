#pr\
agma GCC optimize(2)
#pr\
agma GCC optimize(3)
#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = (1 << 20) + 5, P = 469762049, G = 3, Gi = (P + 1) / G;

ll a[N], b[N], A[N], Ans[N];
int r[N];
int n, m, Max, len = 1, tot = 0;

inline int mul(int x, int y) { return (int)(1ll * x * y % P); }

int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int pre[22][N];

void init(int tp) {
	for(register int mid = 1, t = 0; mid < len; mid <<= 1, t++) {
		ll wn = fpow(G, (P - 1) / (mid << 1)), w = 1;
		for(register int i = 0; i < mid; i++, w = w * wn % P) pre[t][i] = w;
	}
}

void NTT(ll *a, int tp) {
	for(register int i = 1; i < len; i++) if(i < r[i]) swap(a[i], a[r[i]]);
	for(register int mid = 1, t = 0; mid < len; mid <<= 1, t++) {
		for(register int i = 0; i < len; i += (mid << 1)) {
			for(register int j = 0; j < mid; ++j) {
				ll x = a[i + j], y = a[i + j + mid] * pre[t][j] % P;
				a[i + j] = (x + y) % P; a[i + j + mid] = (x - y + P) % P;
			}
		}
	}
	if(tp == -1) {
		ll inv = fpow(len, P - 2);
		for(register int i = 0; i < len; i++) a[i] = a[i] * inv % P;
	}
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		int t; read(t); A[t] = 1;
		Max = max(Max, t);
	}
	while(len < m * Max) len <<= 1, tot++;
	for(register int i = 0; i < len; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (tot - 1));
	init(1); NTT(A, 1); for(register int i = 0; i < len; i++) A[i] = fpow(A[i], m);
	reverse(A + 1, A + len); NTT(A, -1);
	for(register int i = 1; i <= Max * m; ++i) if(A[i]) print(i, ' ');
	return 0;
}