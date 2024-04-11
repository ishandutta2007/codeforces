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

const int maxn = 200;

int n;
char s[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char c[] = "BGR";
	scanf("%d%s", &n, s);
	int cnt[3] = {0};
	REP(i, 0, n)
	{
		if (s[i] == 'B') ++cnt[0];
		else if (s[i] == 'G') ++cnt[1];
		else ++cnt[2];
	}
	if (cnt[0] && cnt[1] && cnt[2]) puts("BGR");
	else
	{
		int sum = 0;
		REP(i, 0, 3) sum += !!cnt[i];
		if (sum == 1)
		{
			REP(i, 0, 3) if (cnt[i]) putchar(c[i]);
		}
		else
		{
			bool ok[3] = {0};
			int p = -1;
			REP(i, 0, 3) if (cnt[i] == 1) p = i;
			if (p == -1) puts("BGR");
			else
			{
				int p0 = -1;
				REP(i, 0, 3) if (i != p && cnt[i]) p0 = i;
				assert(p0 != -1);
				ok[3 - p0 - p] = 1;
				if (cnt[p0] > 1) ok[p] = 1;
			}
			REP(i, 0, 3) if (ok[i]) putchar(c[i]);
		}
	}
	return 0;
}