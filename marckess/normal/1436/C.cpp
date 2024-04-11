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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005, mod = 1000000007;
int n, x, pos, mn, mx;

void solve () {
	cin >> n >> x >> pos;
	int l = 0;
	int r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (pos >= m) {
			mn++;
			l = m + 1;
		} else {
			mx++;
			r = m;
		}
	}
	int a = x;
	int b = n - x;
	int c = n - mx - mn;
	ll res = 1;
	a--, mn--;
	forn (i, mn) {
		(res *= a) %= mod;
		a--;
	}
	forn (i, mx) {
		(res *= b) %= mod;
		b--;
	}
	while (c) {
		(res *= c) %= mod;
		c--;
	}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}