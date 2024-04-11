#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 210;
constexpr int mod = 1e9 + 7;
struct mat {
	int n,m,a[maxn][maxn];
	mat() : n(0), m(0) {}
	mat(int n, int m) : n(n), m(m) { memset(a, 0, sizeof a); }
	friend mat operator * (mat p, mat q) {
		mat ret(p.n, q.m);
		for (int i = 0; i < p.n; ++i)
			for (int j = 0; j < q.m; ++j)
				for (int k = 0; k < p.m; ++k)
					ret.a[i][j] = (ret.a[i][j] + 1ll * p.a[i][k] * q.a[k][j]) % mod;
		return ret;
	}
	friend mat operator ^ (mat p, int x) {
		mat ans(p.n, p.n);
		for (int i = 0; i < p.n; ++i) ans.a[i][i] = 1;
		while (x) {
			if (x & 1) ans = ans * p;
			p = p * p, x >>= 1;
		}
		return ans;
	}
};
int w[10],f[10][2];

int calc(int s, int t, int l) {
	int k = s & t;
	if (l == 1) return !k;
	f[0][0] = 0, f[0][1] = 1;
	for (int i = 1; i <= l; ++i)
		f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod,
		f[i][1] = (k >> (i - 1)) & 1 ? f[i - 1][0] : (f[i - 1][0] + f[i - 1][1]) % mod;
	return f[l][1];
}

int main() {
	mat res(1, 1);
	res.a[0][0] = 1;
	for (int i = 1; i <= 7; ++i) {
		int w, len = (1 << i); read(w);
		for (int j = 0; j < res.m; ++j)
			res.a[0][j | (1 << (i - 1))] = res.a[0][j], res.a[0][j] = 0;
		res.m <<= 1;
		mat trans(res.m, res.m);
		for (int s = 0; s < len; ++s)
			for (int t = 0; t < len; ++t)
				trans.a[s][t] = calc(s, t, i);
		res = res * (trans ^ w);
	}
	write(res.a[0][127], '\n');
	return 0;
}