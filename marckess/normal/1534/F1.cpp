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

const int MX = 400005;
int n, m, a[MX], cn, in[MX], comp[MX];
string s[MX];
vi c[MX], adj[MX];

vector<vi> scc(){
	int V = cn;
	vi low(V), label(V);
	int time = 0;
	vector<vi> ans;
	stack<int> S;
	function<void(int)> dfs = [&](int u){
		label[u] = low[u] = ++time;
		S.push(u);
		for(int &v : adj[u]){
			if(!label[v]) dfs(v);
			low[u] = min(low[u], low[v]);
		}
		if(label[u] == low[u]){
			vi comp;
			while(S.top() != u){
				comp.push_back(S.top());
				low[S.top()] = V + 1;
				S.pop();
			}
			comp.push_back(S.top());
			S.pop();
			ans.push_back(comp);
			low[u] = V + 1;
		}
	};
	for(int u = 0; u < V; ++u)
		if(!label[u]) dfs(u);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	forn (i, n) cin >> s[i];
	forn (i, n) c[i] = vi(m, -1);
	forn (i, m) cin >> a[i];
	
	forn (j, m)
		forn (i, n) {
			if ((!i && s[i][j] == '#') || (s[i][j] == '#' && s[i - 1][j] == '.'))
				c[i][j] = cn++;
			else if (s[i][j] == '#')
				c[i][j] = c[i - 1][j];
		}
	
	forn (j, m) {
		int ant = -1;
		
		forn (i, n) {
			if (c[i][j] != -1) {
				if (ant != -1)
					adj[ant].pb(c[i][j]);
				ant = c[i][j];
			}
			
			if (ant != -1) {
				if (j && c[i][j - 1] != -1)
					adj[ant].pb(c[i][j - 1]);
					
				if (j + 1 < m && c[i][j + 1] != -1)
					adj[ant].pb(c[i][j + 1]);
			}
		}
	}
	
	vvi cc = scc();
	for (vi &v : cc)
		for (int u : v)
			comp[u] = v[0];
	
	forn (u, cn)
		for (int v : adj[u])
			if (comp[u] != comp[v])
				in[comp[v]]++;
	
	int res = 0;
	forn (i, cn)
		if (comp[i] == i && !in[i])
			res++;
	cout << res << endl;
	
	return 0;
}