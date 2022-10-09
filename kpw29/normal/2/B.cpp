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
PII zer = mp(0, 0);
int tab[tys][tys][2];
int t[tys][tys][2];
int main()
{
	scanf("%d", &n);
	for (int k=0; k<2; ++k)
	  for (int i=0; i<=n; ++i)
	    for (int j=0; j<=n; ++j) tab[i][j][k] = inf;
	tab[0][1][0] = tab[0][1][1] = 0;
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=n; ++j)
	  {
		  scanf("%d", &a);
		  if (a == 0)
		  {
			  t[i][j][1] = 1000;
			  t[i][j][0] = 1000;
			  zer = mp(i, j);
		  }
		  else 
		  {
			  int el = 0;
			  while (a % 2 == 0) ++el, a /= 2;
			  t[i][j][0] = el;
			  el = 0;
			  while (a % 5 == 0) ++el, a /= 5;
			  t[i][j][1] = el;
		  }
	  }
	for (int k=0; k<2; ++k)
	  for (int i=1; i<=n; ++i)
	    for (int j=1; j<=n; ++j) tab[i][j][k] = min(tab[i-1][j][k], tab[i][j-1][k]) + t[i][j][k];

	PII start = mp(0, 0);
	int wyn = min(tab[n][n][0], tab[n][n][1]);
	if (wyn > 0 && zer != start) //special case
	{
		puts("1");
		for (int i=1; i<zer.e1; ++i) printf("D");
		for (int i=1; i<zer.e2; ++i) printf("R");
		for (int i=zer.e1; i<n; ++i) printf("D");
		for (int i=zer.e2; i<n; ++i) printf("R");
		exit(0);
	}
	vector <char> tmp;
	int esc = 0;
	if (tab[n][n][1] < tab[n][n][0]) ++esc;
	int x = n, y = n;
	while (x > 1 || y > 1) {
		if (tab[x-1][y][esc] < tab[x][y-1][esc]) 
		{
			tmp.pb('D');
			x--;
		}
		else 
		{
			tmp.pb('R');
			y--;
		}
	}
	printf("%d\n", wyn);
	for (int i=tmp.size() - 1; i >= 0; --i) printf("%c", tmp[i]);
}