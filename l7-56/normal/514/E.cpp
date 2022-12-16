#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

constexpr int maxn = 110, mod = 1e9 + 7;
#define inc(x, y) (((x) += (y)) >= mod ? (x) -= mod : (x))
struct mat {
	int n,m,a[maxn][maxn];
	mat() : n(0), m(0) {}
	mat(int n, int m) : n(n), m(m) { memset(a, 0, sizeof a); }
	friend mat operator * (mat p, mat q) {
		mat ret(p.n, q.m);
		for (int i = 0; i < p.n; ++i)
			for (int j = 0; j < q.m; ++j)
				for (int k = 0; k < p.m; ++k)
					inc(ret.a[i][j], 1ll * p.a[i][k] * q.a[k][j] % mod);
		return ret;
	}
	friend mat operator ^ (mat x, int p) {
		mat ans(x.n, x.m);
		for (int i = 0; i < x.n; ++i) ans.a[i][i] = 1;
		while (p) {
			if (p & 1) ans = ans * x;
			x = x * x, p >>= 1;
		}
		return ans;
	}
};

const int maxm = 1e5 + 10;
int n,x,d[maxm];

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
	mat st(1, 101), trans(101, 101);
	st.a[0][99] = st.a[0][100] = 1;
	for (int i = 1; i < 100; ++i) trans.a[i][i - 1] = 1;
	trans.a[100][100] = 1;
	for (int i = 1; i <= n; ++i) trans.a[100 - d[i]][99]++, trans.a[100 - d[i]][100]++;
	st = st * (trans ^ x);
	printf("%d\n", st.a[0][100]);
	return 0;
}