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

const int maxm = 6;

int n, m;
vector<int> all[maxm];

int res[maxm];

int f[maxm][maxm];

bool check()
{
	REP(i, 0, m) if (!res[i]) REP(j, 0, m) if (f[i][j]) return 0;
	REP(i, 0, 1 << m)
	{
		int cnt = 0;
		REP(j, 0, m) if (i >> j & 1) cnt -= res[j];
		if (!cnt) continue;
		REP(j, 0, m) if (i >> j & 1) REP(k, 0, j + 1) if (i >> k & 1) cnt += f[j][k];
		if (cnt >= 0) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int u = i;
		int cnt = -1;
		while (u)
		{
			++cnt;
			u /= 10;
		}
		all[cnt].pb(i);
		m = cnt + 1;
	}
	REP(i, 0, m) res[i] = SZ(all[i]);
	REP(i, 0, n - 1)
	{
		static char a[100], b[100];
		scanf("%s%s", a, b);
		int x = strlen(a), y = strlen(b);
		++f[x - 1][y - 1];
		if (x != y) ++f[y - 1][x - 1];
	}
	if (!check()) printf("-1\n");
	else
	{
		int now = n - 1;
		while (now)
		{
			REP(a, 0, m) REP(b, 0, m)
				if (f[a][b])
				{
					--f[a][b], --res[a];
					if (a != b) --f[b][a];
					if (!check()) 
					{
						++f[a][b], ++res[a];
						if (a != b) ++f[b][a];
					}
					else 
					{
						--now;
						printf("%d ", all[a][SZ(all[a]) - 1]);
						all[a].pop_back();
						printf("%d\n", all[b][SZ(all[b]) - 1]);
					}
				}
		}
	}
	return 0;
}