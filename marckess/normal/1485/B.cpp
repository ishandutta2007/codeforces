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

const int MX = 100005;
int n, k, q, a[MX];
ll acu[MX];

void solve () {
	cin >> n >> q >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		acu[i] = a[i + 1] - a[i - 1] - 2;
		acu[i] += acu[i - 1];
	}
	
	while (q--) {
		int l, r;
		ll res = 0;
		
		cin >> l >> r;
		
		if (l == r) {
			res += k - 1;
		} else {
			if (r - l + 1 >= 3)
				res += acu[r - 1] - acu[l];
			
			res += a[l + 1] - 2;
			res += k - a[r - 1] - 1;
		}
		
		cout << res << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}