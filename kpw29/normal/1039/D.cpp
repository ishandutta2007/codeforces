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
int n;

const int maxn = 100100;
vector <int> v[maxn], ch[maxn];
int stos[maxn], par[maxn], ST;
int MAX[maxn], SECMAX[maxn], dp[maxn];

void prep(int x, int p) {
	par[x] = p;
	for (auto u : v[x])
		if (u != p) {
			ch[x].pb(u);
			prep(u, x);
		}
	stos[++ST] = x;
}

int ask(int key) {
	FOR(i, 1, ST)
	{
		int x = stos[i];
		MAX[x] = SECMAX[x] = dp[x] = 0;
		for (auto u : ch[x])
		{
			dp[x] += dp[u];
			if (MAX[u] > MAX[x]) {SECMAX[x] = MAX[x]; MAX[x] = MAX[u]; }
			else if (MAX[u] > SECMAX[x]) SECMAX[x] = MAX[u]; 
		}
		++MAX[x];
		if (SECMAX[x] + MAX[x] >= key)
		{
			++dp[x];
			SECMAX[x] = MAX[x] = 0;
		}
		
		//cout << x << ' ' << dp[x] << endl;
	}
	
	return dp[1];
}

const int MAGIC = 500;
int ans[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		//a = i - 1; b = i;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	prep(1, 0);
	FOR(i, 1, min(n, MAGIC)) ans[i] = ask(i);
	int x = min(n, MAGIC) + 1, y = n;
	while (x <= n)
	{
		int xx = x, yy = y;
		int val = ask(xx);
		while (xx < yy)
		{
			int mid = ((xx + yy) >> 1) + 1;
			//cout << xx << ' ' << mid << ' ' << yy << endl;
			if (ask(mid) < val) yy = --mid;
			else xx = mid;
		}
		//cout << xx << ' ' << yy << endl;
		ans[xx] = val;
		x = xx + 1;
	}
	
	for (int i=n; i>0; --i)
		if (!ans[i]) ans[i] = ans[i + 1];
	FOR(i, 1, n) cout << ans[i] << "\n";
}