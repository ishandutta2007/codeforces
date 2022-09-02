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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 3000;

int n, m;
char s[maxn + 5][maxn + 5];

int to[maxn + 5][maxn + 5], from[maxn + 5][maxn + 5];

int c[maxn + 5];

inline void add(int x, int y) { for (int i = x + 1; i > 0; i -= i & -i) c[i] += y; }
inline int query(int x) { int ret = 0; for (int i = x + 1; i <= m; i += i & -i) ret += c[i]; return ret; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", s[i]);
	REP(i, 0, n)
	{
		int lst = 0;
		REP(j, 0, m) { if (s[i][j] == '.') lst = j + 1; from[i][j] = lst; }
		lst = m;
		for (int j = m - 1; j >= 0; --j) { if (s[i][j] == '.') lst = j; to[i][j] = lst; }
	}
	LL ans = 0;
	REP(i, 0, n + m - 1)
	{
		memset(c, 0, sizeof c);
		int x = i, y = 0;
		static vector<int> all[maxn + 5];
		REP(j, 0, m + 1) all[j].clear();
		int lst = 0;
		REP(j, 0, min(m, i + 1))
		{
			if (x < n)
			{
				for (auto x : all[y]) add(x, -1);
				if (s[x][y] == '.') lst = y + 1;
				else
				{
					add(y, 1);
					ans += query(max(lst, from[x][y]));
					all[to[x][y]].pb(y);
				}
			}
			--x, ++y;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}