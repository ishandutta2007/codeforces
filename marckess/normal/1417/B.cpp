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

const int MX = 100005;
int n, t, a[MX], cn;
set<int> x;

void solve () {
	cin >> n >> t;
	forn (i, n) cin >> a[i];
	
	x.clear();
	cn = 0;
	
	forn (i, n) {
		if (2 * a[i] == t) cn++;
		else if (!x.count(t - a[i])) x.insert(a[i]); 
	}
	
	cn /= 2;
	
	forn (i, n) {
		if (2 * a[i] == t) {
			if (cn) {
				cout << 1 << " ";
				cn--;
			} else {
				cout << 0 << " ";
			}
		} else {
			cout << x.count(a[i]) << " ";
		}
	}
	
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