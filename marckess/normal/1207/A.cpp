#include <bits/stdc++.h>
 
#define endl '\n'
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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		if (h > c) {
			int x = min(b / 2, p);
			b -= 2 * x;
			cout << x * h + c * min(b / 2, f) << endl;
		} else {
			int y = min(b / 2, f);
			b -= 2 * y;
			cout << y * c + h * min(b / 2, p) << endl;
		}
	}

	return 0;
}