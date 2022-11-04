#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, a[MX];
vi par, imp;
vii res;

void solve () {
	cin >> n;

	par.clear();
	imp.clear();
	res.clear();

	forn (i, 2 * n) {
		cin >> a[i];
		if (a[i] % 2 == 0) par.pb(i + 1);
		else imp.pb(i + 1);
	}

	for (int i = 0; i + 1 < par.size(); i += 2)
		res.emplace_back(par[i], par[i + 1]);

	for (int i = 0; i + 1 < imp.size(); i += 2)
		res.emplace_back(imp[i], imp[i + 1]);

	while (res.size() >= n) res.pop_back();

	for (ii r : res)
		cout << r.fi << " " << r.se << endl;
}	

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}