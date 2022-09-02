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

const int maxn = 5010;

int query(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

int n;
int a[maxn + 5], b[maxn + 5];

int ans[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
		a[i] = query(i, 0), b[i] = query(0, i);
	int cnt = 0;
	REP(i, 0, n)
	{
		int u = i, v = a[0] ^ i;
		static int tmpa[maxn + 5], tmpb[maxn + 5];
		bool failed = 0;
		REP(j, 0, n) tmpa[j] = a[j] ^ v, tmpb[j] = b[j] ^ u;
		REP(j, 0, n) if (tmpa[j] >= n) failed = 1;
		REP(j, 0, n) if (tmpb[j] >= n) failed = 1;
		REP(j, 0, n) if (tmpa[tmpb[j]] != j) failed = 1;
		if (!failed) 
		{
			++cnt;
			memcpy(ans, tmpa, sizeof ans);
		}
	}
	printf("!\n");
	printf("%d\n", cnt);
	REP(i, 0, n) printf("%d ", ans[i]);
	return 0;
}