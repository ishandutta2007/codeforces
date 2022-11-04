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

ll n;

bool esPos (ll m) {
	if (!m) return 1;
	ll a = 2 * m + 1;
	ll b = a * a / 2;
	return a * a - b <= n;
}

void solve () {
	cin >> n;
	
	ll i = 0, j = 1e9, rep = 35;
	while (rep--) {
		ll m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}
	
	cout << i << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
		
	return 0;
}