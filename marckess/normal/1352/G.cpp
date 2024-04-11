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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
vi a[4];

void solve () {
	cin >> n;

	if (n < 4) {
		cout << -1 << endl;
		return;
	}

	forn (i, 4) a[i].clear();

	forn (i, n)
		a[(i + 1) % 4].pb(i + 1);

	reverse(all(a[0]));
	reverse(all(a[3]));

	for (int x : a[2]) cout << x << " ";
	for (int x : a[0]) cout << x << " ";
	for (int x : a[1]) cout << x << " ";
	for (int x : a[3]) cout << x << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}