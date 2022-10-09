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
int n,m,a,b,c;
#define maxn 510
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
bool DASIE = 0;
int Bears;
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
		if (ret >= Bears)  {
			DASIE = 1;
			return 0;
		}
		///printf("RET: %d\n", ret);
	}
	return ret;
}
int A[maxn], B[maxn], C[maxn];

long double EPS = 1e-9;
inline void addEdge(int x, int y, int cost) {
	mat[x][y] = cost;
}
int main()
{
	scanf("%d%d%d", &n, &m, &Bears);
	for (int i=1; i<=m; ++i) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		a = A[i]; b = B[i];
		v[a].pb(b);
		v[b].pb(a);
	}
	double x = 0, y = 500 * 1000000 + 3;
	while (abs(y - x) > EPS) {
		//cout << x << ' ' << y << endl;
		DASIE = 0;
		for (int i=1; i<=n; ++i)
		  for (int j=1; j<=n; ++j) mat[i][j] = 0;
		double sr = (x + y) / 2;
		for (int i=1; i<=m; ++i) {
			int cap = ((double)C[i] / sr);
			addEdge(A[i], B[i], cap);
		}
		int fajnosc = flow(1, n);
		if (DASIE) x = sr;
		else y = sr - EPS;
	}
	double wyn = x * (double)Bears;
	if (abs(wyn - EPS) != 0) wyn = max(wyn, (double)1);
	printf("%.15lf", wyn);
}