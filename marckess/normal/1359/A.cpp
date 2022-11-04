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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, k, a[55];

void solve () {
	cin >> n >> m >> k;

	memset(a, 0, sizeof(a));
	a[0] = min(n / k, m);
	m -= a[0];

	for (int i = 1; m; m--) {
		a[i]++;
		i++;
		if (i == k) i = 1;
	}

	cout << a[0] - a[1] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();		

	return 0;
}