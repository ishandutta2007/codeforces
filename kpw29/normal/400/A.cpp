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
int n,m,k,a,b,c,x ,y;
ll N,M,K,A,B,C;
int T;
char s[1010];
int t[1010];
int main()
{
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		int dl = 12;vector <int> wyn;
		wyn.clear();
		for (int i=1; i<=dl; ++i) t[i] = (s[i] == 'X')? 1 : 0;
		for (int i=1; i<=dl; ++i)
		{
			if (dl % i != 0) continue;
			int reszty[15];
			for (int j=0; j<=dl; ++j) reszty[j] = 0;
			int ile = dl / i;
			for (int j=1; j<=dl; ++j) reszty[j % ile]+= t[j];
			
			bool czy = true;
			for (int j=0; j<ile; ++j) 
			{
				if (reszty[j] == i) czy = false;
				//printf("%d ", reszty[j]);
			}
			if (!czy)
			{
				wyn.pb(ile);
			}
		}
		printf("%d ", wyn.size());
		for (int i=0; i<wyn.size(); ++i) printf("%dx%d ", 12/wyn[i], wyn[i]);
		puts("");
	}
	return 0;
}