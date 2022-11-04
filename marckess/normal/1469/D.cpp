#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
int n;
vii res;

int techo (int a, int b) {
	return (a + b - 1) / b;
}

void solve () {
	cin >> n;
	res.clear();
	
	for (int i = n; i > 2;) {
		for (int j = i - 1;; j--) {
			if (techo(i, j - 1) > j - 1) {
				res.pb({i, j});
				res.pb({i, j});
				i = j;
				break;
			}
			
			res.pb({j, i});
		}
	}
	
	cout << res.size() << endl;
	for (ii &p : res)	
		cout << p.fi << " " << p.se << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}