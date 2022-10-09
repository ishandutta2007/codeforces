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
int a,b,c,k,x, out, in;
#define OUT(x) {cout << x; return 0; }
int zajete[5010], zeros, ones;
int wyn[3001000];
int main()
{
	scanf("%d%d", &zeros, &ones);
	int all = zeros + ones;
	wyn[0] = -1;
	for (int i=1; i<=all; ++i)
	{
		if (wyn[i-1] == 0) wyn[i] = 1, --ones;
		else if (wyn[i-1] == 1 && wyn[i-2] == 1) wyn[i] = 0, --zeros;
		else if (zeros > ones) wyn[i] = 0, zeros--;
		else wyn[i] = 1, ones--;
	}
	//for (int i=1; i<=all; ++i) printf("%d ", wyn[i]);
	
	if (!(zeros == 0 && ones == 0)) puts("-1");
	else
	{
		bool czy = false;
		for (int i=2; i<=all; ++i) if (wyn[i] == 0 && wyn[i-1] == 0) czy = true;
		for (int i=3; i<=all; ++i) if (wyn[i] == 1 && wyn[i-1] == 1 && wyn[i-2] == 1) czy = true;
		if (czy) puts("-1");
		else for (int i=1; i<=all; ++i) printf("%d", wyn[i]);
	}
}