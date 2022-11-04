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

const int MX = 500005, mod = 1000000007;
ll n, a[MX], res, cn[66];

void solve () {
	memset(cn, 0, sizeof(cn));
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		
		forn (j, 60)
			if (a[i] & (1ll << j))
				cn[j]++;
	}
	
	res = 0;
	forn (i, n) {
		ll x = 0, y = 0;
		
		forn (j, 60)
			if (a[i] & (1ll << j))
				(x += (1ll << j) % mod * cn[j]) %= mod;
		
		forn (j, 60) {
			if (a[i] & (1ll << j))
				(y += (1ll << j) % mod * n) %= mod;
			else
				(y += (1ll << j) % mod * cn[j]) %= mod;
		}
		
		(res += x * y) %= mod;
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