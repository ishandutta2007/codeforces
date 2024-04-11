#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define OUT(x) {cout << x; exit(0); }
#define pb push_back
#define root 1
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> PLL;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,d,k;
ll N,M,P,Q,A,C;
#define maxn 1000100
vector <int> v[maxn];
int taken[maxn];
bool odw[maxn];
ll x, y, res;
int dp[maxn];
ll ile = 0;
int f[maxn], size[maxn], akt[maxn], licz[maxn];

inline int _find(int a)
{
	if (f[a] == a) return a;
	f[a] = _find(f[a]);
	return f[a];
}
inline void _union(int a, int b)
{
	a = _find(a), b = _find(b);
	if (a == b) return;
	if (size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	size[b] = -1;
	f[b] = a;
}
void dfs(int x)
{
	odw[x] = 1;
	for (unsigned int i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i]])
	  {
		  dfs(v[x][i]);
		  if (taken[x] < 2 && taken[v[x][i]] < 2) ++ile, taken[x]++, taken[v[x][i]]++;
	  }
}
int deg[maxn];

int main()
{
	cin >> n >> x >> y;
	ile = n;
	for (int i=1; i<=n; ++i) f[i] = i, size[i] = 1, akt[i] = i;
	for (int i=1; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	if (x <= y) //maksymalnie wiele krawedzi z drzewa
	{
		ile = 0;
		dfs(1);
		cout << ile * x + (n - 1 - ile) * y;
	}
	else //minimalnie wiele krawedzi z drzewa poprosze
	{
		for (int i=1; i<=n; ++i) 
	{
		for (int j=1; j<=ile; ++j) licz[akt[j]] = 0;
		for (ui j=0; j<v[i].size(); ++j) ++licz[_find(v[i][j])];
		for (int j=1; j<=ile; ++j) 
		  if (licz[akt[j]] != size[akt[j]]) _union(i, akt[j]);
		for (int j=1; j<=ile; ++j)
		{
			if (size[akt[j]] > -1);
			else akt[j] = akt[ile], --ile, --j;
		}
	}
		ll edges = ile - 1;
		ll Edges = (n - 1 - edges);
		//cout << edges << ' ' << Edges << endl;
		OUT(edges * x + Edges * y);
		
	}
}