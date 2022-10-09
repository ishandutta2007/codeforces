#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
#define maxn 1010
int t[maxn][maxn];
int wyn = 0;
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=n; ++j) 
	  {
		  scanf("%d", &t[i][j]);
		  if (i == j) wyn += t[i][i];
	  }
	wyn = wyn % 2;
	int q;
	vector <int> w;
	scanf("%d", &q);
	while (q--)
	{
		int a,b;
		scanf("%d", &a);
		if (a != 3) scanf("%d", &b);
		if (a == 3) w.pb(wyn);
		else wyn = 1 - wyn;
	}
	for (int i=0; i<w.size(); ++i) printf("%d", w[i]);
	
}