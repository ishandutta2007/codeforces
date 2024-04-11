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

const int MX = 205;
int n, m, k, sx[MX], sy[MX], fx[MX], fy[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	forn (i, k) cin >> sx[i] >> sy[i];
	forn (i, k) cin >> fx[i] >> fy[i];

	string s;
	forn (i, n - 1) s.pb('U');
	forn (i, m - 1) s.pb('L');

	forn (i, n) {
		forn (j, m - 1) {
			if (i % 2 == 0) s.pb('R');
			else s.pb('L');
		}
		if (i + 1 < n) s.pb('D');
	}

	cout << s.size() << endl;
	for (char c : s) cout << c;
	cout << endl;

	return 0;
}