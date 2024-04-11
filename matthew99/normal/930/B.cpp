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

int n;
char s[maxn + 5];

int cnt[27][maxn + 5][27];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n) REP(j, 0, n) if (i != j)
	{
		++cnt[s[i] - 'a'][(j - i + n) % n][s[j] - 'a'];
	}
	int ans = 0;
	REP(i, 0, 26) 
	{
		int Max = 0;
		REP(j, 0, n) 
		{
			int tmp = 0;
			REP(k, 0, 26)
				if (cnt[i][j][k] == 1) ++tmp;
			chkmax(Max, tmp);
		}
		ans += Max;
	}
	printf("%.15f\n", (double)ans / n);
	return 0;
}