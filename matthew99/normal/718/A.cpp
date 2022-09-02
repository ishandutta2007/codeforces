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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	static char s[maxn + 5];
	int t;
	scanf("%d%d", &n, &t);
	scanf("%s", s);
	int lst = -1;
	int Max = -1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (s[i] == '.') continue;
		if (~lst && lst <= t) Max = i;
		if (s[i] >= '5') lst = 1;
		else if (s[i] < '4') lst = -1;
		else if (~lst) ++lst;
		if (s[i + 1] == '.') break;
	}
	if (~Max)
	{
		int p = -1;
		bool over = 0;
		for (int j = Max; j >= 0; --j)
		{
		    if (s[j] == '.') continue;
			if (s[j] != '9')
			{
				p = j;
				break;
			}
		}
		REP(j, p, n) if (s[j] == '.') over = 1;
		if (!~p)
		{
			printf("1");
			REP(i, 0, n)
			{
				if (s[i] == '.') break;
				printf("0");
			}
			printf("\n");
		}
		else if (!over)
		{
			++s[p];
			s[p + 1] = 0;
			printf("%s\n", s);
		}
		else
		{
			++s[p];
			REP(i, p + 1, n)
			{
				if (s[i] == '.')
				{
					s[i] = 0;
					break;
				}
				s[i] = '0';
			}
			printf("%s\n", s);
		}
	}
	else printf("%s\n", s);
	return 0;
}