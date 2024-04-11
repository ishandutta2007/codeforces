#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 400005, mod = 1000000007;
int n, d[MX];
vi adj[MX];

void query (int u) {
	cout << "? " << u << endl;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
}

void go (int u) {
	for (int i = 1; i <= n; i++)
		if (d[i] == 1)
			adj[u].pb(i);
}

void solve () {
	cin >> n;
	
	query(1);
	
	vi a, b;
	for (int i = 1; i <= n; i++) {
		if (d[i] % 2) b.pb(i);
		else a.pb(i);
	}
	
	if (a.size() <= b.size()) {
		go(1);
	} else {
		swap(a, b);
	}
	
	for (int u : a)
		if (u != 1) {
			query(u);
			go(u);
		}
	
	cout << "!" << endl;
	for (int u = 1; u <= n; u++)
		for (int v : adj[u])
			cout << u << " " << v << endl;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}