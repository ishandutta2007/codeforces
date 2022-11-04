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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, a[MX], bs[MX];
vi res;

void solve () {
	cin >> n;
	res.clear();

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		bs[i] = 0;
	}

	int x = 1;
	while (!bs[x]) {
		bs[x] = 1;
		
		if (bs[x - a[x]]) {
			int r = x;
			do {
				res.pb(r);
				r -= a[r];
			} while (r != x);
		}

		x -= a[x];
	}

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}