#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const ld PI = acos(-1.0);

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

struct pairhash {
public:
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2> &p) const {
		size_t lhs = hash<T1>()(p.x);
		size_t rhs = hash<T2>()(p.y);
		return lhs ^ (rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
	}
};

vi bfs(int n, const vvi &adj, int s) {
	vi dist(n, INT_MAX);
	queue<int> q;
	q.push(s); dist[s] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (ll nx : adj[cur]) {
			int nxt = (int) nx;
			if (dist[nxt] != INT_MAX) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	return dist;
}

bool test(int n, vi &src, vi &snk, vi &S, int mid) {
	map<ll,ll> pareto;
	pareto[ src[S[0]] ] = snk[S[0]];
	int k = sz(S);
	for (int i=1; i<k; i++) {
		ll a = src[S[i]], b = snk[S[i]];
		// find c,d with c >= mid-1-b and d >= mid-1-a

		auto it = pareto.lower_bound(mid-1-b);
		if (it != pareto.end() && it->y >= mid-1-a) {
			return true;
		}

		// todo: do careful insertion
		auto ins = pareto.lower_bound(a);
		if (ins != pareto.end() && b <= ins->y)
			continue; // *ins is better

		while (--ins != pareto.begin() && ins->x <= a && ins->y <= b)
			pareto.erase(ins);

		pareto[a] = b;
	}

	return false;
}

void run() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vi S(k);
	REP(i, k) {
		scanf("%lld", &S[i]);
		S[i]--;
	}
	sort(all(S));

	vvi adj(n);

	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		// connect a, b
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vi src = bfs(n, adj, 0);
	vi snk = bfs(n, adj, n-1);

	ll cur_min = INT_MAX;
	REP(i, n) cur_min = min(cur_min, src[i]+snk[i]);

	// can we do better?

	ll lo = 0, hi = cur_min+1;
	assert(test(n, src, snk, S, lo));
	// assert(!test(hi));
	// cerr << "curmin: " << cur_min << endl;
	while (hi - lo > 1) {
		ll mid = (lo + hi) / 2;

		// can we find ((a,b), (c,d)) s.t. min(a+d, b+c) + 1 >= mid ?
		bool poss = test(n, src, snk, S, mid);
		// cerr << "TEST " << mid << ": " << poss << endl;
		if (poss) lo = mid;
		else hi = mid;
	}

	printf("%d\n", lo);
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}