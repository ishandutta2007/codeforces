#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
string x, a, b;
void solve () {
	cin >> n >> x;
	int f = 0;
	a = "1";
	b = "1";
	for (int i = 1; i < n; i++) {
		if (f) {
			a.pb('0');
			b.pb(x[i]);
		} else if (x[i] == '0') {
			a.pb('0');
			b.pb('0');
		} else if (x[i] == '1') {
			a.pb('1');
			b.pb('0');
			f = 1;
		} else if (x[i] == '2') {
			a.pb('1');
			b.pb('1');
		}
	}
	cout <<a << endl << b << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}