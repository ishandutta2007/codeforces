// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 105;
int n, a[MX][MX][MX], from[MX], vis[MX];
map<vi, vi> mp[MX];
vvi adj, pos;

void add (int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
}

void dfs (int u, int p, int d) {
	pos[d].pb(u);
	
	for (int v : adj[u])
		if (v != p)
			dfs(v, u, d + 1);
}

bool valid () {
	forr (u, 1, n) {
		sort(all(adj[u]));
		adj[u].erase(unique(all(adj[u])), adj[u].end());
	}
	
	int cn = 0;
	forr (i, 1, n) {
		if (!adj[i].size())
			return 0;
		cn += adj[i].size();
	}
	
	if (cn != 2 * (n - 1))
		return 0;
	
	forr (u, 1, n) {
		pos = vvi(n + 1);
		dfs(u, u, 0);
		
		int cn = 0;
		forr (d, 0, n)
			if (pos[d].size() > 1) {
				sort(all(pos[d]));
				if (!mp[u].count(pos[d]))
					return 0;
				cn++;
			}
		
		if (cn != mp[u].size())
			return 0;
	}
	
	return 1;
}

void main_() {
	cin >> n;
	
	forr (i, 1, n)
	forr (j, i + 1, n) {
		string s;
		cin >> s;
		s = " " + s;
		
		forr (k, 1, n)
			a[i][j][k] = a[j][i][k] = s[k] == '1';
		
		if (n == 2) {
			if (s == " 00") {
				cout << "Yes" << endl << "1 2" << endl;
			} else {
				cout << "No" << endl;
			}
			return;
		}
	}
	
	forr (i, 1, n)
	forr (j, 1, n)
	forr (k, 1, n)
		if (a[i][j][k] && (i == k || j == k)) {
			cout << "No" << endl;
			return;
		}
	
	forr (k, 1, n) {
		mp[k].clear();
		
		forr (i, 1, n) {
			vi v = {i};
			
			forr (j, 1, n)
				if (a[i][j][k])
					v.pb(j);
			
			if (v.size() > 1) {
				sort(all(v));
				mp[k][v].pb(i);
			}
		}
		
		for (const auto &p : mp[k]) {
			if (p.fi != p.se) {
				cout << "No" << endl;
				return;
			}
		}
	}
	
	forr (ot, 2, n) {
		adj = vvi(n + 1);
		memset(from, -1, sizeof(from));
		
		vi mk = {ot};
		
		for (const auto &p : mp[1]) {
			int in = 0;
			
			for (int v : p.fi)
				if (v == ot)
					in = 1;
			
			if (in) {
				mk = p.fi;
				break;
			}
		}
		
		queue<int> q;
		from[1] = 1;
		
		for (int v : mk) {
			q.push(v);
			from[v] = 1;
			add(1, v);
		}
		
		while (q.size()) {
			int u = q.front();
			q.pop();
			
			vi mk;
			for (const auto &q : mp[u]) {
				int in = 0;
				
				for (int v : q.fi)
					if (v == from[u])
						in = 1;
				
				if (in) {
					mk = q.fi;
					break;
				}
			}
			
			if (mk.size())
				for (int v : mk) {
					if (from[v] == -1) {
						q.push(v);
						from[v] = u;
					}
					add(u, v);
				}
		}
		
		if (valid()) {
			cout << "Yes" << endl;
			
			forr (u, 1, n)
				for (int v : adj[u])
					if (u < v)
						cout << u << " " << v << endl;
			
			return;
		}
	}
	
	cout << "No" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}