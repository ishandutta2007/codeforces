#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, sx, sy, fx, fy;
ll dis[MX];
ii a[MX];
map<int, vi> mx, my;
set<int> ex, ey;
set<ii> pq;

void insert (int d, int u) {
	pq.emplace(d, u); 
}

void find (ii a, int dis) {
	auto it = ex.upper_bound(a.fi);
	
	if (it != ex.end()) insert(dis + abs(*it - a.fi), *it);
	if (it != ex.begin()) {
		it--;
		insert(dis + abs(*it - a.fi), *it);
	}
	
	it = ey.upper_bound(a.se);
	
	if (it != ey.end()) insert(dis + abs(*it - a.se), -*it);
	if (it != ey.begin()) {
		it--;
		insert(dis + abs(*it - a.se), -*it);
	}
}

void solve () {
	memset(dis, -1, sizeof(dis));
	
	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;
	
	forn (i, m) {
		cin >> a[i].fi >> a[i].se;
		
		mx[a[i].fi].pb(i);
		my[a[i].se].pb(i);
		
		ex.insert(a[i].fi);
		ey.insert(a[i].se);
	}
	
	find(ii(sx, sy), 0);
	
	while (pq.size()) {
		int u = pq.begin()->se;
		int w = pq.begin()->fi;
		pq.erase(pq.begin());
		
		if (u > 0) {
			if (!ex.count(u)) continue;
			ex.erase(u);
			
			for (const auto &it : mx[u]) {
				if (dis[it] == -1) dis[it] = w;
				find(a[it], w);
			}
		} else {
			u = -u;
			
			if (!ey.count(u)) continue;
			ey.erase(u);
			
			for (const auto &it : my[u]) {
				if (dis[it] == -1) dis[it] = w;
				find(a[it], w);
			}
		}
	}
	
	ll res = abs(sx - fx) + abs(sy - fy);
	forn (i, m)
		res = min(res, dis[i] + abs(a[i].fi - fx) + abs(a[i].se - fy));
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}