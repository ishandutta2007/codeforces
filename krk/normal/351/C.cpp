#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 22;
const int Maxd = 41;
const int Inf = 2000000017;

int Add(int a, int b)
{
	return a <= Inf - b? a + b: Inf;
}

struct matrix {
	int m[Maxd][Maxd];
	matrix() {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = (i != j) * Inf;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++) {
				c.m[i][j] = Inf;
				for (int k = 0; k < Maxd; k++)
					c.m[i][j] = min(c.m[i][j], Add(m[i][k], b.m[k][j]));
			}
		return c;
	}
};

int n, m;
int a[Maxn], b[Maxn];
matrix res, mult;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	fill((int*)mult.m, (int*)mult.m + Maxd * Maxd, Inf);
	for (int j = 0; j < 1 << n; j++) {
		int cur = 0, cost = 0;
		int mn = 0, mx = 0;
		for (int k = 0; k < n; k++)
			if (!(j & 1 << k)) {
				mx = max(mx, ++cur); cost += a[k];
			} else {
				mn = min(mn, --cur); cost += b[k];
			}
		for (int i = 0; i < Maxd; i++) 
			if (i + mn >= 0 && i + mx < Maxd)
				mult.m[i][i + cur] = min(mult.m[i][i + cur], cost);
	}
	while (m) {
		if (m & 1) res = res * mult;
		m >>= 1; mult = mult * mult;
	}
	printf("%d\n", res.m[0][0]);
	return 0;
}