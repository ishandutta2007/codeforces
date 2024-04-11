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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000100;

int n;
int ty[maxn + 5];
int chd[maxn + 5][2];

int val[maxn + 5];
int ansn = 0;
int id[maxn + 5];
int ans[maxn + 5];

void dfs0(int x)
{
	if (ty[x] == 0)
	{
		val[x] = 1;
		REP(i, 0, 2) 
		{
			dfs0(chd[x][i]);
			val[x] &= val[chd[x][i]];
		}
	}
	if (ty[x] == 1)
	{
		val[x] = 0;
		REP(i, 0, 2) 
		{
			dfs0(chd[x][i]);
			val[x] |= val[chd[x][i]];
		}
	}
	if (ty[x] == 2)
	{
		val[x] = 0;
		REP(i, 0, 2) 
		{
			dfs0(chd[x][i]);
			val[x] ^= val[chd[x][i]];
		}
	}
	if (ty[x] == 3)
	{
		REP(i, 0, 1) 
		{
			dfs0(chd[x][i]);
			val[x] = !val[chd[x][i]];
		}
	}
}

void dfs1(int x, int ch = 1)
{
	if (ty[x] == 4)
	{
		ans[id[x]] = val[0] ^ ch;
		return;
	}
	if (ty[x] == 0)
	{
		REP(i, 0, 2)
		{
			int tmp = ch;
			val[chd[x][i]] = !val[chd[x][i]];
			if ((val[chd[x][0]] & val[chd[x][1]]) == val[x]) tmp = 0;
			val[chd[x][i]] = !val[chd[x][i]];
			dfs1(chd[x][i], tmp);
		}
	}
	if (ty[x] == 1)
	{
		REP(i, 0, 2)
		{
			int tmp = ch;
			val[chd[x][i]] = !val[chd[x][i]];
			if ((val[chd[x][0]] | val[chd[x][1]]) == val[x]) tmp = 0;
			val[chd[x][i]] = !val[chd[x][i]];
			dfs1(chd[x][i], tmp);
		}
	}
	if (ty[x] == 2)
	{
		REP(i, 0, 2)
		{
			int tmp = ch;
			val[chd[x][i]] = !val[chd[x][i]];
			if ((val[chd[x][0]] ^ val[chd[x][1]]) == val[x]) tmp = 0;
			val[chd[x][i]] = !val[chd[x][i]];
			dfs1(chd[x][i], tmp);
		}
	}
	if (ty[x] == 3)
	{
		REP(i, 0, 1)
		{
			dfs1(chd[x][i], ch);
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	ansn = 0;
	REP(i, 0, n)
	{
		static char s[10];
		scanf("%s", s);
		if (s[0] == 'A')
		{
			ty[i] = 0;
			REP(j, 0, 2) scanf("%d", chd[i] + j), --chd[i][j];
		}
		if (s[0] == 'O')
		{
			ty[i] = 1;
			REP(j, 0, 2) scanf("%d", chd[i] + j), --chd[i][j];
		}
		if (s[0] == 'X')
		{
			ty[i] = 2;
			REP(j, 0, 2) scanf("%d", chd[i] + j), --chd[i][j];
		}
		if (s[0] == 'N')
		{
			ty[i] = 3;
			REP(j, 0, 1) scanf("%d", chd[i] + j), --chd[i][j];
		}
		if (s[0] == 'I')
		{
			ty[i] = 4;
			id[i] = ansn++;
			scanf("%d", val + i);
		}
	}
	dfs0(0);
	dfs1(0);
	REP(i, 0, ansn) printf("%d", ans[i]);
	return 0;
}