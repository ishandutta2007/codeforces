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

const int MX = 3005;
int n, a[MX];

int esPos (int s) {
	int res = 0, acu = 0;
	
	forn (i, n) {
		acu += a[i];
		
		if (acu == s) {
			res++;
			acu = 0;	
		}
		
		if (acu > s)
			return 1e9;
	}
	
	if (acu) return 1e9;
	return n - res; 
}

void solve () {
	cin >> n;
	
	forn (i, n)
		cin >> a[i];
	
	int s = 0, res = n - 1;
	forn (i, n) {
		s += a[i];
		res = min(res, esPos(s));
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