#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 510
int dp[maxn][maxn], odp[maxn][maxn], n, m, mod;

int ile[maxn];
char s[maxn][maxn];
int bin2[maxn], ilo[maxn][maxn];
;

int main()
{
	scanf("%d%d%d", &n, &m, &mod);
	FOR(i, 0, 500) bin2[i] = i * (i-1)/2;
	FOR(i, 0, 500)
	  FOR(j, 0, 500) ilo[i][j] = i * j;
	  
	FOR(i, 1, m) scanf("%s", s[i] + 1);
	FOR(i, 1, m)
	  FOR(j, 1, n) ile[j] += s[i][j] - '0';

	FOR(i, 1, n)
	  if (ile[i] > 2) OUT(0);
	
	int id = 0, ij = 0;
	FOR(i, 1, n)
	{
	  	if (ile[i] == 0) ++id;
	  	if (ile[i] == 1) ++ij;
	}
	//cout << id << ' ' << ij << endl;
	odp[ij][id] = 1;
	int CST = 2 * id + ij;
	FOR(steps, m+1, n)
	{
		FOR(i, 0, id)
		  FOR(j, 0, n)
		  {
		  		if (2 * i + j + 2 * (steps - m) != CST) continue;
		  		ll W = 0;
				ll val = odp[j+2][i];
		  		val = (val * bin2[j+2]);
		  		W += val;
		  		
		  		val = odp[j][i+1];
		  		val = (val * ilo[i+1][j]);
		  		W += val;
		  		
		  		if (j - 2 >= 0)
				{
					val = odp[j-2][i+2];
		  			val = (val * bin2[i+2]);
		  			W += val;
		  		}
		  		dp[j][i] = (W % mod);
		  		//if (dp[i][j] > 0) cout << dp[i][j] << " WSK : " << i << ' ' << j << endl;
		  }
		FOR(i, 0, id)
		  FOR(j, 0, n) odp[j][i] = dp[j][i];
	//	cout << "ENDSTEP\n";
	}
	
	cout << odp[0][0];
}