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

const int MX = 1000005;
int n, a[MX];
vi x, y;

void solve () {
	cin >> n;
	
	for (int i = 1; i <= 2 * n; i++)
		a[i] = 0;
	
	forn (i, n) {
		int b;
		cin >> b;
		a[b] = 1;
	}
	
	x.clear();
	y.clear();
	
	for (int i = 1; i <= 2 * n; i++)
		if (a[i])
			x.pb(i);
		else
			y.pb(i);
	
	int a, b;
	
	int i = 0, j = min(x.size(), y.size()), rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		int f = 1;
		
		for (int i = 0, j = (int)y.size() - m; i < m; i++, j++)
			f &= x[i] <= y[j];
		
		if (f) i = m;
		else j = m;
	}
	
	b = i;
	
	i = 0, j = min(x.size(), y.size()), rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		int f = 1;
		
		for (int i = (int)x.size() - m, j = 0; j < m; i++, j++)
			f &= x[i] >= y[j];
		
		if (f) i = m;
		else j = m;
	}
	
	a = n - i;
	
	cout << max(0, b - a + 1) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
		
	return 0;
}