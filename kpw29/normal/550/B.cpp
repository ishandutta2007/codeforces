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
ll N,M,P,Q;
ll l,r,x;
ll t[maxn];
int w = 0;
int bits[25];
int main()
{
	int wyn =0;
	cin >> n >> l >> r >> x;
	for (int i=1; i<=n; ++i) cin >> t[i];
	int dwa = (1 << n);
	for (int j=0; j<dwa; ++j)
	  {
		  ll MIN = INF, MAX = -1;
		  int help = j;
		  int ile = 0;
		  for (int i=1; i<=n; ++i) 
		  {
			  if (help & 1) bits[i] = true;
			  else bits[i] = false;
			  help >>=1;
		  }

		  ll SUM = 0;
		  for (int i=1; i<=n; ++i) 
		  if (bits[i]) {
		  MAX = max(MAX, t[i]);
		  MIN = min(MIN, t[i]);
		  SUM += t[i];
		  ile++;
		}
		 if (MAX - MIN >= x && SUM >= l && SUM <= r && ile > 1) ++wyn;
	  }
	cout << wyn;
}