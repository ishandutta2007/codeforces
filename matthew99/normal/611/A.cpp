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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x;
	static char s[100];
	scanf("%d", &x);
	scanf("%s", s);
	scanf("%s", s);
	if (s[0] == 'w')
	{
		int ans = 0;
		REP(i, 0, 366)
		{
			if ((4 + i) % 7 + 1 == x)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	else
	{
		if (x <= 29) printf("12\n");
		else if (x == 30) printf("11\n");
		else printf("7\n");
	}
	return 0;
}