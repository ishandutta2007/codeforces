#include <bits/stdc++.h>
 
#define endl '\n'
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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 105;
int a[MX], b[MX], n;

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];

	sort(a, a+n);
	sort(b, b+n);

	forn(i, n) cout << a[i] << " ";
	cout << endl;
	forn(i, n) cout << b[i] << " ";
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