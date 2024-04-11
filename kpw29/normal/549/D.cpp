#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define root 1
#define maxn 300100
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
ll N,M,P,Q,A,B,C;

int t[110][110];
char s[150];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i)
	{
		scanf("%s", s+1);
		for (int j=1; j<=m; ++j)
		{
		  if (s[j] == 'W') t[i][j] = 1;
		  else t[i][j] = -1;
		}
	}

	int wyn = 0;
	for (int i=n; i>0; --i)
	  for (int j=m; j>0; --j)
	  {
		  if (t[i][j] != 0)
		  {
			  int w = -t[i][j];
			  ++wyn;
			  for (int help=1; help<=i; ++help)
			    for (int melp=1; melp<=j; ++melp) t[help][melp] += w;
		 }
	  }
	printf("%d", wyn);
	
}