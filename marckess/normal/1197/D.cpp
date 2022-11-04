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

const int MX = 300005;
int n, m, k;
ll a[MX], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	forn(i, n) cin >> a[i];
	
	for (int ini = 0; ini < min(m, n); ini++) {
		ll dp = 0;
		for (int i = ini; i < n;) {
			ll s = 0;
			for (int j = 0; j < m && i < n; j++, i++) {
				res = max(res, dp + s - k);
				s += a[i];
			}
			dp = max(0ll, dp + s - k);
			res = max(res, dp);
		}
	}
	cout << res << endl;

	return 0;
}