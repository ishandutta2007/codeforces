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

ll n, m, k, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	k += 2;
	
	ll s = sqrt(n) + 5;
	
	for (int x = 1; x <= s; x++) {
		ll y = k - x;
		if (y <= 0) continue;
		
		res = max(res, (n / x) * (m / y));
	}
	
	for (int t = 1; t <= s; t++) {
		ll x = n / t;
		ll y = k - x;
		
		if (x <= 0 || y <= 0) continue;
			
		res = max(res, (n / x) * (m / y));
	}
	
	s = sqrt(n) + 5;
	
	for (int y = 1; y <= s; y++) {
		ll x = k - y;
		if (x <= 0) continue;
		
		res = max(res, (n / x) * (m / y));
	}
	
	for (int t = 1; t <= s; t++) {
		ll y = m / t;
		ll x = k - y;
		
		if (x <= 0 || y <= 0) continue;
			
		res = max(res, (n / x) * (m / y));
	}
	
	if (res) cout << res << endl;
	else cout << -1 << endl;
	
	return 0;
}