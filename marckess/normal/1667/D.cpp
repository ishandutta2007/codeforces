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

const int MX = 200005;
int n, mem[MX][2];
vi adj[MX];

int dp (int u, int p, int f) {
	int &res = mem[u][f == -1 ? 0 : f];
	
	if (res != -1)
		return res;
	
	int a = 0, b = 0, c = 0;
	if (f == 0) a++;
	if (f == 1) b++;
	
	for (int v : adj[u])
		if (v != p) {
			int g = dp(v, u, 0);
			int h = dp(v, u, 1);
			
			if (!g && !h) return res = 0;
			if (g && !h) a++;
			if (!g && h) b++;
			if (g && h) c++;
		}
	
	int x = (adj[u].size() + 1) / 2;
	int y = adj[u].size() / 2;
	
	if (a + c < x) return res = 0;
	if (b + c < y) return res = 0;
	return res = 1;
}

void rec (int u, int p, int f) {
	vi a, b, c;
	if (f == 0) a.pb(p);
	if (f == 1) b.pb(p);
	
	for (int v : adj[u])
		if (v != p) {
			int g = dp(v, u, 0);
			int h = dp(v, u, 1);
			
			if (g && !h) a.pb(v);
			if (!g && h) b.pb(v);
			if (g && h) c.pb(v);
		}
	
	int g = 1 - (int)adj[u].size() % 2;
	while (a.size() + b.size() + c.size()) {
		int v;
		
		if (g) {
			if (b.size()) {
				v = b.back();
				b.pop_back();
			} else {
				v = c.back();
				c.pop_back();
			}
		} else {
			if (a.size()) {
				v = a.back();
				a.pop_back();
			} else {
				v = c.back();
				c.pop_back();
			}
		}
		
		if (v == p) cout << u << " " << v << endl;
		else rec(v, u, g);
		g = 1 - g;
	}
}

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		adj[i].clear();
		mem[i][0] = mem[i][1] = -1;
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	if (dp(1, -1, -1)) {
		cout << "YES" << endl;
		rec(1, -1, -1);
	} else {
		cout << "NO" << endl;
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