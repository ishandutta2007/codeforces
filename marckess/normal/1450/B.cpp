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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, k, x[MX], y[MX];

void solve () {
	cin >> n >> k;
	forn (i, n)
		cin >> x[i] >> y[i];
	forn (i, n) {
		int cn = 0;
		forn (j, n)
			cn += abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k;
		if (cn == n) {
			cout << 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve ();
	
	return 0;
}