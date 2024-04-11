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

const int MX = 200005, mod = 1000000007;
int n, a[MX];

void solve () {
	cin >> n;
	
	int x = 0;
	forn (i, n) {
		cin >> a[i];
		if (!i) x = a[i];
		else x &= a[i];
	}
	
	int cn = 0;
	forn (i, n)
		cn += x == a[i];
	
	if (cn < 2) {
		cout << 0 << endl;
		return;
	}
	
	ll res = 1ll * cn * (cn - 1) % mod;
	for (int i = 1; i <= n - 2; i++)
		(res *= i) %= mod;
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