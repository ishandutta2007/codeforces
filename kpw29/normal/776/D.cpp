 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 300100
vector <int> v[maxn], rev[maxn];
bool odw[maxn];
int n, m, a, b, DL = 0;
vector <int> topsort;
vector <int> skladowe[maxn];
int skl[maxn], SKL = 0;
int state[maxn];

inline int neg(int x) {
	if (x <= n) return x + n;
	return x - n;
}


void dfs(int x)
{
	odw[x] = 1;
	for (ui i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i]]) dfs(v[x][i]);
	topsort.pb(x);
}

void rdfs(int x)
{
	odw[x] = 1;
	skl[x] = SKL;
	skladowe[SKL].pb(x);
	for (ui i=0; i<rev[x].size(); ++i)
	  if (!odw[rev[x][i]]) rdfs(rev[x][i]);
}
int stan[maxn];
PII controls[maxn];

inline void addEdge(int x, int y)
{
	//cout << "Adding: " << x << ' ' << y << endl;
	v[x].pb(y);
	v[y].pb(x);
	rev[y].pb(x);
	rev[x].pb(y);
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; ++i) scanf("%d", &stan[i]);
	int N = 2 * n;
	
	for (int i=1; i<=n; ++i)
	{
		int ki, aa;
		scanf("%d", &ki);
		for (int j=1; j<=ki; ++j)
		{
			scanf("%d", &aa);
			if (controls[aa].e1 == 0) controls[aa].e1 = i;
			else controls[aa].e2 = i;
		}
	}
	//for (int i=1; i<=m; ++i) cout << controls[i].e1 << ' ' << controls[i].e2 << endl;
	for (int i=1; i<=m; ++i)
	{
		a = controls[i].e1, b = controls[i].e2;
		if (stan[i] == 1)
		{
			//change either none or both
			addEdge(a, b);
			addEdge(neg(a), neg(b));
		}
		else
		{
			addEdge(a, neg(b));
			addEdge(b, neg(a));
		}
	}
	
	for (int i=1; i<=N; ++i) v[0].push_back(i);
	dfs(0);
	fill(odw, odw + N + 5, false);
	for (int i=topsort.size() - 1; i>=0; --i)
	{
		int akt = topsort[i];
		if (akt == 0) continue;
		if (!odw[akt])
		{
			++SKL;
			rdfs(akt);
		}
	}
	//for (int i=1; i<=N; ++i) cout << skl[i] << ' ';
	for (int i=1; i<=n; ++i)
	  if (skl[i] == skl[i+n]) OUT("NO");
	OUT("YES");
}