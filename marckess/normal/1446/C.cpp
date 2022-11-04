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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];

int go (int i, int j, int bt) {
	if (j - i + 1 <= 2 || bt == 0) return j - i + 1;
	int res = 0;
	
	int ant = i, cn = 0;
	
	for (int k = i + 1; k <= j; k++) {
		int x = a[k - 1] & ((1ll << (bt + 1)) - 1);
		int y = a[k] & ((1ll << (bt + 1)) - 1);
		
		if ((x ^ y) > y) {
			res = max(res, cn + go(ant, k - 1, bt - 1) + 1);
			cn++;
			ant = k;
		}
	}
	
	res = max(res, cn + go(ant, j, bt - 1));
	
	return res;
}

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	sort (a, a + n, greater<int>());
	cout << n - go(0, n - 1, 30) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
		
	return 0;
}