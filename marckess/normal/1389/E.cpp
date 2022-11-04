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

ll m, d, w, res;

void solve () {
	cin >> m >> d >> w;
	res = 0;

	ll a = w / __gcd(w, d - 1);
	ll l = min(d, m);

	if (a >= l) {
		cout << 0 << endl;
		return;
	}

	ll x = (l - 1) / a - 1;

	res = a * x * (x + 1) / 2;
	res += (1 + (l - 1) % a) * (x + 1);

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