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

const int MX = 100005;
int n, m, a[MX];

void solve () {
	cin >> n >> m;
	
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			mx = i;
	}
	
	ld res = 1;
	while (m--) {
		ld p;
		int r;
		cin >> r >> p;
		if (r >= mx)
			res *= 1 - p;
	}
	
	if (!mx) {
		cout << 1.0 << endl;
		return;
	}
	
	cout << 1 - res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}