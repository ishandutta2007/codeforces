#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<101> bset;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 300100

ll d[maxn];
int n, m, a, b, c, start, counter;
vector <PII> graf[maxn];
int A[maxn], B[maxn], C[maxn], wlot[maxn], wygraj[maxn];
vector <int> v[maxn], top, rv[maxn];
bool odw[maxn], son[maxn], wyrzuc[maxn];

void dfs(int x) 
{
	odw[x] = 1;
	for (auto u : v[x])
	if (!odw[u]) dfs(u);
	top.pb(x);
}

void dijkstra(int start)
{
	set <PLI> q;
	while (!q.empty()) q.erase(q.begin());
	
	FOR(i, 1, n) d[i] = INF;
	d[start] = 0;
	q.insert({d[start], start});
	
	while (!q.empty())
	{
		int x = (*q.begin()).e2;
		q.erase(q.begin());
		for (auto u : graf[x])
		if (d[x] + u.e2 < d[u.e1])
		{
			q.erase({d[u.e1], u.e1});
			d[u.e1] = d[x] + u.e2;
			q.insert({d[u.e1], u.e1});
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &start);
	FOR(i, 1, m)
	{
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		graf[A[i]].pb({B[i], C[i]});
		graf[B[i]].pb({A[i], C[i]});
	}
	dijkstra(start);

	FOR(i, 1, m)
	{
		a = A[i]; b = B[i]; 
		ll cc = C[i];
		if (d[a] + cc == d[b]) v[a].pb(b), rv[b].pb(a);
		if (d[b] + cc == d[a]) v[b].pb(a), rv[a].pb(b);
	}
	
	/*FOR(i, 1, n)
	{
		cout << "i: " << i << ' ' << (int)v[i].size() << endl;
		for (auto u : v[i]) cout << u << ' ';
		cout << endl;
	}*/
	
	top.clear();
	dfs(start);
	reverse(top.begin(), top.end());
	
	for (auto u : v[start]) son[u] = 1;
	int maxx = 0;
	
	for (auto akt : top)
	{
		bool sett = 0;
		if (akt == start || son[akt] == 1) continue;
		int ojciec = 0;
		for (auto nowe : rv[akt])
		{
			if (!wyrzuc[nowe] && ojciec == 0) ojciec = nowe;
			else if (!wyrzuc[nowe] && ojciec != nowe) sett = 1;
		}
		
		if (sett) continue;

		wygraj[ojciec]++; //mamy nowy wierzcholek w ojcu
		for (auto u : v[akt]) rv[u].pb(ojciec); //mamy nowego ojca
		wyrzuc[akt] = 1;
	}
	//for (auto akt : top) cout << akt << ' ' << wyrzuc[akt] << endl;
	
	for (auto akt : top)
		if (akt != start) maxx = max(maxx, wygraj[akt] + 1);
		
	cout << maxx;
}