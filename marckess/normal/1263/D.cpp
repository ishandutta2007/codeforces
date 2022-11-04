#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, vis[MX];
string s[MX];
vi adj[MX + 256];

void dfs (int u) {
	vis[u] = 1;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sort(all(s[i]));
		s[i].erase(unique(all(s[i])), s[i].end());
		
		for (int c : s[i]) {
			adj[i].pb(c+n);
			adj[c+n].pb(i);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i]) {
			res++;
			dfs(i);
		}
	cout << res << endl;

	return 0;
}