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
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
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
const int mod = 1e9+7;
const int maxn = 1e6 + 100;
vector <int> v[maxn];
ll tab[maxn];
int d[maxn], ILE[maxn];
void dfs(int x)
{
	for (auto u : v[x])
	{
		d[u] = d[x] + 1;
		ILE[d[u]]++;
		dfs(u);
	}
}
int n;
int main()
{
	boost;
	cin >> n;
	FOR(i, 2, n) {
		int pi;
		cin >> pi;
		v[pi].pb(i);
	}
	
	dfs(1);
	int res = 0;
	FOR(i, 0, n)
	{
		if (ILE[i] % 2 == 1) ++res;
	}
	cout << res + 1;
}