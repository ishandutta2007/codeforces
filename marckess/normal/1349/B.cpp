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

const int MX = 100005;
int n, a[MX], k, cn;

bool valid (vi v) {
	int cn = 0;
	for (int x : v)
		if (x >= k)
			cn++;
	return 2 * cn > v.size();
}

void solve () {
	cin >> n >> k;

	cn = 0;
	forn (i, n) {
		cin >> a[i];
		if (a[i] == k)
			cn++;
	}

	if (!cn) {
		cout << "no" << endl;
		return;
	}

	if (n == 1) {
		cout << "yes" << endl;
		return;
	}

	forn (i, n - 1)
		if (valid({a[i], a[i + 1]})) {
			cout << "yes" << endl;
			return;
		}

	forn (i, n - 2)
		if (valid({a[i], a[i + 1], a[i + 2]})) {
			cout << "yes" << endl;
			return;
		}

	cout << "no" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}