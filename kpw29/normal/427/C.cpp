#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define milion 1000100
#define tysiac 1010
#define boost ios_base::sync_with_stdio(false)
typedef long long ll;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> DONG;
typedef pair <ll, ll> LONG;
typedef unsigned int ui;
typedef unsigned long long ull;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 100010
int n,m,a,b,c, k, ile, MIN;
ll jednakowe;
vector <int> v[maxn];
vector <int> rev[maxn];
bool odw[milion];
int cost[milion];
vector <int> top;
ll tmp = 0;
void dfs(int x)
{
	odw[x] = true;
	for (int i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i]]) dfs(v[x][i]);
	top.pb(x);
}

void REV(int x)
{
	odw[x] = true;
	if (cost[x] < MIN) MIN = cost[x], jednakowe = 1;
	else if (cost[x] == MIN) jednakowe++;
	++tmp;
	for (int i=0; i<rev[x].size(); ++i)
	  if (!odw[rev[x][i]]) REV(rev[x][i]);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &cost[i]);
	scanf("%d", &m);
	ll wyn =0, wyn2 = 1;
	for (int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		rev[b].pb(a);
	}
	for (int i=1; i<=n; ++i) 
	  if (!odw[i]) dfs(i);
	fill(odw, odw+n+1, false);
	int skl = 0;
	
	for (int i=n-1; i>=0; --i)
	{
		int akt = top[i];
		if (!odw[akt])
		{
			tmp =0;
			MIN = inf;
			++skl;
			jednakowe = 0;
			REV(akt);
			wyn += MIN;
			wyn2 *= jednakowe;
			wyn2 %= mod;
		}
	}
	cout << wyn << " " << wyn2;
}