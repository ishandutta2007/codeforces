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
typedef vector<ii> vii;

const int MX = 500005;

ll n, x, y;
void solve () {
	int mx, mn;

	cin >> n >> x >> y;

	mx = min(n, x + y - 1);

	x = n - x + 1;
	y = n - y + 1;

	mn = n - max(0ll, min(n - 1, x + y - 3));

	cout << mn << " " << mx << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}