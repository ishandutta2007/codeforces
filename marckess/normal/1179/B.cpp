#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, ox = 1, oy = 1, x = 1, y = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	cout << 1 << " " << 1 << endl;

	while (n && m) {
		if (n == 1) {
			int i = oy, j = oy + m - 1, f = (y == oy);
			while (i < j) {
				if (f) {
					i++;
					y = j;
				} else {
					j--;
					y = i;
				}
				cout << x << " " << y << endl;
				f = 1 - f; 
			}
			break;
		} else if (m == 1) {
			int i = ox, j = ox + n - 1, f = (x == ox);
			while (i < j) {
				if (f) {
					i++;
					x = j;
				} else {
					j--;
					x = i;
				}
				cout << x << " " << y << endl;
				f = 1 - f; 
			}
			break;
		} else {
			int a = oy, b = oy + m - 1, f = 1;
			for (int kk = 0; kk < 2 * m - 1; kk++) {
				if (f) {
					a++;
					x = ox + n - 1;
					y = b;
				} else {
					b--;
					x = ox;
					y = a;
				}
				cout << x << " " << y << endl;
				f = 1 - f;
			}
			n -= 2;
			ox++;
			x = ox;
			y = 1;
			if (n) cout << x << " " << y << endl;
		}
	}
 
	return 0;
}