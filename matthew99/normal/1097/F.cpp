#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

const int maxv = 7010;

typedef bitset<maxv + 5> bset;

bset a[maxn + 5];

bset fac[maxv + 5];
bset mul[maxv + 5];

int mu[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i <= maxv; ++i) mu[i] = 1;
	for (int i = 2; i * i <= maxv; ++i)
		for (int j = i * i; j <= maxv; j += i * i)
			mu[j] = 0;
	for (int i = 1; i <= maxv; ++i)
		for (int j = i; j <= maxv; j += i)
		{
			fac[j][i] = 1;
			mul[i][j] = mu[j / i];
		}
	int n, qn;
	scanf("%d%d", &n, &qn);
	REP(i, 0, qn)
	{
		int ty, x, y, z, v;
		scanf("%d%d", &ty, &x), --x;
		if (ty == 1)
		{
			scanf("%d", &v);
			a[x] = fac[v];
		}
		else if (ty == 2)
		{
			scanf("%d%d", &y, &z), --y, --z;
			a[x] = a[y] ^ a[z];
		}
		else if (ty == 3)
		{
			scanf("%d%d", &y, &z), --y, --z;
			a[x] = a[y] & a[z];
		}
		else if (ty == 4)
		{
			scanf("%d", &v);
			int ret = (a[x] & mul[v]).count() & 1;
			putchar('0' + ret);
		}
	}
	return 0;
}