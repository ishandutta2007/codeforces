#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n;

void solve () {
	cin >> n;

	if (n == 2) {
		cout << "Ashishgup" << endl;
		return;
	}

	if (n == (n & -n)) {
		cout << "FastestFinger" << endl;
		return;
	}

	int dos = 0;
	while (n % 2 == 0) {
		dos++;
		n /= 2;
	}

	if (dos != 1) {
		cout << "Ashishgup" << endl;
	} else {
		int cn = 1;

		for (int i = 3; i * i <= n; i += 2) {
			if (n % i == 0) {
				cn++;
				if (i * i < n)
					cn++;
			}
		}

		if (cn > 1) {
			cout << "Ashishgup" << endl;
		} else {
			cout << "FastestFinger" << endl;
		}
	}
}	

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}