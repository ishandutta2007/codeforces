#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1e6 + 10;

vector <int> v[30];
string s1, s2;

void add_edge(int x, int y)
{
	v[x].pb(y);
	v[y].pb(x);
}
vector <int> helo;
int odw[maxn];

void dfs(int x)
{
	odw[x] = 1;
	helo.pb(x);
	for (auto u : v[x])
		if (!odw[u])
		{
			dfs(u);
		}
}

vector <int> help[27];

int main()
{
	boost;
	int n;
	cin >> n;
	cin >> s1 >> s2;
	for (int i=0; i<n; ++i)
	{
		if (s1[i] != s2[i]) add_edge(s1[i] - 'a', s2[i] - 'a');
	}
	
	int spo = 0;
	int res = 0;
	FOR(i, 0, 25)
		if (!odw[i])
		{
			++spo;
			helo.clear();
			dfs(i);
			res += (int)helo.size() - 1;
			help[spo] = helo;
		}
	
	cout << res << endl;
	FOR(i, 1, spo)
	{
		if ((int)help[i].size() == 1) continue;
		for (int j=1; j<(int)help[i].size(); ++j)
			cout << (char)(help[i][0] + 'a') << ' ' << (char)(help[i][j] + 'a') << "\n";
	}
}