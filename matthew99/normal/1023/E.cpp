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

const int maxn = 510;

int n;

char s[maxn * 2 + 5];

int main()
{
#ifdef matthew99
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int curx = 1, cury = 1;
	char ver[5];
	REP(i, 0, n - 1)
	{
		printf("? %d %d %d %d\n", curx + 1, cury, n, n);
		fflush(stdout);
		scanf("%s", ver);
		if (ver[0] == 'N')
		{
			s[i] = 'R';
			++cury;
		}
		else
		{
			s[i] = 'D';
			++curx;
		}
	}
	curx = n, cury = n;
	for (int i = 2 * n - 3; i >= n - 1; --i)
	{
		printf("? %d %d %d %d\n", 1, 1, curx, cury - 1);
		fflush(stdout);
		scanf("%s", ver);
		if (ver[0] == 'N')
		{
			s[i] = 'D';
			--curx;
		}
		else
		{
			s[i] = 'R';
			--cury;
		}
	}
	printf("! %s\n", s);
	return 0;
}