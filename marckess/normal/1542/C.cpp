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

const int mod = 1000000007;
ll n;

void solve () {
	cin >> n;
	
	ll res = 0;
	for (ll i = 1, x = 1; x <= n; i++) {
		ll nex = x * (i + 1) / __gcd(x, i + 1);
		
		(res += (i + 1) * (n / x)) %= mod;
		(res -= (i + 1) * (n / nex)) %= mod;
		
		x = nex;
	}
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}