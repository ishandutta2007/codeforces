#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 500003, SQ = 707;
int q, t, x, y, s[SQ+5][SQ+5], a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> q;
	while (q--) {
		cin >> t >> x >> y;
		if (t == 1) {
			for (int i = 1; i <= SQ; i++)
				s[i][x % i] += y;
			a[x] += y;
		} else {
			if (x <= SQ) cout << s[x][y] << endl;
			else {
				int res = 0;
				for (int i = y; i < MX; i += x)
					res += a[i];
				cout << res << endl;
			}
		}
	}

	return 0;
}