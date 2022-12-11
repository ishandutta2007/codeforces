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
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, K;
vi edge[MAXN];
bitset<MAXN> bad;
int ans;

void dfs(int u, int p, int c)
{
	if (c > K) return;
	for (int v : edge[u])
	{
		if (v == p) continue;
		dfs(v, u, (bad[v] ? c + 1 : 0));
	}
	if (SZ(edge[u]) == 1 && u != 0) ans++;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	FOR(i, 0, N)
	{
		bool b; cin >> b; bad[i] = b;
	}
	FOR(i, 0, N - 1)
	{
		int u, v; cin >> u >> v; u--; v--;
		edge[u].PB(v);
		edge[v].PB(u);
	}
	dfs(0, -1, bad[0]);
	cout << ans << '\n';
	return 0;
}