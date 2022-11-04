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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n;
ll acu, res, a[MX], b[MX];

void solve () {
	res = acu = 0;

	cin >> n;
	forn (i, n) {
		cin >> a[i] >> b[i];
		res += a[i];
	}
	
	forn (i, n)
		acu += max(0ll, a[(i + 1) % n] - b[i]);

	forn (i, n) {
		ll p = acu - max(0ll, a[(i + 1) % n] - b[i]) + a[(i + 1) % n];
		res = min(res, p);
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