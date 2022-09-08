#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
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

const int N = 125005 << 2, P = 998244353, G = 3, Gi = (P + 1) / 3;

char t1[N], t2[N];
int r[N], a[N], b[N], f[N][6];
int n, m, len = 1, tot;

int find(int x, int y) { return f[x][y] == y ? y : f[x][y] = find(x, f[x][y]); }

inline int mul(int x, int y) { return (int)(1ll * x * y % P); }
inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

void NTT(int *a, int opt) {
	for(register int i = 1; i < len; i++) if(i < r[i]) swap(a[i], a[r[i]]);
	for(register int mid = 1; mid < len; mid <<= 1) {
		int wn = fpow(opt == 1 ? G : Gi, (P - 1) / (mid << 1));
		for(register int i = 0; i < len; i += (mid << 1)) {
			for(register int j = 0, w = 1; j < mid; j++, w = mul(w, wn)) {
				int x = a[i + j], y = mul(a[i + j + mid], w);
				a[i + j] = (x + y) % P; a[i + j + mid] = (x - y + P) % P;
			}
		}
	}
	if(opt == -1) {
		int inv = fpow(len, P - 2);
		for(register int i = 0; i < len; i++) a[i] = mul(a[i], inv);
	}
}

int main() {
	scanf("%s%s", t1 + 1, t2 + 1);
	n = strlen(t1 + 1); m = strlen(t2 + 1);
	while(len <= n + m) len <<= 1, tot++;
	for(register int i = 1; i < len; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (tot - 1));
	for(register int i = 1; i <= n; i++) for(register int j = 0; j <= 5; j++) f[i][j] = j;
	for(register int i = 0; i <= 5; i++) {
		for(register int j = 0; j <= 5; j++) {
			if(i == j) continue;
			memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
			for(register int k = 1; k <= n; k++) a[k] = (t1[k] == ('a' + i));
			for(register int k = 1; k <= m; k++) b[m - k + 1] = (t2[k] == ('a' + j));
			NTT(a, 1); NTT(b, 1);
			for(register int k = 0; k < len; k++) a[k] = mul(a[k], b[k]);
			NTT(a, -1);
//			fprintf(stderr, "DEBUG >>> ");
//			for(register int k = 0; k < len; k++) fprintf(stderr, "%d%c", a[k], k == (len - 1) ? '\n' : ' ');
			for(register int k = m + 1; k <= n + 1; k++) if(a[k] > 0) f[k - m][find(k - m, i)] = find(k - m, j);
		}
	}
	for(register int i = 1; i <= n - m + 1; i++) {
		int ans = 0;
		for(register int j = 0; j <= 5; j++) ans += (find(i, j) != j);
		print(ans, i == (n - m + 1) ? '\n' : ' ');
	}
	return 0;
}