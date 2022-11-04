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

int n, u, r, d, l;

void solve () {
	cin >> n >> u >> r >> d >> l;
	
	forn (x, 2) forn (y, 2) forn (z, 2) forn (w, 2) {
		int a = u - x - y;
		int b = r - y - w;
		int c = d - w - z;
		int d = l - z - x;
		
		int f = 1;
		f &= 0 <= a && a <= n - 2;
		f &= 0 <= b && b <= n - 2;
		f &= 0 <= c && c <= n - 2;
		f &= 0 <= d && d <= n - 2;
		
		if (f) {
			cout << "YES" << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}