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

const int maxnm = 1000100;

pair<int, int> a[maxnm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) REP(j, 0, m) a[i * m + j] = mp(i, j);
	int i0 = 0, i1 = n * m - 1;
	while (1)
	{
		printf("%d %d\n", a[i0].x + 1, a[i0].y + 1);
		if (i0 == i1) break;
		if (i0 < i1) ++i0;
		else --i0;
		swap(i0, i1);
	}
	return 0;
}