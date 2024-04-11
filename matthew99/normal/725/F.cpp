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

const int maxn = 200100;

int n;
int a[maxn + 5][2];

bool bbig[maxn + 5];

bool take[maxn + 5][2];
int delta[maxn + 5][2];

int pos[maxn + 5];

bool vis[maxn + 5];

LL income[2];

inline void pick(bool player, int id) 
{ 
	income[player] += a[id][player];
	vis[id] = 1; 
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d%d%d", a[i], a[i] + 1, a[n + i], a[n + i] + 1);
	REP(i, 0, n) 
	{
		delta[i][0] = a[i][0] - a[n + i][1];
		delta[i][1] = a[i][1] - a[n + i][0];
		if (a[n + i][0] + a[n + i][1] >= a[i][0] + a[i][1]) bbig[i] = 1;
		REP(j, 0, 2) take[i][j] = !(delta[i][j] <= 0 && -delta[i][!j] >= delta[i][j]);
	}
	REP(i, 0, n << 1) pos[i] = i;
	sort(pos, pos + (n << 1), [&](int x, int y) { return a[x][0] + a[x][1] > a[y][0] + a[y][1]; });
	int p[2] = {0, 0};
	REP(i, 0, n << 1)
	{
		bool now = i & 1;
		while (p[now] < (n << 1))
		{
			int x = pos[p[now]];
			if (!vis[x])
			{
				if (x >= n)
				{
					if (vis[x - n]) 
					{
						pick(now, x);
						break;
					}
				}
				else if (take[x][now])
				{
					pick(now, x);
					if (bbig[x]) pick(!now, x + n);
					else break;
				}
			}
			++p[now];
		}
	}
	printf("%I64d\n", income[0] - income[1]);
	return 0;
}