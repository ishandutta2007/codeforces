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

const int maxn = 100100;

int n;
int a[maxn + 5];

inline int get(int x)
{
#ifdef matthew99
	return a[x + (n >> 1)] - a[x];
#else
	int u, v;
	printf("? %d\n", x + 1);
	fflush(stdout);
	scanf("%d", &u);
	printf("? %d\n", x + (n >> 1) + 1);
	fflush(stdout);
	scanf("%d", &v);
	return v - u;
#endif
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
#ifdef matthew99
	REP(i, 0, n) scanf("%d", a + i);
#endif
	if ((n & 3) == 2) printf("! -1\n");
	else
	{
		int tmp = get(0);
		if (!tmp)
		{
			printf("! 1\n");
		}
		else
		{
			int l = 1, r = (n >> 1) - 1;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				int val = get(mid);
				if (!val)
				{
					printf("! %d\n", mid + 1);
					return 0;
				}
				if ((val > 0) == (tmp > 0)) l = mid + 1;
				else r = mid - 1;
			}
#ifdef matthew99
			debug("%d\n", get(l));
#endif
			printf("! %d\n", l + 1);
		}
	}
	return 0;
}