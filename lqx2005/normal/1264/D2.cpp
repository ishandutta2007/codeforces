#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e6 + 10, P = 998244353;
int n, fac[N], ifac[N];
char s[N];
int qpow(int a, int b, int c = 1) { for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P; return c; }
void initmath(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[n] = qpow(fac[n], P - 2);
	for(int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
	return;
}

int C(int n, int m) { return (n < m || n < 0 || m < 0) ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P; }

int main() {
	cin >> (s + 1);
	n = strlen(s + 1);
	initmath(n);
	int d1 = 0, d2 = 0, c1 = 0, c2 = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == ')') d2++;
		if(s[i] == '?') c2++;
	}
	int ans = 0;
	for(int i = 1; i <= n + 1; i++) {
		ans = (ans + 1ll * c1 * C(c1 + c2 - 1, c2 - d1 + d2 - 1) % P) % P;
		ans = (ans + 1ll * d1 * C(c1 + c2, c2 - d1 + d2) % P) % P;
		if(s[i] == '?') c2--, c1++;
		if(s[i] == ')') d2--;
		if(s[i] == '(') d1++;
	}
	printf("%d\n", ans);
	return 0;
}