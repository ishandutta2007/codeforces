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

const int maxn = 100100;

int n;
char s[maxn + 5][7];
int ty[maxn + 5];

bool vis[1001000];

int now[maxn + 5];

int ansn = 0;
char ans[1000000][31];

bool in[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(now, -1, sizeof now);
	scanf("%d", &n);
	int cnt = 0;
	memset(vis, 0, sizeof vis);
	REP(i, 0, n)
	{
		scanf("%s%d", s[i], ty + i), cnt += ty[i];
		if (s[i][0] != '0')
		{
			bool failed = 0;
			for (int j = 0; s[i][j]; ++j)
				if (!isdigit(s[i][j]))
				{
					failed = 1;
					break;
				}
			if (failed) continue;
			int tmp = atoi(s[i]);
			vis[tmp] = 1;
			if (tmp >= 1 && tmp <= n)
			{
				in[i] = 1;
				now[tmp] = ty[i];
			}
		}
	}
	int buffer = n + 1;
	while (vis[buffer]) ++buffer;
	vector<int> le, le_empty, ri, ri_empty;
	REP(i, 1, cnt + 1)
	{ 
		if (now[i] == 0) le.pb(i);
		else if (!~now[i]) le_empty.pb(i);
	}
	REP(i, cnt + 1, n + 1)
	{
		if (now[i] == 1) ri.pb(i);
		else if (!~now[i]) ri_empty.pb(i);
	}
	while (SZ(le) || SZ(ri))
	{
		if (!SZ(le_empty) && !SZ(ri_empty))
		{
			int x = le.back(), y = ri.back();
			le.pop_back();
			ri.pop_back();
			ri_empty.pb(y);
			now[y] = -1;
			now[x] = 1;
			in[x] = 0;
			sprintf(s[x], "%d", buffer);
			sprintf(ans[ansn++], "move %d %d", x, buffer);
			sprintf(ans[ansn++], "move %d %d", y, x);
		}
		else if (SZ(ri_empty) && SZ(le))
		{
			int x = le.back(), y = ri_empty.back();
			le.pop_back();
			le_empty.pb(x);
			ri_empty.pop_back();
			now[x] = -1;
			now[y] = 0;
			sprintf(ans[ansn++], "move %d %d", x, y);
		}
		else if (SZ(le_empty) && SZ(ri))
		{
			int x = ri.back(), y = le_empty.back();
			ri.pop_back();
			ri_empty.pb(x);
			le_empty.pop_back();
			now[x] = -1;
			now[y] = 1;
			sprintf(ans[ansn++], "move %d %d", x, y);
		}
	}
	int j = 1, k = cnt + 1;
	REP(i, 0, n) if (!in[i])
	{
		if (!ty[i])
		{
			while (~now[k]) ++k;
			sprintf(ans[ansn++], "move %s %d", s[i], k);
			now[k] = 0;
		}
		else
		{
			while (~now[j]) ++j;
			sprintf(ans[ansn++], "move %s %d", s[i], j);
			now[j] = 1;
		}
	}
	printf("%d\n", ansn);
	REP(i, 0, ansn) printf("%s\n", ans[i]);
	return 0;
}