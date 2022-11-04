#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, m, k, h[105];

void solve () {
	cin >> n >> m >> k;
	forn(i, n) cin >> h[i];
	ll acu = m;
	forn(i, n - 1) {
		if (h[i] >= max(0, h[i+1] - k)) {
			acu += h[i] - max(0, h[i+1] - k);
		} else {
			acu -= (h[i+1] - k) - h[i];
		}
		if (acu < 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}