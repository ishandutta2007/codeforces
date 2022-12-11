#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define MAXN 500013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;
int N, K;
vpi edge[MAXN];
ll dp[MAXN][2];

void dfs(int u, int p)
{
	for (pii e : edge[u])
	{
		ll d = e.fi; int v = e.se;
		if (v == p) continue;
		dfs(v, u);
	}
	//you take exactly K
	//you take <= K - 1
	vl gains;
	for (pii e : edge[u])
	{
		ll d = e.fi; int v = e.se;
		if (v == p) continue;
		dp[u][0] += dp[v][0];
		dp[u][1] += dp[v][0];
		gains.PB(d + dp[v][1] - dp[v][0]);
	}
	sort(ALL(gains)); reverse(ALL(gains));
	FOR(i, 0, K)
	{
		if (i >= SZ(gains) || gains[i] < 0) break;
		if (i != K - 1)
		{
			dp[u][1] += gains[i];
		}
		dp[u][0] += gains[i];
	}
	//1 means there must be smth free. 0 means there might not be.
	ckmax(dp[u][0], dp[u][1]);
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> TC;
	while(TC--)
	{
		cin >> N >> K;
		FOR(i, 0, N)
		{
			edge[i].clear();
			dp[i][0] = 0; dp[i][1] = 0;
		}
		FOR(i, 0, N - 1)
		{
			int u, v, d; cin >> u >> v >> d; u--; v--;
			edge[u].PB({d, v});
			edge[v].PB({d, u});
		}
		dfs(0, N);
		cout << dp[0][0] << '\n';
		//you take a set of edges such that for each vertex, you have taken noo more than K adjacent edfges
	}
	return 0;
}