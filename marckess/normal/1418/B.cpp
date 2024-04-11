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

const int MX = 105;
int n, a[MX], l[MX];

void solve () {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
	}

	vi x, y;

	forn (i, n) {
		cin >> l[i];
		if (l[i]) x.pb(a[i]);
		else y.pb(a[i]);
	}

	sort(all(y), greater<ll>());

	for (int i = 0, j = 0, k = 0; i < n; i++) {
		if (l[i]) {
			cout << x[j] << " ";
			j++;
		} else {
			cout << y[k] << " ";
			k++;
		}
	}
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