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

const int MX = 1000005;
ll k, l, r, t, x, y;
int vis[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k >> l >> r >> t >> x >> y;
	
	k -= l;
	r -= l;
	l = 0;
	
	if (y <= x) {
		__int128 a, _1 = 1;
				
		if (k + y > r) {
			a = k - _1 * t * x + _1 * (t - 1) * y;
		} else {
			a = k - _1 * t * x + _1 * t * y;
		}
		
		if (a < 0) cout << "No" << endl;
		else cout << "Yes" << endl;	
		
		return 0;
	}
	
	ll acu = 0;
	
	while (acu < t) {
		if (k < 0) {
			cout << "No" << endl;
			return 0;
		}
		
		ll d = min(t - acu, k / x);
		
		acu += d;
		k -= d * x;
		
		if (k < x) {
			if (vis[k]) break;
			vis[k] = 1;
		}
		
		if (acu < t) {
			if (k + y <= r)
				k += y;
			k -= x;
			acu++;
		}
	}
	
	if (k < 0) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}