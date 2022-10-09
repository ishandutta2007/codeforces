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
int n,m,a,b,c,k, out, in;
#define OUT(x) {cout << x; return 0; }

int main()
{
	scanf("%d%d", &n, &k);
	ll sum = 0;
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		sum += a;
	}
	if (sum < 0) sum = - sum;
	int wyn = (sum / k);
	if (wyn * k < sum) ++wyn;
	printf("%d", wyn); 
	
	
	return 0;
}