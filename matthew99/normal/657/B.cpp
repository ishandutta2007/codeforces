#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

const LL max0 = 1e18;

int n, K;
int a[maxn + 5];

bool ok[maxn + 5];
int pre[maxn + 5];

LL suf[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n + 1) scanf("%d", a + i);
	suf[n + 1] = 0;
	for (int i = n; i >= 0; --i)
	{
		suf[i] = (suf[i + 1] << 1) + a[i];
		chkmin(suf[i], max0);
		chkmax(suf[i], -max0);
	}
	pre[0] = 0;
	ok[0] = 1;
	REP(i, 0, n)
	{
		if (!ok[i]) ok[i + 1] = 0;
		else
		{
			ok[i + 1] = 1;
			pre[i + 1] = pre[i];
			if (pre[i + 1] & 1) ok[i + 1] = 0;
			pre[i + 1] >>= 1;
			pre[i + 1] += a[i];
		}
	}
	int ans = 0;
	REP(i, 0, n + 1)
		if (ok[i])
		{
			LL tmp = pre[i];
			if (tmp & 1) continue;
			tmp >>= 1;
			tmp += suf[i + 1] << 1;
			if (i == n && !tmp) continue;
			if (abs(tmp) <= K) ++ans;
		}
	printf("%d\n", ans);
	return 0;
}