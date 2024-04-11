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

int n;

inline int c(int x)
{
	while (!(x % 2)) x /= 2;
	while (!(x % 3)) x /= 3;
	return x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int x;
	scanf("%d", &x);
	x = c(x);
	REP(i, 1, n)
	{
		int y;
		scanf("%d", &y);
		y = c(y);
		if (y != x) printf("No\n"), exit(0);
	}
	printf("Yes\n");
	return 0;
}