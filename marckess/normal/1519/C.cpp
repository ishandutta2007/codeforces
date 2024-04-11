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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, u[MX], s[MX];
ll res[MX];
vi a[MX];

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		a[i].clear();
		res[i] = 0;
	}
	
	forn (i, n) cin >> u[i];
	forn (i, n) cin >> s[i];
	
	forn (i, n)
		a[u[i]].pb(s[i]);
	
	for (int i = 1; i <= n; i++) {
		sort(all(a[i]), greater<ll>());
		
		for (int j = 1; j < (int)a[i].size(); j++)
			a[i][j] += a[i][j - 1];
		
		for (int j = 1; j <= (int)a[i].size(); j++) {
			int q = (int)a[i].size() / j;
			res[j] += a[i][q * j - 1];
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}