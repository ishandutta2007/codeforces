#include <bits/stdc++.h>

//#define endl '\n'
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void solve () {
	int n, mx = 0;
	cin >> n;
	for (int i = 0; i <= 6; i++) {
		vi a[2];
		for (int j = 1; j <= n; j++)
			a[bool(j&(1<<i))].pb(j);
		if (a[0].empty() || a[1].empty()) break;

		cout << a[0].size() << " " << a[1].size();
		for (int x : a[0]) cout << " " << x;
		for (int x : a[1]) cout << " " << x;
		cout << endl;

		int r;
		cin >> r;
		if (r == -1) exit(0);
		mx = max(mx, r); 
	}

	cout << "-1 " << mx << endl;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}