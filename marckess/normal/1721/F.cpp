#include <bits/stdc++.h>

// #define endl '\n'
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define SET(p,n) memset(p, n, sizeof (p))

const int MX = 200005;
const int INF = INT_MAX;
const int MN = 2 * MX, ME = MN + MX;

int src, snk, nno, ned;
int q[MN], fin[MN], pro[MN], dist[MN];
int flow[2*ME], cap[2*ME];
int sig[2*ME], to[2*ME];

inline void init (int _src, int _snk, int _n) {
	src = _src, snk = _snk, nno = _n, ned = 0;
	SET(fin, -1);
}

inline void add (int u, int v, int c) {
	to[ned] = v, cap[ned] = c, flow[ned] = 0, sig[ned] = fin[u], fin[u] = ned++;
	to[ned] = u, cap[ned] = 0, flow[ned] = 0, sig[ned] = fin[v], fin[v] = ned++;
}

inline void reset (int _src, int _snk) {
    src = _src, snk = _snk;
    for (int i = 0; i < ned; i++)
        flow[i] = 0;
}

bool bfs () {
	int st, en, u, v;
	SET(dist, -1);

	dist[src] = st = en = 0;
	q[en++] = src;

	while (st < en) {
		u = q[st++];

		for (int e = fin[u]; e >= 0; e = sig[e]) {
			v = to[e];

			if (flow[e] < cap[e] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}

	return dist[snk] != -1;
}

int dfs (int u, int mn) {
	if (u == snk)
		return mn;

	int au, v;
	for (int &e = pro[u]; e >= 0; e = sig[e]) {
		v = to[e];

		if (flow[e] < cap[e] && dist[v] == dist[u]+1)
			if (au = dfs(v, min(mn, cap[e] - flow[e]))) {
                flow[e] += au;
                flow[e^1] -= au;
                return au;
            }
	}

	return 0;
}

ll dinitz () {
	ll f = 0;
	int au;

	while (bfs()) {
		for (int i = 0; i <= nno; i++)
			pro[i] = fin[i];

		while (au = dfs(src, INF))
			f += au;
	}

	return f;
}

int n1, n2, m, vis[MN];
map<ii, int> mp;

void dfs (int u) {
	vis[u] = 1;
	
	for (int e = fin[u]; e >= 0; e = sig[e])
		if (flow[e] < cap[e] && !vis[to[e]])
			dfs(to[e]);
}

void main_() {
	int q;
	cin >> n1 >> n2 >> m >> q;
	
	int s = n1 + n2, t = s + 1;
	init(s, t, t);
	
	forn (i, n1) add(s, i, 1);
	forn (i, n2) add(n1 + i, t, 1);
	
	forn (i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		mp[{x, y}] = i + 1;
		add(x, n1 + y, 1);
	}
	
	dinitz();
	
	dfs(s);
	
	set<vi> st;
	ll tot = 0;
	
	forn (u, n1)
		for (int e = fin[u]; e >= 0; e = sig[e])
			if (flow[e] == cap[e] && to[e] != s && to[e] != t) {
				int ind = mp[{u, to[e] - n1}];
				st.insert({u, to[e] - n1, ind});
				tot += ind;
			}
	
	while (q--) {
		int op;
		cin >> op;
		
		if (op == 1) {
			int u = (*st.begin())[0];
			int v = (*st.begin())[1];
			int ind = (*st.begin())[2];
			st.erase(st.begin());
			tot -= ind;
			
			cout << 1 << endl;
			if (!vis[u]) cout << u + 1 << endl;
			else cout << -(v + 1) << endl;
			cout << tot << endl;
		} else {
			cout << st.size() << endl;
			for (const vi &v : st) cout << v[2] << " ";
			cout << endl;
		}
	}
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}