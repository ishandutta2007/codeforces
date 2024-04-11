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

const int maxn = 1000000;

int n, qn;

int ans[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	int delta_odd = 0, delta_even = 0;
	REP(i, 0, qn)
	{
		int ty, x;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d", &x);
			(delta_odd += x) %= n;
			(delta_even += x) %= n;
		}
		else if (ty == 2)
		{
			if (delta_odd & 1) (++delta_odd) %= n;
			else (--delta_odd) %= n;
			if (delta_even & 1) (--delta_even) %= n;
			else (++delta_even) %= n;
		}
	}
	memset(ans, -1, sizeof ans);
	REP(i, 0, n)
	{
		int tmp = i;
		if (i & 1) (tmp += delta_odd) %= n;
		else (tmp += delta_even) %= n;
		(tmp += n) %= n;
		ans[tmp] = i;
	}
	REP(i, 0, n) printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}