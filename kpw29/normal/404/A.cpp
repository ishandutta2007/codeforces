#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define e1 first
#define e2 second
typedef long long ll;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
typedef unsigned int ui;
typedef unsigned long long ull;
const int inf = 1e9+9;
const ll INF = 1e18+18;
const int mod = 1e9+7;

ll potmod(ll a, ll b)
{
	if (!b) return 1;
	if (b & 1) return a%mod*potmod(a*a%mod, b>>1)%mod;
	return potmod(a*a%mod, b>>1)%mod;
}
int n,a,b,c,m;
char t[310][310];
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	 for (int j=1; j<=n; ++j) scanf(" %c", &t[i][j]);
	char lit = t[1][2];
	char x = t[1][1];
	bool ok = true;
	if (lit == x) ok = false;
	for (int i=1; i<=n; ++i)
	for (int j=1; j<=n; ++j)
	{
		int czyx = 0;
		if (i == j || (i == (n - j + 1))) czyx = 1;
		if (czyx)
		{
			if (t[i][j] != x) ok =false;
		}
		else if (t[i][j] != lit) ok = false;
		}
	
	if (ok) puts("YES");
	else puts("NO");
	return 0;
	
}