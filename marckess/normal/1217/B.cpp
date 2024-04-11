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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, x, g[MX], h[MX], mg, md;

void solve () {
	cin >> n >> x;
	mg = md = 0;

	forn(i, n) {
		cin >> g[i] >> h[i];
		mg = max(mg, g[i]);
		md = max(md, g[i] - h[i]);
	}

	if (!md && x > mg) {
		cout << -1 << endl;
		return;
	}

	int i = 0, j = 1e9, rep = 32;
	while (rep--) {
		ll m = (i + j) / 2;
		if (x - m * md <= mg) j = m;
		else i = m;
	}

	cout << j + 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}