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

const int MX = 100005;
int n;
ll c[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> c[i];
		
	ll res = 1e18;
	ll mnx = c[0], cnx = 1, sx = c[0];
	ll mny = c[1], cny = 0, sy = 0;
	
	for (int i = 1; i < n; i++) {
		if (i % 2) {
			mny = min(mny, c[i]);
			sy += c[i];
			cny++;
		} else {
			mnx = min(mnx, c[i]);
			sx += c[i];
			cnx++;
		}
		
		res = min(
			res,
			mnx * (n - cnx) + sx + mny * (n - cny) + sy
		);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}