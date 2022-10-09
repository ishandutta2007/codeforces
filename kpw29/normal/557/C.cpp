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
int n,m,a,b,c,k, w;
bool odw[1000100];
int val[210];
PII t[1000100];
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &t[i].e1);
	for (int i=1; i<=n; ++i) scanf("%d", &t[i].e2);
	t[0] = mp(-1,-1);
	sort(t+1, t+n+1);
	int ALLCOST = 0;
	int WYN = inf;
	for (int i=1; i<=n; ++i) val[t[i].e2]++, ALLCOST += t[i].e2;
	for (int i=n; i>0; --i)
	{
		if (odw[i]) continue;
		int j = i;
		while (t[j].e1 == t[i].e1) --j;
		++j;
		int act_cost = 0;
		for (int help = j; help <= i; ++help) act_cost += t[help].e2, val[t[help].e2]--, odw[help] = true;
		
		int ile = i - j + 1;
		int MIN = ile - 1;
		for (int j=200; j>0; --j) 
		{
			if (MIN <= 0 || val[j] == 0) continue;
			if (val[j] <= MIN) 
			{
				MIN -= val[j];
				act_cost += (val[j] * j);
			}
			else
			{
				act_cost += (MIN * j);
				MIN = 0;
			}
		}
		WYN = min(WYN, ALLCOST - act_cost);
		//printf("%d %d\n", i, WYN);
	}
	printf("%d", WYN);
}