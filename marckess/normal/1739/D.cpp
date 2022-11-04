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

const int MX = 200005;
int n, k, p[MX];
vi adj[MX];

int cn, d;
int dfs (int u, int p) {
	int mx = 0;
	
	for (int v : adj[u])
		if (v != p)
			mx = max(mx, dfs(v, u));
			
	if (mx + 1 == d) {
		cn += p != 1;
		return 0;
	}
	
	return mx + 1;
}

void main_() {
	cin >> n >> k;
	forr (i, 1, n)
		adj[i].clear();
	
	forr (i, 2, n) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	int i = 1, j = n, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		
		cn = 0, d = m;
		dfs(1, 1);
		
		if (cn <= k) j = m;
		else i = m; 
	}
	
	cout << j << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}