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

const int MX = 4005;
int n, p[MX], res;
vi adj[MX];
string s;

ii dfs (int u) {
	ii ret(s[u] == 'W', s[u] == 'B');
	
	for (int v : adj[u]) {
		ii d = dfs(v);
		ret.fi += d.fi;
		ret.se += d.se;
	}
	
	if (ret.fi == ret.se)
		res++;
	return ret;
}

void main_() {
	cin >> n;
	forr (i, 1, n) {
		adj[i].clear();
	}
	
	forr (i, 2, n) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	cin >> s;
	s = " " + s;
	
	res = 0;
	dfs(1);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}