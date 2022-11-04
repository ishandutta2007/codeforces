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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], sig[MX], res = 1e9;

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sig[i] = -1;
	}

	res = 1e9;
	for (int i = n; i; i--) {
		if (sig[a[i]] != -1)
			res = min(res, sig[a[i]] - i + 1);
		sig[a[i]] = i;
	}

	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;  
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}