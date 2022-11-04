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

const int MX = 100005;
int n, m, k, ex[MX], mx[MX], in[MX], mt[MX], res[MX], vis[MX], cn = 1;
string p[MX], s[MX];
map<string, int> mp;
vi adj[MX];

void dfs (int u) {
	vis[u] = 1;
	
	for (int v : adj[u]) {
		if (!vis[v]) dfs(v);
		else if (vis[v] == 1) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	
	res[cn++] = u;
	vis[u] = 2;
}

void main_ () {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		ex[i] = mx[i] = 1;
		mp[p[i]] = i;
	}
	
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> mt[i];
		in[mt[i]]++;
		
		int f = 1;
		
		forn (mk, (1 << k)) {
			string aux;
			
			forn (j, k) {
				if (mk & (1 << j)) aux.pb(s[i][j]);
				else aux.pb('_');
			}
			
			if (mp.count(aux)) {
				int l = mp[aux];
				if (l == mt[i]) f = 0;
				else adj[l].pb(mt[i]);
			}
		}
		
		if (f) {
			cout << "NO" << endl;
			return;
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
	
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();	
			
	return 0;
}