#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;

void solve () {
	cin >> n;
	
	vector<ll> a, b;
	
	forn (i, 2 * n) {
		int x, y;
		cin >> x >> y;
		
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		
		if (x) a.pb(x);
		else b.pb(y);
	}
	
	sort(all(a));
	sort(all(b));
	
	ld res = 0;
	forn (i, n)
		res += sqrt(a[i] * a[i] + b[i] * b[i]);
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	cout << fixed << setprecision(12);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}