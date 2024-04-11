#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int mod = 1e8;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
#define tys 1010
int n, m, k, a, b, c;
char s[11];
int DL = 0, tab[11];
int odl[tys][11][11]; //[ile_elementow][ile_wiecej_na_szalce][ostatni_uzyty]
int last[tys][11][11];
queue <PPI> q;
void bfs()
{
	while (!q.empty())
	{
		PPI x = q.front();
		///printf("%d %d %d\n", x.e1.e1, x.e1.e2, x.e2);
		q.pop();
		if (x.e1.e1 > n) continue;
		for (int i=1; i<=DL; ++i)
		  if (tab[i] != x.e2 && tab[i] > x.e1.e2 && odl[x.e1.e1 + 1][tab[i] - x.e1.e2][tab[i]] == 0)
		  {
			  odl[x.e1.e1 + 1][tab[i] - x.e1.e2][tab[i]] = odl[x.e1.e1][x.e1.e2][x.e2] + 1;
			  last[x.e1.e1 + 1][tab[i] - x.e1.e2][tab[i]] = x.e2;
			  q.push(mp(mp(x.e1.e1 + 1, tab[i] - x.e1.e2), tab[i]));
		  }
	}
}

int main()
{
	scanf("%s%d", s + 1, &n);
	for (int i=1; i<=10; ++i)
	  if (s[i] == '1') tab[++DL] = i;
	odl[0][0][-1] = 1;
	q.push(mp(mp(0, 0), -1));
	bfs();
	for (int i=1; i<=10; ++i)
	  for (int j=1; j<=DL; ++j)
	  {
		  if (odl[n][i][tab[j]])
		  {
			  vector <int> ans;
			  ans.clear();
			  int akt = n, roz = i, ost = tab[j];
			  while (akt > 0)
			  {
				  ans.push_back(ost);
				  int nowy = last[akt][roz][ost];
				  roz = (ost - roz);
				  akt--;
				  ost = nowy;
			  }
			  puts("YES");
			  for (int i=ans.size() - 1; i >= 0; --i) printf("%d ", ans[i]);
			  exit(0);
		  }
	  }
	puts("NO");
}