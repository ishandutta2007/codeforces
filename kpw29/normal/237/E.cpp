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
const int in = 0;
int n,m,a,b,c,k, w;
char s[1001];
char S[1010][1010]; int CEN[110]; int DL[110];
int mat[1010][1010], cost[1010][1010], out, parent[1010], d[1010], przeplyw; 
int letters[30];
vector <int> v[1010];
bool in_queue[1010];
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
	int N = OUT + 2;
	while (1)
	{
		for (int i=0; i<=N; ++i) d[i] = inf, parent[i] = -1, in_queue[i] = 0;
		d[IN] = parent[IN] = 0;
		SPFA(IN);
		if (d[OUT] == inf) return wyn;
		int bottle = inf, x = OUT;
		while (x != IN)
		{
			bottle = min(bottle, mat[parent[x]][x]);
			x = parent[x];
		}
		
		x = OUT;
		while (x != IN)
		{
			wyn += (cost[parent[x]][x] * bottle);
			mat[parent[x]][x] -= bottle;
			mat[x][parent[x]] += bottle;
			x = parent[x];
		}
		przeplyw += bottle;
	}
	return 0;
}
int main()
{
	scanf("%s", s+1);
	int dl = 1; while (s[dl]) ++dl; --dl;
	scanf("%d", &k);
	for (int i=1; i<=k; ++i) 
	{
		scanf("%s", S[i] + 1);
		DL[i] = 1; 
		while (S[i][DL[i]]) ++DL[i]; 
		--DL[i];
		scanf("%d", &CEN[i]);
	}
	int sum = 0;
	for (int i=1; i<=k; ++i) sum += DL[i];
	for (int i=1; i<=k; ++i) add_edge(in, i, CEN[i], 0);
	for (int i=1; i<=k; ++i) 
	{
		fill(letters, letters+28, 0);
		for (int j=1; j<=DL[i]; ++j) letters[S[i][j] - 'a']++;
		for (int j=0; j<26; ++j) add_edge(i, k + j + 1, letters[j], i);
	}
	for (int i=1; i<=26; ++i) add_edge(i + k, i + k + 26, inf, 0);
	int out = k + 26 + 26 + 1;
	fill(letters, letters+28, 0);
	for (int i=1; i<=dl; ++i) letters[s[i] - 'a']++;
	for (int i=0; i<26; ++i) add_edge(26 + k + i + 1, out, letters[i], 0);
	int COST = MaxFlowMinCost(in, out);
	if (przeplyw == dl) printf("%d", COST);
	else printf("-1");
}