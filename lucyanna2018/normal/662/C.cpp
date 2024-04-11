#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1000000007> mint;

template<typename T>
void fastWalshTransform(T *a, int k) {
	if (k == 0)
		return;
	int n = 1 << (k - 1);
	fastWalshTransform(a, k - 1);
	fastWalshTransform(a + n, k - 1);
	rep(i, n) {
		T x = a[i], y = a[n + i];
		a[i] = x - y;
		a[n + i] = x + y;
	}
}
template<typename T>
void inverseFastWalshTransform(T *a, int k) {
	if (k == 0)
		return;
	int n = 1 << (k - 1);
	inverseFastWalshTransform(a, k - 1);
	inverseFastWalshTransform(a + n, k - 1);
	rep(i, n) {
		T x = a[i], y = a[n + i];
		a[i] = y + x;
		a[n + i] = y - x;
	}
}

int n, m;
mint a[1 << 20], b[1 << 20];

char s[20][100010];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%s", s[i]);
	for (int i = 0; i < m; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++)cur = cur * 2 + (s[j][i] == '1');
		a[cur] += 1;
	}
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)if (i&(1 << j))cnt++;
		b[i] = cnt + cnt > n ? n - cnt : cnt;
	}
	fastWalshTransform(a, n);
	fastWalshTransform(b, n);
	for (int i = 0; i < (1 << n); i++)a[i] *= b[i];
	inverseFastWalshTransform(a, n);
	int res = n * m;
	mint c = (mint)1 / (mint)(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		res = min(res, (a[i] * c).get());
	}
	printf("%d\n", res);
	return 0;
}