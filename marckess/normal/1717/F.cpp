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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define SET(p,n) memset(p, n, sizeof (p))

const int INF = INT_MAX;
const int MN = 10005, ME = 6 * MN, MX = MN;

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

int n, m, p[MX], a[MX], b[MX], u[MX], v[MX], res[MX];

void main_() {
	cin >> n >> m;
	forn (i, n) cin >> p[i];
	forn (i, n) cin >> a[i];
	
	int s = n, t = s + 1;
	init(s, t, t);
	
	map<int, int> mp, izq, der;
	
	forn (i, m) {
		cin >> u[i] >> v[i];
		u[i]--, v[i]--;
		
		b[u[i]]--;
		b[v[i]]++;
		
		if (p[u[i]] && p[v[i]]) {
			mp[i] = ned;
			add(v[i], u[i], 1);
		}
	}
	
	ll nec = 0;
	
	forn (i, n)
		if (p[i]) {
			if ((a[i] - b[i]) % 2) {
				cout << "NO" << endl;
				return;
			}
			
			if (a[i] < b[i]) {
				add(s, i, (b[i] - a[i]) / 2);
			} else if (a[i] > b[i]) {
				add(i, t, (a[i] - b[i]) / 2);
			}
			
			nec += abs(a[i] - b[i]) / 2;
		}
		
	nec -= 2 * dinitz();
	
	forn (i, m) {
		if (p[u[i]] && !p[v[i]]) {
			izq[i] = ned;
			add(s, u[i], 1);
		}
	}
	
	nec -= dinitz();
	
	for (auto [i, e] : izq) {
		if (flow[e])
			res[i] = 1;
		flow[e] = cap[e] = 0;
	}
	
	forn (i, m) {
		if (!p[u[i]] && p[v[i]]) {
			der[i] = ned;
			add(v[i], t, 1);
		}
	}
	
	nec -= dinitz();
	
	for (auto [i, e] : der) {
		if (flow[e])
			res[i] = 1;
		flow[e] = cap[e] = 0;
	}
	
	
	for (auto [i, e] : mp)
		if (flow[e])
			res[i] = 1;
	
	if (nec) {
		cout << "NO" << endl; 
	} else {
		cout << "YES" << endl;
		forn (i, m) {
			if (res[i]) cout << v[i] + 1 << " " << u[i] + 1 << endl;
			else cout << u[i] + 1 << " " << v[i] + 1 << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}