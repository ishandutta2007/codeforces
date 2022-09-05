#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
  
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
const int N = 305, md = 10007;

inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}

struct mat { int a[N][N], n; } a;

mat operator * (const mat a, const mat b) {
	int n = a.n; mat ans; ans.n = n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			ll sum = 0;
			for (int k = 0; k <= n; k++) sum += a.a[i][k] * b.a[k][j];
			ans.a[i][j] = sum % md;
		}
	}
	return ans;
}

mat fpow(mat x, int y) {
	mat ans = x; --y;
	while (y) {
		if (y & 1) ans = ans * x;
		y >>= 1; x = x * x;
	}
	return ans;
}

struct vec { int a[N], n; } ans;

vec operator * (const mat a, const vec b) {
	int n = a.n; vec ans; ans.n = n;
	for (int i = 0; i <= n; i++) {
		ll sum = 0;
		for (int j = 0; j <= n; j++) sum += a.a[j][i] * b.a[j];
		ans.a[i] = sum % md;
	}
	return ans;
}

int f[N][N][N], g[N][N][N];
char c[N];
int n, m, tmp_ans;

void cat(mat a) {
	int n = a.n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			print(a.a[i][j], j == n ? '\n' : ' ');
		}
	}
}

int main() {
	scanf("%s", c + 1); n = strlen(c + 1); read(m);
	for (int i = 1; i <= n + 1; i++) f[i][i - 1][0] = 1;
	for (int i = 1; i <= n; i++) f[i][i][0] = 1;
	if ((n + m) & 1) {
		for (int i = 1; i <= n - 1; i++) if (c[i] == c[i + 1]) g[i][i + 1][0] = 1;
	}
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l <= n - len + 1; l++) {
			int r = l + len - 1;
			if (c[l] == c[r]) {
				for (int i = 0; i <= len; i++) {
					f[l][r][i] = f[l + 1][r - 1][i];
					if (len > 2) g[l][r][i] = g[l + 1][r - 1][i];
				}
			} else {
				for (int i = 1; i <= len; i++) {
					f[l][r][i] = add(f[l + 1][r][i - 1], f[l][r - 1][i - 1]);
					if (len > 2) g[l][r][i] = add(g[l + 1][r][i - 1], g[l][r - 1][i - 1]);
				}
			}
		}
	}
	a.a[0][0] = 26;
	for (int i = 1; i <= n; i++) a.a[i][i - 1] = 1, a.a[i][i] = 24;
	for (int i = 1; i <= (n + 1) / 2; i++) a.a[i + n][i + n + 1] = 1, a.a[i + n + 1][i + n + 1] = 25;
	a.n = ans.n = n + (n + 1) / 2 + 1;
	for (int i = 0; i <= n; i++) a.a[(n - i + 1) / 2 + n + 1][i] = f[1][n][i];
	ans.a[n + 1] = 1; ans = fpow(a, (n + m + 1) / 2 + 1) * ans;
	if ((n + m) % 2 == 0 || n == 1) {
		print(ans.a[0], '\n');
		return 0;
	}
	tmp_ans = ans.a[0];
	memset(a.a, 0, sizeof(a.a)); memset(ans.a, 0, sizeof(ans.a));
	for (int i = 1; i <= n; i++) a.a[i][i - 1] = 1, a.a[i][i] = 24;
	for (int i = 1; i <= (n + 1) / 2; i++) a.a[i + n][i + n + 1] = 1, a.a[i + n + 1][i + n + 1] = 25;
	for (int i = 0; i <= n; i++) a.a[(n - i + 1) / 2 + n + 1][i] = g[1][n][i];
	ans.a[n + 1] = 1; ans = fpow(a, (n + m + 1) / 2 + 1) * ans;
	print((tmp_ans - ans.a[0] + md) % md, '\n');
    return 0;
}