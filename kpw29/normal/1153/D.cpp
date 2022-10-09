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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 300100;
int type[maxn], par[maxn], n, leaves = 0;
vector <int> ch[maxn];

ll dp[maxn];

void dfs(int x)
{
	bool leaf = true;
	for (auto u : ch[x]) leaf = false, dfs(u);
	if (leaf)
	{
		++leaves;
		dp[x] = 1;
		return;
	}
	
	if (type[x] == 0) //min
	{
		ll score =0;
		for (auto u : ch[x]) score += dp[u];
		dp[x] = score;
	}
	else
	{
		ll score = INF;
		for (auto u : ch[x]) score = min(score, dp[u]);
		dp[x] = score;
	}
}

bool check(int x) //czy wynik moze byc >= x
{
	leaves = 0;
	FOR(i, 1, n) dp[i] = 0;
	dfs(1);
	ll have = leaves - x + 1;
	return have >= dp[1];
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> type[i];
	FOR(i, 2, n) {
		cin >> par[i];
		ch[par[i]].pb(i);
	}

	int x = 1, y = n;
	while (x < y)
	{
		int sr = (x + y) / 2 + 1;
		if (!check(sr)) y = --sr;
		else x = sr;
	}
	
	cout << x;
}