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
#define maxn 110
int t[maxn];
int tab[maxn][maxn];
int kol[maxn];
int main()
{
	boost;
	cin >> n;
	int maks = 0;
	for (int i=1; i<=n; ++i) 
	{
		cin >> t[i];
		maks = max(maks, t[i]);
	}
	for (int i=1; i<=maks; ++i)
	  for (int j=1; j<=n; ++j) 
	    if (t[j] >= i) kol[i]++;
	
	for (int i=1; i<=maks; ++i)
	  for (int j=1; j<=kol[i]; ++j) tab[maks - i + 1][n - j +1] = 1;
	for (int i=1; i<=n; ++i)
	
	  {
		  int ret =0;
		  for (int j=1; j<=maks; ++j) ret += tab[j][i];
		  cout << ret << ' ';
	  }
}