#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c,k,x, out, in;
#define OUT(x) {cout << x; return 0; }
int zajete[5010];

int main()
{
	scanf("%d%d", &x, &k);
	zajete[x] = 1;
	for (int i=1; i<=k; ++i)
	{
		int ile;
		scanf("%d", &ile);
		if (ile == 1) ile = 2;
		else ile = 1;
		for (int j=1; j<=ile; ++j)
		{
			scanf("%d", &a);
			zajete[a] = true;
		}
	}
	int wynmax = 0, wynmin = 0;
	for (int i=1; i<=x; ++i) if (!zajete[i]) ++wynmax;
	for (int i=1; i<=x; ++i)
	{
		if (zajete[i]) continue;
		if (zajete[i + 1] == false)
		{
			wynmin++;
			zajete[i] = zajete[i+1] = 1;
		}
		else wynmin++;
	}
	printf("%d %d", wynmin, wynmax);
	return 0;
}