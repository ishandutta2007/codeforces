// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 400005;

struct satisfiability_twosat{
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat(int n) : n(n), imp(2 * n) {}

	void add_edge(int u, int v){imp[u].push_back(v);}

	int neg(int u){return (n << 1) - u - 1;}

	void implication(int u, int v){
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}
	
	void equivalence (int u, int v) {
		implication(u, v);
		implication(neg(u), neg(v));
	}
	
	void is_true (int u) {
		implication(neg(u), u);
	}

	vector<bool> solve(){
		int size = 2 * n;
		vector<int> S, B, I(size);

		function<void(int)> dfs = [&](int u){
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for(int v : imp[u])
				if(!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if(I[u] == B.back())
				for(B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
					I[S.back()] = size;
		};

		for(int u = 0; u < 2 * n; ++u)
			if(!I[u]) dfs(u);

		vector<bool> values(n);

		for(int u = 0; u < n; ++u)
			if(I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
}*sat;

int n, q, lvl[MX], x[MX], y[MX], p[MX];
string s[MX];
vi adj[MX], path[MX];
char res[MX];
vii in[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u]) {
			lvl[v] = lvl[u] + 1;
			p[v] = u;
			
			dfs(v);
		}
}

void main_() {
	cin >> n >> q;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[1] = 1;
	dfs(1);
	
	sat = new satisfiability_twosat(q + 5);
	
	forr (i, 1, q) {
		cin >> x[i] >> y[i] >> s[i];
		
		int u = x[i], v = y[i];
		vi izq, der;
		while (u != v) {
			if (lvl[u] > lvl[v]) {
				izq.pb(u);
				u = p[u];
			} else {
				der.pb(v);
				v = p[v];
			}
		}
		
		izq.pb(u);
		reverse(all(der));
		for (int x : der)
			izq.pb(x);
		path[i] = izq;
		
		forn (j, path[i].size()) {
			int u = path[i][j];
			int v = path[i][(int)path[i].size() - j - 1];
			
			in[u].pb({i, s[i][j]});
			in[v].pb({-i, s[i][j]});
		}
	}
	
	forr (i, 1, n) {
		if (!in[i].size()) continue;
		
		char x = in[i][0].se, y = in[i][1].se;
		if (x == y) y = 0;
		
		for (int j = 2; j < in[i].size(); j += 2) {
			if (x != in[i][j].se && x != in[i][j + 1].se) x = 0;
			if (y != in[i][j].se && y != in[i][j + 1].se) y = 0;
		}
		
		if (!x && !y) {
			cout << "NO" << endl;
			return;
		}
		
		if (!x) swap(x, y);
		
		if (!y) {
			for (int j = 0; j < in[i].size(); j += 2) {
				if (in[i][j].se == in[i][j + 1].se) continue;
				int t;
				if (in[i][j].se == x) t = in[i][j].fi;
				else t = in[i][j + 1].fi;
				
				if (t < 0) t = sat->neg(abs(t));
				sat->is_true(t);
			}
		} else {
			int ant = -1;
			for (int j = 0; j < in[i].size(); j += 2) {
				int t;
				if (in[i][j].se == x) t = in[i][j].fi;
				else t = in[i][j + 1].fi;
				
				if (t < 0) t = sat->neg(abs(t));
				if (ant != -1) sat->equivalence(ant, t);
				ant = t;
			}
		}
	}
	
	auto sol = sat->solve();
	if (!sol.size()) {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	forr (i, 1, q) {
		if (!sol[i]) reverse(all(path[i]));
		forn (j, path[i].size())
			res[path[i][j]] = s[i][j];
	}
	
	forr (i, 1, n) cout << max(res[i], 'a');
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