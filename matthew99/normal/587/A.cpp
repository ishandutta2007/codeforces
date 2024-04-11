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

const int maxabs = 2000000;

int now[maxabs + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x;
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%d", &x);
		while (now[x] == 1)
		{
			now[x] = 0;
			++x;
		}
		now[x] = 1;
	}
	int ans = 0;
	REP(i, 0, maxabs + 1) ans += now[i];
	printf("%d\n", ans);
	return 0;
}