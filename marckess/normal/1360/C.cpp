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

int n, a[55], x, y, p;

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	sort(a, a + n);

	x = y = p = 0;
	forn (i, n) {
		if (a[i] % 2) x++;
		else y++;
		if (i && a[i] == a[i - 1] + 1) p++;
	}

	if (p || (x % 2 == 0 && y % 2 == 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}