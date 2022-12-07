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

const int MX = 111;
int n, vis[MX];
string adj[MX];
set<int> res[MX];

void dfs (int u) {
	res[u].insert(u);
	vis[u] = 1;
	
	forr (v, 1, n)
		if (adj[v][u] == '1') {
			if (!vis[v])
				dfs(v);
			
			for (int x : res[v])
				res[u].insert(x);
		}
}

void main_() {
	cin >> n;
	forr (i, 1, n) {
		cin >> adj[i];
		adj[i] = "*" + adj[i];
		res[i].clear();
	}
	
	memset(vis, 0, sizeof(vis));
	forr (i, 1, n) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	
	forr (i, 1, n) {
		cout << res[i].size();
		for (int x : res[i])
			cout << " " << x;
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}