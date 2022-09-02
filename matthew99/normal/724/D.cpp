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

const int maxn = 100010;

int n, m;
char s[maxn + 5];

int cnt[26];

inline int work(int x)
{
	int ret = 0;
	int lst = -1;
	int lstx = -1;
	REP(i, 0, n)
	{
		if (s[i] - 'a' < x) lst = i;
		else if (s[i] - 'a' == x) lstx = i;
		if (lst <= i - m)
		{
			if (lstx <= i - m) return -1;
			++ret;
			lst = lstx;
		}
	}
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &m);
	scanf("%s", s), n = strlen(s);
	REP(i, 0, n) ++cnt[s[i] - 'a'];
	REP(i, 0, 26)
	{
		int tmp = work(i);
		if (~tmp)
		{
			REP(j, 0, i) REP(k, 0, cnt[j]) putchar('a' + j);
			REP(j, 0, tmp) putchar('a' + i);
			break;
		}
	}
	return 0;
}