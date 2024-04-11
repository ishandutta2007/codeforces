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
int n,m,a,b,c,k;
long double wyn = 0;
int R[20], M[20];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &M[i]);
	for (int i=1; i<=n; ++i) scanf("%d", &R[i]);
	int all = 1000000, ile = 0;
	for (int D = 1; D <= all; ++D)
	{
		bool dobrze = 1;
		for (int i=1; i<=n; ++i)
		  if (D % M[i] == R[i]) {
			  dobrze = 0;
			  break;
		  }
		if (!dobrze) ++ile;
	}
	printf("%.15lf", (double)ile / (double)all);
	
}