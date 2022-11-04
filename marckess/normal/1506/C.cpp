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

int n, m;
string a, b;

void solve () {
	cin >> a >> b;
	n = a.size(), m = b.size();
	
	int res = n + m;
	forn (r, n) forn (l, r + 1) 
		forn (y, m) forn (x, y + 1) {
			string aa = a.substr(l, r - l + 1);
			string bb = b.substr(x, y - x + 1);
			
			if (aa == bb)
				res = min(res, n + m - (r - l + 1) - (y - x + 1));
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