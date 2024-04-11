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

const int maxn = 1100;

int n;
char s[maxn + 5][10];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	bool find = 0;
	REP(i, 0, n) 
	{
		scanf("%s", s[i]);
		if (find) continue;
		if (s[i][0] == 'O' && s[i][1] == 'O') find = 1, s[i][0] = s[i][1] = '+';
		else if (s[i][3] == 'O' && s[i][4] == 'O') find = 1, s[i][3] = s[i][4] = '+';
	}
	if (find)
	{
		puts("YES");
		REP(i, 0, n) puts(s[i]);
	}
	else puts("NO");
	return 0;
}