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
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 100100;
bool in[maxn];
int h[maxn], n, l, r;

bool dp[10010];
bool dps[10010];

int FILL[10010];
int bestfill[10010];
int main()
{
	boost;
	cin >> n >> l >> r;
	dp[0] = 1;
	FOR(i, 1, n) cin >> h[i];
	FOR(i, 1, n) cin >> in[i];
	vector <int> supreme, taken, ok, wa;
	FOR(i, 1, n)
		if (in[i]) ok.pb(h[i]);
		else wa.pb(h[i]);
	
	if (ok.empty()) OUT(0);
	
	int start = l;
	sort(ok.begin(), ok.end());
	for (auto u : ok)
	{
		start += u;
		if (start <= r) taken.pb(u);
		else supreme.pb(u);
	}

	dps[0] = 1;
	
	for (auto u : wa) {
		for (int i = 10000 - u; i >= 0; --i)
			if (dp[i]) dp[i + u] = 1;
	}
	
	int sumsupreme = 0;
	for (auto u: supreme) {
		for (int i = 10000 - u; i >= 0; --i)
			if (dps[i]) dps[i + u] = 1;
		sumsupreme += u;
	}
	
	reverse(taken.begin(), taken.end());
	FILL[0] = 0;
	int ile = 0, sum = 0;
	for (auto u : taken)
	{
		sum += u; ++ile;
		FILL[sum] = ile;
	}
	for (int i=10000; i>0; --i)
		if (!FILL[i]) FILL[i] = FILL[i + 1];
		
	reverse(taken.begin(), taken.end());
	int result = 0, sumtaken = sum;
	FOR(i, sumtaken + 1, 10000) FILL[i] = inf;
	sum = 0; ile = 0;
	
	bestfill[0] = 0;
	for (auto u : taken)
	{
		sum += u; ++ile;
		bestfill[sum] = ile;
	}


	FOR(i, 1, 10000)
		if (!bestfill[i]) bestfill[i] = bestfill[i - 1];
	FOR(i, 0, 10000)
	{
		if (!dp[i]) continue;
		FOR(j, 0, 10000)
		{
			if (!dps[j]) continue;
			int hardcore = i + j; bool Left = (j == sumsupreme)?0 : 1;
			if (supreme.empty()) Left = 0;
			if (hardcore < l)
			{
				int reszta = l - hardcore;
				result = max(result, Left + (int)taken.size() - FILL[reszta]);
			}
			else if (hardcore <= r)
			{
				int space = r - hardcore;
				if (space < sumtaken) Left = 1;
				result = max(result, Left + bestfill[space]);
			}
			
			/*if (result == 1) {
				cout << i << ' ' << j << endl;
				exit(0);
			}*/
			
		}
	}
	
	cout << result;
}