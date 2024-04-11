#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, int > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 100100;
map <ll, int> gcd;

ll g[maxn];
vector <int> v[maxn];
ll score = 0;
int pre[maxn];
ll result;
int n;

map<ll, int> stor[maxn];

void dfs(int x, int par)
{
	for (auto u : stor[x]) result += (ll)u.e1 * u.e2 % mod;
	
	for (auto u : v[x])
	{
		if (u == par) continue;
		for (auto value : stor[x])
		{
			ll gd = __gcd(value.e1, g[u]);
			stor[u][gd] += value.e2;
		}
		
		stor[u][g[u]]++;
		pre[u] = pre[x] + 1;
		dfs(u, x);
	}
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> g[i];
	stor[1][g[1]]++;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1, 0);
	cout << result % mod << endl;
	
	//FOR(i, 1, n)
		//for (auto u : stor[i]) cout << "i: " << i << " : " << u.e1 << ' ' << u.e2 << endl;
}