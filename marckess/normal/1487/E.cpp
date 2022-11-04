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

const int MX = 150005;
int n[4], a[4][MX], dp[4][MX];
vi adj[4][MX];
multiset<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, 4) cin >> n[i];
	forn (i, 4) forn (j, n[i]) cin >> a[i][j];
	
	forn (i, 3) {
		int m;
		cin >> m;
		while (m--) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[i][u].pb(v);	
		}
	}
	
	st.insert(0);
	for (int i = 3; i >= 0; i--) {
		forn (j, n[i]) {
			for (int k : adj[i][j])
				st.erase(st.find(dp[i + 1][k]));
			
			dp[i][j] = min(int(1e9), a[i][j] + *st.begin());
			
			for (int k : adj[i][j])
				st.insert(dp[i + 1][k]);
		}
		
		st.clear();
		st.insert(1e9);
		forn (j, n[i])
			st.insert(dp[i][j]);
	}
	
	if (*st.begin() == 1e9) cout << -1 << endl;
	else cout << *st.begin() << endl;
		
	return 0;
}