#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; exit(0); }
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
#define maxn 1010
bool pi[maxn];
int wyn[maxn], ret = 0;
int DL = 0, n;

int main()
{
	scanf("%d",&n);
	for (int i=2; i<=n; ++i) 
	if (pi[i] == false)
	{
		int k=i;
		while (k<=n) 
		{
			wyn[++DL] = k;
			k*=i;
		}
		for (int j=i + i; j<=n; j+=i) pi[j]=true;
	}
	printf("%d\n", DL);
	for (int i=1; i<=DL; ++i) printf("%d ", wyn[i]);
}