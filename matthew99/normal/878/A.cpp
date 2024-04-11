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

int a = 0, b = 0, c = 0;

int res[10][2];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	REP(i, 0, 10) REP(j, 0, 2) res[i][j] = j;
	REP(i, 0, n)
	{
		static char s[5];
		scanf("%s", s);
		int x;
		scanf("%d", &x);
		REP(j, 0, 10) REP(k, 0, 2)
		{
			if (s[0] == '&') res[j][k] &= (x >> j & 1);
			if (s[0] == '|') res[j][k] |= (x >> j & 1);
			if (s[0] == '^') res[j][k] ^= (x >> j & 1);
		}
	}
	REP(i, 0, 10)
	{
		if (res[i][0] != res[i][1])
		{
			a ^= 1 << i;
			if (!res[i][0]) c ^= 1 << i;
		}
		else 
		{
			b ^= 1 << i;
			if (!res[i][0]) c ^= 1 << i;
		}
	}
	printf("3\n");
	printf("^ %d\n", a);
	printf("| %d\n", b);
	printf("^ %d\n", c);
	return 0;
}