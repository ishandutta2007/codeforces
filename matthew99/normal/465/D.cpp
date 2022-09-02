#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

int a[8][3], b[8][3], c[8][3];
int pos[8][3];

bool ans = 0;

template <typename T> inline T sqr(const T &x) { return x * x; }

inline LL dis(const int &x)
{
	LL ret = 0;
	REP(i, 0, 3) ret += sqr((LL)c[x][i]);
	return ret;
}

LL d[8];

inline bool cmp(const int &x, const int &y)
{
	return d[x] < d[y];
}

inline LL cross(const int &x, const int &y)
{
	LL ret = 0;
	REP(i, 0, 3) ret += (LL)c[x][i] * c[y][i];
	return ret;
}

inline bool work()
{
	int pos[7];
	memcpy(c, a, sizeof c);	
	REP(i, 1, 8)
	{
		REP(j, 0, 3) c[i][j] -= c[0][j];
		d[i] = dis(i);
	}
	REP(i, 0, 7) pos[i] = i + 1;
	sort(pos, pos + 7, cmp);
	if (!d[pos[0]]) return 0;
	if (d[pos[0]] != d[pos[1]] || d[pos[1]] != d[pos[2]]) return 0;
	REP(i, 1, 3)
		REP(j, 0, i)
			if (cross(pos[i], pos[j])) return 0;
	bool appear[8];
	memset(appear, 0, sizeof appear);
	appear[0] = appear[1] = appear[2] = appear[4] = 1;
	REP(i, 3, 7)
	{
		int tmp = 0;
		REP(j, 0, 3)
		{
			LL tmp0 = cross(pos[i], pos[j]);
			tmp0 = abs(tmp0);
			if (tmp0 && tmp0 != d[pos[0]]) return 0;
			if (tmp0) tmp |= 1 << j;
		}
		if (appear[tmp]) return 0;
		appear[tmp] = 1;
	}
	return 1;
}

void dfs(const int &x)
{
	if (x == 8)
	{
		if (work()) ans = 1;
		return;
	}
	REP(i, 0, 6)
	{
		REP(j, 0, 3) a[x][j] = b[x][pos[x][j]];
		dfs(x + 1);
		if (ans == 1) return;
		next_permutation(pos[x], pos[x] + 3);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, 8)
		REP(j, 0, 3)
			scanf("%d", &b[i][j]), pos[i][j] = j;
	memcpy(a[0], b[0], sizeof a[0]);
	dfs(1);
	if (ans == 1)
	{
		printf("YES\n");
		REP(i, 0, 8)
		{
			REP(j, 0, 3)
				printf("%d ", b[i][pos[i][j]]);
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}