#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
const ll inf = 1e18;

bool Q = 0;
struct Line {
	mutable ll m, b, x;

	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m > ot.m;
	}
};

ll ceil (ll a, ll b) {
	if (a < 0 != b < 0) return a / b;
	return (abs(a) + abs(b) - 1) / abs(b);
}

ll intersection (const Line &p, const Line &q) {
	return ceil(q.b - p.b, p.m - q.m);
}

struct Hull : multiset<Line> {
	bool valid (auto it) {
		if (it == begin()) {
			auto sig = it;
			sig++;
			if (sig != end()) sig->x = intersection(*it, *sig);
			return it->x = -inf;
		}

		auto ant = it, sig = it;
		ant--, sig++;

		if (sig == end()) {
			it->x = intersection(*it, *ant);
			return 1;
		}

		ll x = intersection(*it, *ant);
		ll y = intersection(*it, *sig);

		if (x > y) return 0;
		it->x = x, sig->x = y;
		return 1;
	}

	void add (ll m, ll b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			if (it->b < b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}

		if (!valid(it)) {
			erase(it);
			return;
		}

		auto ant = it;
		while (ant != begin()) {
			if (valid(--ant)) break;
			erase(ant);
			if (it == begin()) { it->x = -inf; break; }
			ant = it;
		}

		auto sig = it;
		sig++;
		while (sig != end() && !valid(sig))
			erase(sig++);
	}

	ll query (ll x) {
		if (empty()) return inf;

		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return x * it->m + it->b;
	}
};

int n, m, k;
ll dis[MX];
vii adj[MX];

void main_() {
	cin >> n >> m >> k;
	
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	forn (i, n)
		dis[i] = inf;
	dis[0] = 0;
	
	forn (kk, k + 1) {
		priority_queue<ii, vii, greater<ii>> pq;
		Hull st;
		
		if (kk) {
			vi q(n);
			iota(all(q), 0);
			sort(all(q), [&] (int i, int j) {
				return dis[i] < dis[j];
			});
			
			forn (i, n) {
				st.add(q[i], q[i] * q[i] + dis[q[i]]);
				pq.push({dis[q[i]] = st.query(-2 * q[i]) + 1ll * q[i] * q[i], q[i]});
			}
		} else {
			pq.push({0, 0});
		}
		
		while (pq.size()) {
			auto [d, u] = pq.top();
			pq.pop();
			
			if (dis[u] != d) continue;
			
			for (auto &[v, w] : adj[u])
				if (dis[u] + w < dis[v])
					pq.push({dis[v] = dis[u] + w, v});
		}
	}
	
	forn (i, n)
		cout << dis[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}