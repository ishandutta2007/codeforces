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
const int maxn = 1001000;
string s;
int n, m, k, a, b, c;
int tab[maxn];
vector <PII> v[maxn];
ll dp[maxn][2];
int topar[maxn];

void dfs(int x, int par) {
	vector <ll> scores;
	ll base_score = 0;
	for (auto xd : v[x]) {
		int u = xd.e1;
		if (u != par) {
			topar[u] = xd.e2;
			dfs(u, x);
			scores.pb(max(0LL, dp[u][1] - dp[u][0]));
			base_score += dp[u][0];
		}
	}
	
	sort(scores.begin(), scores.end(), greater<ll>());
	//cout << "Node: " << x << endl;
	//for (auto u : scores) cout << u << ' ';
	//cout << endl;
	ll zysk = 0;
	for (int i=1; i<min((int)scores.size()+1, k); ++i) {
		zysk += scores[i - 1];
	}
	//cout << "Sc: " << base_score << ' ' << zysk << endl;
	dp[x][0] = zysk + base_score + ((k <= (int)scores.size())?scores[k - 1] : 0);
	if (x != 1) dp[x][1] = zysk + base_score + topar[x];
}

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		FOR(i, 1, n) v[i].clear(), dp[i][0] = dp[i][1] = 0;
		
		FOR(i, 2, n) {
			cin >> a >> b >> c;
			v[a].pb({b, c});
			v[b].pb({a, c});
		}
		
		dfs(1, 1);
		//FOR(i, 1, n) cout << dp[i][0] << ' ' << dp[i][1] << endl;
		cout << dp[1][0] << "\n";
	}
}