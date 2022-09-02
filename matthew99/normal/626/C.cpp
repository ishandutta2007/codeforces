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

const int maxn = 200;

int n, m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	int cnt6 = 0;
	for (int i = 1; ; ++i)
	{
		if (i % 6 == 0) ++cnt6;
		else if (i % 2 == 0)
		{
			if (n > 0) --n;
		}
		else if (i % 3 == 0)
		{
			if (m > 0) --m;
		}
		if (cnt6 >= n + m)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}