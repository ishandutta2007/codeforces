#include <bits/stdc++.h>

#define endl '\n'
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll x, y, k;

void solve () {
	cin >> x >> y >> k;

	ll d = y * k;
	ll res = (d + (x - 1) - 1) / (x - 1);


	d = res * (x - 1) + 1;
	d -= y * k;

	if (d < k) {
		d = k - d;
		res += (d + (x - 1) - 1) / (x - 1);
	}

	res += k;

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}