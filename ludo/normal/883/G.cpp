#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define all(v) (v).begin(), (v).end()
#define rs resize

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const bool LOG = false;
void Log() {
	if(LOG) cerr << "\n\n";
}
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int maxn = 3e5 + 10, maxm = 6e5 + 20;

int N, M, S, E = 0;
vi g[maxn];
map<int, vi> h[maxn];

bool vis[maxn] = {}, handledMin[maxn] = {}, handledMax[maxn] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			// directed
			g[u].pb(v);
		} else if (u == v) {
			E += 2;
			// do not add it to the graph
		} else {
			h[u][v].pb(E++);
			h[v][u].pb(E++);
		}
	}
	
	vector<bool> usemax(E), usemin(E);
	int nmax = 0, nmin = 0;

	vector<pair<int, vi>> undirs;
	int nvis = 0;
	queue<int> q;

	vis[S] = true; nvis++;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : g[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = true; nvis++;
			q.push(nxt);
		}
		for (pair<int, vi> pr : h[cur]) undirs.pb(pr);
	}

	// determine min answer:
	nmin = nvis;
	for (pair<int, vi> pr : undirs) {
		// if (vis[pr.x]) continue; // dir does not matter
		for (int v : pr.y) {
			if (handledMin[v/2]) continue;
			handledMin[v/2] = true;
			usemin[v ^ 1] = true; // use the other
		}
	}

	while (!undirs.empty()) {
		for (pair<int, vi> pr : undirs) {
			// if (vis[pr.x]) continue; // dir does not matter
			for (int v : pr.y) {
				if (handledMax[v/2]) continue;
				handledMax[v/2] = true;
				usemax[v] = true; // use this
			}
			if (!vis[pr.x]) {
				vis[pr.x] = true; nvis++;
				q.push(pr.x);
			}
		}
		undirs.clear();
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int nxt : g[cur]) {
				if (vis[nxt]) continue;
				vis[nxt] = true; nvis++;
				q.push(nxt);
			}
			for (pair<int, vi> pr : h[cur]) undirs.pb(pr);
		}
	}
	
	nmax = nvis;

	cout << nmax << endl;
	for (int i = 0; i < E; i += 2) cout << ((char) (usemax[i] ? '+' : '-'));
	cout << endl << nmin << endl;
	for (int i = 0; i < E; i += 2) cout << ((char) (usemin[i] ? '+' : '-'));
	cout << endl;
	return 0;
}