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

const int maxn = 100000, maxm = 100000;

int n, m;

pair<int, int> a[maxm + 5];

int pos[maxm + 5];

pair<int, int> ans[maxm + 5];

inline bool cmp(int x, int y)
{
	if (a[x].x == a[y].x) return a[x].y > a[y].y;
	return a[x].x < a[y].x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m) scanf("%d%d", &a[i].x, &a[i].y), pos[i] = i;
	sort(pos, pos + m, cmp);
	int now = 1;
	int x = 1, y = 0;
	REP(i, 0, m)
	{
		if (!a[pos[i]].y)
		{
			--y;
			if (y < 0) 
			{
				++x;
				y = x - 2;
			}
			if (x >= now)
			{
				printf("-1\n");
				return 0;
			}
			ans[pos[i]] = mp(x, y);
		}
		else ans[pos[i]] = mp(now - 1, now), ++now;
	}
	REP(i, 0, m) printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
	return 0;
}