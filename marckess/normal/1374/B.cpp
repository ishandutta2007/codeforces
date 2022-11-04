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

int n;

void solve () {
	int tres = 0, dos = 0;
	cin >> n;

	while (n % 2 == 0) {
		n /= 2;
		dos++;
	}

	while (n % 3 == 0) {
		n /= 3;
		tres++;
	}

	if (n > 1 || dos > tres) {
		cout << -1 << endl;
		return;
	}

	cout << (tres - dos) + tres << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}