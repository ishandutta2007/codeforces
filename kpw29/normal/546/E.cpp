#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define in 0
#define out n+n+1
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
int n,m,a,b,c;
#define maxn 310
#define OUT(x) { cout << x; return 0; }
vector <int> v[maxn];
int mat[maxn][maxn], start[maxn][maxn];
int wyk[maxn][maxn];
int parent[maxn];
void bfs(int pocz, int kon)
{
	queue <int> q; while (!q.empty()) q.pop();
	q.push(pocz);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (ui i=0; i<v[x].size(); ++i) 
		if (parent[v[x][i]] == -1 && mat[x][v[x][i]] > 0)
		{
			parent[v[x][i]] = x;
			q.push(v[x][i]);
		}
	}
}
int flow(int IN, int OUT)
{
	int N = OUT + 1, ret = 0;
	while (1)
	{
		for (int i=0; i<=N; ++i) parent[i] = -1;
		parent[IN] = 0;
		bfs(IN, OUT);
		if (parent[OUT] == -1) return ret;
		int MIN = inf, x = OUT;
		while (x != IN)
		{
			MIN = min(MIN, mat[parent[x]][x]);
			x = parent[x];
		}
		x = OUT;
		while (x != IN)
		{
			mat[parent[x]][x] -= MIN;
			mat[x][parent[x]] += MIN;
			x = parent[x];
		}
		ret += MIN;
	}
	
}
int main()
{
	scanf("%d%d", &n, &m);
	int sum1 = 0,sum2 = 0;
	for (int i=1; i<=n; ++i) 
	{
		scanf("%d", &a);
		v[in].pb(i);
		v[i].pb(in);
		mat[in][i] = a;
		sum1 += a;
	}
	for (int i=1; i<=n; ++i) 
	{
		scanf("%d", &a);
		v[i + n].pb(out);
		v[out].pb(i + n);
		mat[i+n][out] = a;
		sum2 += a;
		v[i].pb(i + n);
		v[i + n].pb(i);
		mat[i][i+n] = inf;
	}
	for (int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].pb(b + n);
		v[b].pb(a + n);
		v[b + n].pb(a);
		v[a + n].pb(b);
		mat[a][b+n] = inf;
		mat[b][a+n] = inf;
	}
	for (int i=in; i<=out; ++i)
	for (int j=in; j<=out; ++j) start[i][j] = mat[i][j];
	if (sum1 != sum2) OUT("NO");
	int FLOW = flow(in, out);
	if (FLOW != sum2) OUT("NO");
	//printf("%d\n", FLOW);
	puts("YES");
	for (int i=1; i<=n; ++i)
	{
		for (int j=n+1; j<=n+n; ++j) printf("%d ", start[i][j] - mat[i][j]);
		puts("");
	}
	/*puts("");
	for (int i=0; i<=out; ++i)
	{
		printf("i: %d\n", i);
		for (int j=0; j<v[i].size(); ++j) printf("%d ", v[i][j]);
		puts("");
	}*/
}