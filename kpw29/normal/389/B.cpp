#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 1000100
int n;
char t[2010][2010];
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%s", t[i] + 1);
	bool ok = true;
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=n; ++j)
	  if (t[i][j] == '#')
	  {
		  if (t[i+1][j-1] == '#' && t[i+1][j] == '#' && t[i+1][j+1] == '#' && t[i+2][j] == '#')
		  {
			  t[i+1][j-1] = '.';
			  t[i+2][j] = '.';
			  t[i+1][j+1] = '.';
			  t[i+1][j] = '.';
		  }
		  else ok = false;
	  }
	if (ok) puts("YES");
	else puts("NO");
	return 0;
}