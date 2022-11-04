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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, x[MX], y[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> x[i] >> y[i];
	sort(x, x + n);
	sort(y, y + n);
	
	ll f = 1;
	ll g = 1;
	
	if (n % 2 == 0) {
		f = x[n / 2] - x[n / 2 - 1] + 1;
		g = y[n / 2] - y[n / 2 - 1] + 1;
	}
	
	cout << f * g << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}