#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, m, k, a, b, c, DL = 0, T;
#define maxn 1000100
vector <int> v[maxn];
int MIN[maxn], global, parent[maxn], type;
bool black[maxn];
void dfs(int x, int par)
{
	parent[x] = par;
	for (auto u : v[x])
		if (u != par)
		{
			MIN[u] = min(MIN[u], MIN[x]);
			dfs(u, x);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	FOR(i, 1, n) MIN[i] = i;
	FOR(i, 2, n) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int last = 0;
	cin >> type >> a;
	a = (a + last)%n + 1;
	dfs(a, a);
	black[a] = 1;
	global = a;

	FOR(i, 2, m)
	{
		cin >> type >> a;
		a = (a + last)%n + 1;
		
		if (type == 1)
		{
			while (!black[a])
			{
				global = min(global, a);
				black[a] = 1;
				a = parent[a];
			}
		}
		else
		{
			last = min(MIN[a], global);
			cout << last << "\n";
		}
	}
}