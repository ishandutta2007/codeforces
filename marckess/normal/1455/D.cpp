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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, x, a[MX], b[MX];

void solve () {
	cin >> n >> x;
	forn (i, n) cin >> a[i];
	
	int f = 1;
	forn (i, n - 1)
		f &= a[i] <= a[i + 1];
	
	if (f) {
		cout << 0 << endl;
		return;
	}
	
	int mn = 1e9;
	
	forn (i, n) {
		forn (j, n) b[j] = a[j];
		b[i] = x;
		sort(b, b + n);
		
		int p = 0, y = x;
		
		forn (i, n) {
			if (b[i] != a[i]) {
				if (b[i] != y || a[i] <= y) p = 1e9;
				else y = a[i], p++;
			}
		}
		
		mn = min(mn, p);
	}
	
	if (mn == 1e9) cout << -1 << endl;
	else cout << mn << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}