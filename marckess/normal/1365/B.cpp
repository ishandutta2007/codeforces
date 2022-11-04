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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, a[MX], b[MX], x;

void solve () {
	x = 0;

	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) {
		cin >> b[i];
		x += b[i];
	}

	if (x && x < n) {
		cout << "Yes" << endl;
		return;
	}

	forn (i, n - 1) if (a[i] > a[i + 1]) {
		cout << "No" << endl;
		return;
	}

	cout << "Yes" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}