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
 
typedef __int128 ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int MX = 1000005;
int n, a[MX], res;

void solve () {
	cin >> n;

	forn (i, n) {
		int in;
		cin >> in;
		a[in]++;
	}

	res = 0;
	
	for (int i = 1, c = 0; i <= n; i++) {
		a[i] += c;
		res += a[i] / i;
		c = a[i] % i;
		a[i] = 0;
	}

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