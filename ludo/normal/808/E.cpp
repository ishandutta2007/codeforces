#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000;

#define rep(i,a,b) for(auto i=(a);i!=(b);++i)
#define REP(i,n) rep(i,0,n)
#define pb push_back
#define eb emplace_back

typedef long long ll;

int n, m, nc[3] = { 1, 1, 1 };
ll c[3][maxn];

ll eval3(int nr3)
{
	ll sum = c[2][nr3];
	int cap = m - 3 * nr3;
	ll ret = -1LL;
	for (int n2 = 0; cap >= 0 && n2 <= nc[1]; cap -= 2, n2++) {
		ret = max(ret, sum + c[0][min(nc[0], cap)]);
		sum += c[1][n2 + 1] - c[1][n2];
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	REP(i, n) {
		int iw, ic;
		scanf("%d%d", &iw, &ic);
		iw--;
		c[iw][nc[iw]++] = ic;
	}

	REP(i, 3) {
		c[i][0] = 0;
		sort(c[i] + 1, c[i] + nc[i]);
		reverse(c[i] + 1, c[i] + nc[i]);
		// calculate the prefix sums.

		nc[i]--;

		for (int j = 1; j <= nc[i]; j++) {
			c[i][j] += c[i][j - 1];
		}
	}

	int lo = 0, hi = nc[2];
	while (hi - lo >= 10) {
		int mil = (2 * lo + hi) / 3;
		int mih = (2 * hi + lo) / 3;

		ll fl = eval3(mil);
		ll fh = eval3(mih);
		if (fl > fh) hi = mih;
		else lo = mil;
	}

	ll ret = -1LL;
	for (int x = lo; x <= hi; x++) {
		ret = max(ret, eval3(x));
	}
	printf("%lld\n", ret);
	return 0;
}