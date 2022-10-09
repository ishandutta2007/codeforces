#include <bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
typedef pair <int, int> BONG;
typedef unsigned int ui;
const int inf = 1e9+9;


int n,m,a,b, ZAP, R;
string s;
const int Q = (1 << 20);
int dr[Q][6];
int t[Q][6];

int query(int x, int y, int j)
{
	x += R-1;
	y += R-1;
	int ret = max(t[x][j], t[y][j]);
	while (x/2 != y/2)
	{
		if (!(x & 1)) ret = max(ret, t[x+1][j]);
		if (y & 1) ret = max(ret, t[y-1][j]);
		x/=2; y/=2;
	}
	return ret;
}
long long policz(int k)
{
	long long akt =inf;
	for (int i=1; i<=n-k+1; ++i)
	  {
		  long long shots =0;
		  for (int j=1; j<=m; ++j) shots += query(i, i+k-1, j);
		  akt = min(akt, shots);
	  }
	return akt;
}
int bin_search(int x, int y)
{
	while (x != y)
	{
		//printf("%d %d\n", x, y);
		int k = (x + y)/2+1;
		if (policz(k) > ZAP) y = k-1;
		else x = k;
	}
	return x;
}
int main()
{
	scanf("%d%d%d", &n, &m, &ZAP);
	R = 2;
	while (R < n) R<<=1;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j) 
		{
			scanf("%d", &dr[i][j]);
			t[i+R-1][j] = dr[i][j];
		}
	for (int i=R-1; i>0; --i)
	  for (int j=1; j<=m; ++j) t[i][j] = max(t[2*i][j], t[2*i+1][j]);
	int wyn =bin_search(0,n);
	//jak juz mamy wynik:
	if (wyn == 0) for (int i=1; i<=m; ++i) printf("0 ");
	else
	{
	for (int i=1; i<=n - wyn+1; ++i)
	{
		int shots = 0;
		for (int j=1; j<=m; ++j) shots += query(i, i+wyn-1, j);
		if (shots <= ZAP)
		{
			for (int j=1; j<=m; ++j) printf("%d ", query(i, i+wyn-1, j));
			break;
		}
	}
}
	//printf("%d", wyn);
}