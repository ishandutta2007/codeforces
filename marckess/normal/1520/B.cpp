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

int n;
vi ord;

void solve () {
	cin >> n;
	
	int res = 0;
	for (int x : ord)
		if (x <= n)
			res++;
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 1; i < 10; i++)
		ord.pb(i);
	
	forn (i, 1e9) {
		ll x = 10 * ord[i] + ord[i] % 10;
		if (x > 1e9)
			break;
		ord.pb(x);	
	}
	
	int t;
	cin >> t;
	while (t--)
		solve();
		
	return 0;
}