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


vector <pii> Q[601000];
map <int, int> A;
int a[601000], t[1300100], n, m, ans[601000];
int Min (int x, int val) {for (; x <= n; x += x & -x) t[x] = min (t[x], val);}
int Query (int x) {int ret = inf; for (; x; x -= x & -x) ret = min (t[x], ret); return ret;}
void Solve ()
{
	REP (i, n)
	{
		if (A.find (a[i]) != A.end ())
		{
			int p = A[a[i]];
			Min (n - p + 1, i - p);
			//printf ("%d %d %d\n", p, i, n - p + 1);
		}
		A[a[i]] = i;
		//printf ("t: %d\n", Query (3));
		int tl = Q[i].size ();
		REP_0 (j, tl) ans[Q[i][j].v2] = Query (n - Q[i][j].v1 + 1);
	}
}
int main ()
{
	//freopen ("C.in", "r", stdin);
	scanf ("%d%d", &n, &m); int t1, t2;
	REP (i, n) scanf ("%d", &a[i]);
	REP (i, 2 * n) t[i] = inf;
	REP (i, m) scanf ("%d%d", &t1, &t2), Q[t2].pb (mp (t1, i));
	Solve ();
	REP (i, m) 
	{
		if (ans[i] != inf) printf ("%d\n", ans[i]);
		else printf ("-1\n");
	}
	return 0;
}