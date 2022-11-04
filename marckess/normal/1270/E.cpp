#include <bits/stdc++.h>
 
//#define endl '\n'
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

const int MX = 1005;
int n, x[MX], y[MX];
ll adj[MX][MX], g;
vi res;

#define sq(n) (ll(n)*(n))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			adj[i][j] = sq(x[i] - x[j]) + sq(y[i] - y[j]);
			g = __gcd(g, adj[i][j]);
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			adj[i][j] /= g;

	res = {1};
	for (int i = 2; i <= n; i++)
		if (adj[1][i] % 2 == 0)
			res.pb(i);

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}