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

const int q[] = {2, 4, 3, 9, 5, 25, 7, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int qn = sizeof(q) / sizeof(q[0]);

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int cnt = 0;
	REP(i, 0, qn)
	{
		printf("%d\n", q[i]);
		fflush(stdout);
		char s[100];
		scanf("%s", s);
		if (s[0] == 'y') ++cnt;
		if (cnt > 1)
		{
			puts("composite");
			fflush(stdout);
			return 0;
		}
	}
	puts("prime");
	fflush(stdout);
	return 0;
}