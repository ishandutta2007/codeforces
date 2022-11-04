#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], f;
vi pos[MX];
stack<int> st;

void no () {
	cout << -1 << endl;
	exit(0);
}

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	f = n - 1;
	
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) st.push(i);
		if (a[i] == 2) {
			if (!st.size()) no();
			int u = st.top();
			st.pop();
			
			pos[i].pb(f);
			pos[u].pb(f); f--;
		}
	}
	
	while (st.size()) st.pop();
	
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1 && !pos[i].size()) st.push(i);
		if (a[i] == 2) st.push(i);
		if (a[i] == 3) {
			if (!st.size()) no();
			int u = st.top();
			st.pop();
			
			if (a[u] == 2) {
				pos[i].pb(f);
				pos[u].pb(f); f--;
			} else if (a[u] == 1) {
				f--;
				pos[i].pb(f);
				pos[u].pb(f);
				pos[u].pb(f + 1);
				f--;
			} else {
				pos[i].pb(f);
				pos[u].pb(f); f--;
			}
			
			st.push(i);
		}
	}
	
	forn (i, n) if (a[i] == 1 && !pos[i].size()) {
		pos[i].pb(f); f--;
	}
	
	vii res;
	forn (i, n) for (int j : pos[i]) res.emplace_back(i + 1, j + 1);
	
	cout << res.size() << endl;
	for (ii &r : res) cout << r.se << " " << r.fi << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}