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

const int N = 35, base = 1000000, md = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += md;
	return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

vector <int> f[N][N * N];
int x[N], inv[N], pw[N], lim[N], c[N][N];
int n;

vector <int> jifen(vector <int> poly) {
	int len = (int)poly.size();
	poly.push_back(0);
	for (int i = len; i >= 1; i--) poly[i] = mul(poly[i - 1], inv[i]);
	poly[0] = 0;
	return poly;
}

int getv(vector <int> poly, int x) {
	int ans = 0, pw = 1;
	for (int i = 0; i < (int)poly.size(); i++) {
		ans = add(ans, mul(pw, poly[i]));
		pw = mul(pw, x);
	}
	return ans;
}

vector <int> getpoly(vector <int> f) {
	int len = (int)f.size();
	vector <int> ans(len, 0);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j <= i; j++) {
			ans[j] = add(ans[j], mul(mul(f[i], c[i][j]), pw[i - j]));
		}
	}
	return ans;
}

vector <int> polyadd(vector <int> a, vector <int> b) {
	int len = max((int)a.size(), (int)b.size());
	a.resize(len); b.resize(len);
	for (int i = 0; i < len; i++) a[i] = add(a[i], b[i]);
	return a;
}

vector <int> polysub(vector <int> a, vector <int> b) {
	int len = max((int)a.size(), (int)b.size());
	a.resize(len); b.resize(len);
	for (int i = 0; i < len; i++) a[i] = sub(a[i], b[i]);
	return a;
}

int main() {
	read(n);
	c[0][0] = pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1; pw[i] = mul(pw[i - 1], md - base);
		for (int j = 1; j <= i; j++) c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
	}
	for (int i = 1; i <= n; i++) inv[i] = fpow(i, md - 2);
	vector <int> r;
	for (int i = 1; i <= n; i++) {
		double a;
		scanf("%lf", &a);
		x[i] = (int)(a * base + 0.5);
		r.push_back(x[i] % base);
	}
	r.push_back(0);
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());
	int len = (int)r.size();
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < len; j++) r.push_back(r[j] + i * base);
	}
	r.push_back(n * base);
	for (int i = 1; i <= n; i++) lim[i] = lower_bound(r.begin(), r.end(), x[i]) - r.begin();
	for (int i = 0; i < n * len; i++) {
		if (i < min(lim[1], len)) {
			f[1][i] = {1};
		} else {
			f[1][i] = {0};
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < min(i * len, lim[i]); j++) {
			int sum = 0;
			for (int k = max(j - len + 1, 0); k < j; k++) {
				vector <int> poly = jifen(f[i - 1][k]);
				sum = add(sum, getv(poly, r[k + 1]));
				sum = sub(sum, getv(poly, r[k]));
			}
			vector <int> poly = jifen(f[i - 1][j]);
			sum = sub(sum, getv(poly, r[j]));
			f[i][j] = poly;
			if (j - len >= 0) {
				poly = jifen(f[i - 1][j - len]);
				sum = add(sum, getv(poly, r[j - len + 1]));
				f[i][j] = polysub(f[i][j], getpoly(poly));
			}
			f[i][j][0] = add(f[i][j][0], sum);
			// fprintf(stderr, "i = %d, j = %d, sum = %d\n", i, j, sum);
		}
	}
	int ans = 0;
	for (int i = 0; i < n * len; i++) {
		vector <int> poly = jifen(f[n][i]);
		ans = add(ans, getv(poly, r[i + 1]));
		ans = sub(ans, getv(poly, r[i]));
	}
	print(mul(ans, fpow(fpow(base, n), md - 2)), '\n');
	return 0;
}