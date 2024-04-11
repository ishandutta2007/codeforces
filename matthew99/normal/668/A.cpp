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

const int maxn = 100, maxm = 100;

int num[maxn * maxm + 5];

int n, m, qn;

int id[maxn + 5][maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, n) REP(j, 0, m) id[i][j] = i * m + j;
	REP(i, 0, qn)
	{
		int ty, x, y, z;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d", &x), --x;
			rotate(id[x], id[x] + 1, id[x] + m);
		}
		else if (ty == 2)
		{
			scanf("%d", &x), --x;
			static int tmp[maxn + 5];
			REP(i, 0, n) tmp[i] = id[(i + 1) % n][x];
			REP(i, 0, n) id[i][x] = tmp[i];
		}
		else if (ty == 3) 
		{
			scanf("%d%d%d", &x, &y, &z), --x, --y;
			num[id[x][y]] = z;
		}
	}
	REP(i, 0, n) 
	{
		REP(j, 0, m) printf("%d ", num[i * m + j]);
		printf("\n");
	}
	return 0;
}