#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX];

ll go (int i, int j) {
	ll s = 0, mx = 0;
	while (i < j) {
		s = max(0ll, s + a[i]);
		mx = max(mx, s);
		i++;
	}
	return mx;
}

void solve () {
	cin >> n;

	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if (s > go(0, n - 1) && s > go(1, n)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}