#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0);}
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
const int maxn = 4100;

int dp[maxn], t, n, m;
int old[maxn];
int stor[maxn];

PII tab[maxn];
int curr[13][maxn];
int nowe[13][maxn];

int solve()
{
	cin >> n >> m;
	FOR(i, 1, n)
	{
		FOR(j, 1, m) 
		{
			cin >> curr[i][j];
			tab[j] = mp(curr[i][j], j);
		}
		sort(tab+1, tab+m+1);
		FOR(j, 1, m) nowe[i][tab[j].e2] = m - j + 1;
	}
	fill(dp, dp+maxn, 0);
	FOR(j, 1, m)
	{
		bool skip = true;
		FOR(i, 1, n)
			if (nowe[i][j] <= 12) skip = false;

		if (skip) continue;
		//normally add a column
		vector <int> deq;
		FOR(i, 1, n) deq.push_back(curr[i][j]);
		FOR(h, 0, maxn-1) old[h] = dp[h], stor[h] = dp[h];
		FOR(step, 1, n)
		{
			FOR(mask, 0, (1 << n))
				FOR(el, 0, n-1)
					if ((mask & (1 << el)) == 0) dp[mask | (1 << el)] = max(dp[mask | (1 << el)], dp[mask] + deq[el]);
			
			FOR(h, 0, maxn-1) stor[h] = max(stor[h], dp[h]), dp[h] = old[h];
			int val = deq[0];
			deq.erase(deq.begin());
			deq.pb(val);
		}
		
		FOR(h, 0, maxn-1) dp[h] = stor[h];
	}
	
	return dp[(1 << n) - 1];
}
int main()
{
	boost;
	cin >> t;
	while (t--) {
		cout << solve() << "\n";
	}
	
}