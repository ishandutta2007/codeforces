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
int n, p[MX], izq[MX], der[MX];

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	
	for (int i = 1; i <= n; i++) {
		if (p[i - 1] < p[i]) izq[i] = izq[i - 1] + 1;
		else izq[i] = 1;
	}
	
	for (int i = n; i >= 1; i--) {
		if (p[i] > p[i + 1]) der[i] = der[i + 1] + 1;
		else der[i] = 1;
	}
	
	int mx = 0, cn = 0;
	for (int i = 1; i <= n; i++)
		mx = max({mx, izq[i], der[i]});
		
	for (int i = 1; i <= n; i++)
		cn += mx == max(izq[i], der[i]);
	
	if (cn > 1) {
		cout << 0 << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++)
		if (mx == max(izq[i], der[i])) {
			int a = izq[i], b = der[i];
			if (a > b) {
				a -= a % 2;
				cout << (a < b) << endl;
			} else {
				b -= b % 2;
				cout << (a > b) << endl;
			}
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	
	return 0;
}