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
int n,m,k, a, b, x;
long long A, B;

int main()
{
	scanf("%d", &x);
	if (x == 3) OUT("5");
	int MIN = inf;
	for (int i=1; i<=200; ++i) 
	{
		int n = i;
		if (n % 2 == 0)
		{
			int pole = n * n;
			int blocked = 4 * n - 4;
			pole -= blocked;
			pole /= 2;
			if (x % 4 == 0 && pole >= x) MIN = min(MIN, i);
		}
		else
		{
			int pole = n * n - 2 * n  + 1;
			pole /= 2;
			int dod = n;
			if (pole + dod >= x) MIN = min(MIN, i);
		}

	}
	printf("%d", MIN);
	
}