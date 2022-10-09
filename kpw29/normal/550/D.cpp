#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define root 1
#define maxn 300100
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
ll N,M,P,Q;
string s;

vector <BONG> wyn;
int NEW,k;
int t[300];
void make(int nowy, int skad)
{
	int ile = k-1;
	int l1 = nowy + k - 1;
	int l2 = nowy + k;
	wyn.pb(mp(l1, l2));
	for (int i=0; i<ile; ++i) 
	{
		wyn.pb(mp(skad, nowy + i));
	}
	for (int i=0; i<ile; ++i) 
	{
		wyn.pb(mp(nowy + i, l1));
		wyn.pb(mp(nowy + i, l2));
	}
	for (int i=0; i<ile; ++i)
	  for (int j=i + 1; j < ile; ++j)
	  {
		  if ((i% 2 == 0) && j == i + 1) continue;
		  wyn.pb(mp(nowy + i, nowy + j));
	  }
	
}

int main()
{
	scanf("%d", &n);
	k = n;
	if (!(n & 1))
	{
		puts("NO");
		return 0;
	}
	else if (n == 1)
	{
		printf("YES\n");
		printf("%d %d\n", 2, 1);
		printf("%d %d", 1, 2);
		return 0;
	}
	else
	{
		printf("YES\n");
		printf("%d %d\n", 2 * k + 4, k * (k + 2));
		make(3, 1);
		make(k + 4, 2);
		wyn.pb(mp(1,2));
		for (ui i=0; i<wyn.size(); ++i) printf("%d %d\n", wyn[i].e1, wyn[i].e2);
	}
	
}