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

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		static char s[maxn + 5];
		scanf("%s", s);
		int n = strlen(s);
		int cnt0 = 0;
		int left = n, right = 0;
		REP(i, 0, n)
			if (s[i] == '0') 
			{
				++cnt0;
				chkmin(left, i);
				chkmax(right, i);
			}
		if (!cnt0)
		{
			printf("0\n");
		}
		else if (right - left + 1 == cnt0)
		{
			printf("1\n");
		}
		else printf("2\n");
	}
	return 0;
}