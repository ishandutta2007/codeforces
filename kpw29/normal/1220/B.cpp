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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1010;
int n;
ll tab[maxn][maxn];

ll arr[maxn];

bool ok()
{
	FOR(i, 1, n)
		FOR(j, i+1, n)
			if (arr[i] * arr[j] != tab[i][j]) return 0;
		
	return 1;
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n)
		FOR(j, 1, n) cin >> tab[i][j];
	
	vector <int> divs;
	
	FOR(i, 1, sqrt(tab[1][2]) + 1)
	{
		if (tab[1][2] % i == 0) divs.pb(i), divs.pb(tab[1][2]/i);
	}
	
	for (auto u : divs)
	{
		if (!u) continue;
		arr[1] = u;
		FOR(i, 2, n) arr[i] = tab[1][i] / u;
	
		if (ok())
		{
			FOR(i, 1, n) cout << arr[i] << ' ';
			exit(0);
		}
	}
}