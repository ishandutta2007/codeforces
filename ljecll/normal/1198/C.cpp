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
#define MAXN 300013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC, N, M;
vi edge[MAXN];
map<int, int> eid[MAXN];
bitset<MAXN> vis;
vi ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	while(TC--)
	{
		cin >> N >> M;
		ans.clear();
		FOR(i, 0, 3 * N)
		{
			edge[i].clear();
			eid[i].clear();
			vis[i] = false;
		}
		FOR(i, 0, M)
		{
			int u, v; cin >> u >> v; u--; v--;
			edge[u].PB(v);
			edge[v].PB(u);
			eid[u][v] = i;
			eid[v][u] = i;
		}
		//so you literally just need to keep on choosing edges until you get stuck, and if you get stuck the everything else is the answer
		FOR(i, 0, 3 * N)
		{
			if (vis[i]) continue;
			for (int u : edge[i])
			{
				if (vis[u]) continue;
				vis[i] = true;
				vis[u] = true;
				// cerr << "ADD " << i << ' ' << u << endl;
				ans.PB(eid[i][u]);
				break;
			}
		}
		// cerr << N << ',' << SZ(ans) << '\n';
		if (SZ(ans) >= N)
		{
			cout << "Matching\n";
			FOR(i, 0, N)
			{
				if (i) cout << ' ';
				cout << ans[i] + 1;
			}
			cout << '\n';
			continue;
		}
		ans.clear();
		FOR(i, 0, 3 * N)
		{
			if (!vis[i])
			{
				ans.PB(i);
				// cerr << "WOOHOO " << i << endl;
			}
		}
		// cerr << "SIZE " << SZ(ans) << '\n';
		cout << "IndSet\n";
		FOR(i, 0, N)
		{
			if (i) cout << ' ';
			cout << ans[i] + 1;
		}
		cout << '\n';
	}
}