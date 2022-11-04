#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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
const int MN = 4005, ME = 10 * MN;

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

int n1, n2, m, pos[MN], ud[MN], vd[MN], fsz, sd, td, degu[MN], degv[MN];
int s, ss, t, tt;

void solve (int k) {
	int i = 0, j = m;
	while (i < j) {
		int m = (i + j) / 2;
		cap[fsz] = m;
		reset(ss, tt);
		
		if (dinitz() == k * (n1 + n2)) j = m;
		else i = m + 1;
	}
	
	cap[fsz] = j;
	reset(ss, tt);
	dinitz();
	
	int t = 0;
	cout << j;
	forn (i, m)
		if (flow[pos[i]])
			cout << " " << i + 1;
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	cin >> n1 >> n2 >> m;
	s = n1 + n2, t = s + 1, ss = t + 1, tt = ss + 1;
	
	init(ss, tt, tt);
	
	forn (i, n1) {
		add(s, i, INF);
		
		ud[i] = ned;
		add(ss, i, 0);
	}
	sd = ned;
	add(s, tt, 0);
	
	forn (i, n2) {
		add(n1 + i, t, INF);
		
		vd[i] = ned;
		add(n1 + i, tt, 0);
	}
	td = ned;
	add(ss, t, 0);
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		degu[u]++;
		degv[v]++;
		
		pos[i] = ned;
		add(u, n1 + v, 1);
	}
	fsz = ned;
	add(t, s, m);
	
	int mn = m;
	forn (i, n1) mn = min(mn, degu[i]);
	forn (i, n2) mn = min(mn, degv[i]);
	
	forn (k, mn + 1) {
		solve(k);
		
		forn (i, n1)
			cap[ud[i]]++;
		cap[sd] += n1;
		
		forn (i, n2)
			cap[vd[i]]++;
		cap[td] += n2;
	}
	
	return 0;
}