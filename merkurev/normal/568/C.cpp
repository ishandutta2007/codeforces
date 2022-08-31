#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;



const int maxn = 205;
vector <pair <int, int> > g[maxn][2];
char wc[maxn];
char str[maxn];

bool used[maxn][2][maxn][2];

void dfs(int a, int b, bool u[maxn][2] )
{
	u[a][b] = true;
	for (int i = 0; i < (int) g[a][b].size(); i++)
	{
		int na = g[a][b][i].first;
		int nb = g[a][b][i].second;
		if (u[na][nb] )
			continue;
		dfs(na, nb, u);
	}
}
int n, l;

int need[maxn][2];
char ans[maxn];
bool bad()
{
	for (int i = 0; i < n; i++)
		if (need[i][0] && need[i][1] )
			return true;
	return false;
}

void printAns()
{
	for (int i = 0; i < n; i++)
		ans[i] += 'a';
	printf("%s\n", ans);
}
void pl(int a, int b, int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
		{
			if (used[a][b][i][j] )
			{
//				eprintf("%d %d += %d\n", i, j, x);
				need[i][j] += x;
			}
		}
}
void placeLetter(int a, int b)
{
//	eprintf("place %d : %d\n", a, b);
	ans[a] = b;
	pl(a, wc[b], 1);
}
void unplaceLetter(int a, int b)
{
	pl(a, wc[b], -1);
}

void trySolve(int pos, bool onBound)
{
	if (bad() )
		return;
	if (pos == n)
	{
		printAns();
		exit(0);
	}

	bool test[2] = {false, false};
	
	int start = (onBound ? str[pos] : 0);
	for (int ch = start; ch < l; ch++)
	{
		int t = wc[ch];
		if (test[t] )
			continue;
		placeLetter(pos, ch);
		bool nBound = onBound;
		if (ch != str[pos] )
			nBound = false;
		if (!nBound)
			test[t] = true;
		trySolve(pos + 1, nBound);
		unplaceLetter(pos, ch);
	}
	
}

void solve()
{
	scanf("%s", wc);
	l = strlen(wc);
	for (int i = 0; i < l; i++)
	{
		if (wc[i] == 'V')
			wc[i] = 0;
		else
			wc[i] = 1;
	}
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, ca, cb;
		char sca[2], scb[2];
		scanf("%d%s%d%s", &a, sca, &b, scb);
		a--;
		b--;
		if (sca[0] == 'V')
			ca = 0;
		else
			ca = 1;
		if (scb[0] == 'V')
			cb = 0;
		else
			cb = 1;
		g[a][ca].push_back(make_pair(b, cb) );
		g[b][cb ^ 1].push_back(make_pair(a, ca ^ 1) );
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dfs(i, j, used[i][j] );
		}
		if (used[i][0][i][1] && used[i][1][i][0] )
		{
			printf("-1\n");
			return;
		}
	}

	scanf("%s", str);
	for (int i = 0; i < n; i++)
		str[i] -= 'a';


	for (int eq = n; eq >= 0; eq--)
	{
//		eprintf("\n\neq = %d\n", eq);
		for (int i = 0; i < eq; i++)
			placeLetter(i, str[i] );
		trySolve(eq, true);
		for (int i = 0; i < eq; i++)
			unplaceLetter(i, str[i] );
	}
	printf("-1\n");
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	solve();

	return 0;
}