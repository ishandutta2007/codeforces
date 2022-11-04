#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, k, res;
ll dis[MX];
ii a[MX];
vii adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	forn (i, k)
		cin >> a[i].se >> a[i].fi;
	sort(a, a + k);
	
	forn (i, MX) dis[i] = 1e18;
	dis[1] = 0;
	
	priority_queue<ii, vii, greater<ii>> pq;
	pq.emplace(0, 1);
	
	for (int j = 0; j < k || pq.size();)
		if (!pq.size() || (j < k && a[j].fi < pq.top().fi)) {
			int v = a[j].se;
			ll w = a[j].fi;
			
			if (dis[v] > w) {
				pq.emplace(dis[v] = w, v);
				res++;
			}
			
			j++;
		} else {
			int u = pq.top().se;
			ll d = pq.top().fi;
			pq.pop();
			
			if (dis[u] < d) continue;
			
			for (ii &v : adj[u]) {
				ll w = d + v.se;
				
				if (dis[v.fi] > w)
					pq.emplace(dis[v.fi] = w, v.fi);
			}
		}
	
	cout << k - res << endl;
	
	return 0;
}