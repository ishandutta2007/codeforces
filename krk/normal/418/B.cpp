#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 5000000000000000000ll;
const int Maxn = 105;
const int Maxm = 1 << 20;

struct frien {
	int x, k, mask;
	frien(int x = 0, int k = 0, int mask = 0): x(x), k(k), mask(mask) {}
	bool operator <(const frien &f) const {
		return k < f.k;
	}
};

int n, m, b;
frien F[Maxn];
ll dp[Maxm];
ll res = Inf;

int main()
{
	scanf("%d %d %d", &n, &m, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &F[i].x, &F[i].k);
		int mi; scanf("%d", &mi);
		while (mi--) {
			int bt; scanf("%d", &bt);
			F[i].mask |= 1 << bt - 1;
		}
	}
	sort(F, F + n);
	fill(dp, dp + (1 << m), Inf);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 << m; j++)
			dp[F[i].mask | j] = min(dp[F[i].mask | j], dp[j] + F[i].x);
		if (dp[(1 << m) - 1] != Inf)
			res = min(res, dp[(1 << m) - 1] + ll(b) * F[i].k);
	}
	printf("%I64d\n", res == Inf? -1: res);
	return 0;
}