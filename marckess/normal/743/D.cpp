#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

typedef vector<vector<ll> > vvl;
vvl adj;
ll a[200005], mx[200005];
bitset<200005> bs;

ll dfs (int u) {
	ll u_mx = -2e9, u_sum = a[u];
	bs[u] = 1;

	for (ll v : adj[u]) {
		if (bs[v])
			continue;
		u_sum += dfs(v);
		u_mx = max(u_mx, mx[v]);
	}

	mx[u] = max(u_mx, u_sum);
	//cout << u << " " << mx[u] << endl;
	return u_sum;
}

ll obtRes (ll u) {
	ll u_res = -1e18;
	priority_queue<ll, vector<ll>, greater<ll> > u_mx;
	bs[u] = 1;

	for (ll v : adj[u]) {
		if (bs[v])
			continue;
		u_res = max(u_res, obtRes(v));
		u_mx.push(mx[v]);
		if ( u_mx.size() > 2 )
			u_mx.pop();
	}

	if ( u_mx.size() == 2 ) {
		ll sum = 0;
		sum += u_mx.top(); u_mx.pop();
		sum += u_mx.top(); u_mx.pop();
		u_res = max(u_res, sum);
	}

	//cout << u << " " << u_res << endl;
	return u_res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	adj = vvl(n+2);

	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1);
	bs.reset();
	ll res = obtRes(1);

	if (res == -1e18)
		cout << "Impossible" << endl;
	else
		cout << res << endl;

	return 0;
}