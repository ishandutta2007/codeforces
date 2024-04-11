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

const int maxn = 500100;

int l[maxn + 5], r[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	static char s[maxn + 5];
	scanf("%d", &n);
	int ans = 0;
	int zero = 0;
	REP(i, 0, n)
	{
		scanf("%s", s);
		int m = strlen(s);
		int sum = 0;
		bool lr = 1, rl = 1;
		REP(j, 0, m)
		{
			if (s[j] == '(') ++sum;
			else --sum;
			if (sum < 0) lr = 0;
		}
		if (!lr)
		{
			sum = 0;
			for (int j = m - 1; j >= 0; --j)
			{
				if (s[j] == ')') ++sum;
				else --sum;
				if (sum < 0) rl = 0;
			}
			if (rl)
			{
				if (l[sum]) ++ans, --l[sum];
				else ++r[sum];
			}
		}
		else
		{
			if (!sum)
			{
				if (zero) ++ans, --zero;
				else ++zero;
			}
			else
			{
				if (r[sum]) ++ans, --r[sum];
				else ++l[sum];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}