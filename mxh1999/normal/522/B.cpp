/*
    Template Fimbulvetr ver 0.11
    In the darkness, I will find peace.
    Author: Falsyta
    Date: March 4th, 2015
*/
  
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <cmath>
# include <algorithm>
# include <queue>
# include <vector>
# include <map>
# include <set>
# include <string>
  
# define REP(i, n) for (int i = 1; i <= n; i ++)
# define REP_0(i, n) for (int i = 0; i < n; i ++)
# define REP_0N(i, n) for (int i = 0; i <= n; i ++)
# define REP_D(i, n) for (int i = n; i > 0; i --)
# define REP_D0(i, n) for (int i = n - 1; i >= 0; i --)
# define REP_D0N(i, n) for (int i = n; i >= 0; i --)
# define REP_G(i, x) for (int i = pos[x]; i; i = g[i].frt)
# define FOR(i, a, b) for (int i = a; i <= b; i ++)
# define DWN(i, a, b) for (int i = b; i >= a; i --)
# define RST(a) memset (a, 0, sizeof (a))
# define CLR(a, x) memset (a, x, sizeof (a))
# define CPY(a, b) memcpy (a, b, sizeof (a))
  
# define pii pair <int, int>
# define pb push_back
# define mp make_pair
# define v1 first
# define v2 second
  
using namespace std;
  
typedef long long LL;
typedef long double DB;
  
const int inf = 1 << 30;
const LL lnf = 1LL << 60;
  
bool RlxN (int &x, int y) {if (x > y) {return x = y, 1;} return 0;}
bool RlxX (int &x, int y) {if (x < y) {return x = y, 1;} return 0;}

int n;
int st[401000][20], w[201000], h[201000];
int Ask (int l, int r)
{
	if (l > r) return 0;
	int p = int (log (r - l + 1) / log (2));
	return max (st[l][p], st[r - (1 << p) + 1][p]);
}
int main ()
{
	//freopen ("B.in", "r", stdin);
	scanf ("%d", &n);
	int sum = 0;
	REP (i, n) scanf ("%d%d", &w[i], &h[i]), sum += w[i];
	REP (i, n) st[i][0] = h[i];
	for (int i = 1; (1 << i) <= n; i ++)
		for (int j = 1; j + (1 << i) - 1 <= n; j ++)
			st[j][i] = max (st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
	REP (i, n) printf ("%I64d ", 1LL * (sum - w[i]) * max (Ask (1, i - 1), Ask (i + 1, n)));
	puts ("");
	return 0;
}