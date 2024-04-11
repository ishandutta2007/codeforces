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
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
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
int n,m,a,b,c,k, w;
int mat[3010][3010], cost[3010][3010], in, out, parent[3010], d[3010], przeplyw; 
vector <int> v[3010];
bool in_queue[3010];
void add_edge(int x, int y, int ile, int cena)
{
	mat[x][y] = ile;
	v[x].pb(y);
	v[y].pb(x);
	cost[x][y] = cena;
	cost[y][x] = -cena;
}
void SPFA(int vertex)
{
	queue <int> q;
	while (!q.empty()) q.pop();
	q.push(vertex);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		in_queue[x] = false;
		for (ui i=0; i<v[x].size(); ++i) 
		{
			int u = v[x][i];
			if (mat[x][u] > 0 && d[x] + cost[x][u] < d[u])
			{
				d[u] = d[x] + cost[x][u];
				parent[u] = x;
				if (in_queue[u] == false)
				{
					in_queue[u] = 1;
					q.push(u);
				}
			}
		}
	}
}

int MaxFlowMinCost(int IN, int OUT)
{
	int wyn = 0;
	int N = OUT;
	while (1)
	{
		for (int i=0; i<=N; ++i) d[i] = inf, parent[i] = -1, in_queue[i] = 0;
		d[IN] = parent[IN] = 0;
		SPFA(IN);
		if (d[OUT] == inf) 
		{
			printf("%d\n", -wyn);
			FOR(i, 1, n)
			  if (mat[i][n+1] == 0) printf("%d ", i);
			puts("");
			FOR(i, 1, n)
			  if (mat[i][n+2] == 0) printf("%d ", i);
			exit(0);
		}
		//cout << "FLOWNN" << endl;
		int x = OUT;

		while (x != IN)
		{
			wyn += cost[parent[x]][x];
			mat[parent[x]][x]--;
			mat[x][parent[x]]++;
			x = parent[x];
		}
	}
}
#define maxn 3010
int sport[maxn], infa[maxn];
int p, s;
int main()
{
	boost;
	cin >> n >> p >> s;
	FOR(i, 1, n) cin >> sport[i];
	FOR(i, 1, n) cin >> infa[i];
	out = n + 3, in = 0;
	FOR(i, 1, n) add_edge(in, i, 1, 0);
	FOR(i, 1, n) add_edge(i, n+1, 1, -sport[i]);
	FOR(i, 1, n) add_edge(i, n+2, 1, -infa[i]);
	add_edge(n+1, out, p, 0);
	add_edge(n+2, out, s, 0);

	int wynik = MaxFlowMinCost(in, out);
}