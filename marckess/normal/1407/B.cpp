#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 1005;
int n, a[MX], us[MX], g;

void solve () {
	memset(us, 0, sizeof(us));
	g = 0;

	cin >> n;
	forn (i, n) cin >> a[i];

	forn (kk, n) {
		int ind = -1;

		forn (i, n) if (!us[i]) {
			if (ind == -1) {
				ind = i;
			} else if (__gcd(g, a[i]) > __gcd(g, a[ind])) {
				ind = i;
			}
		}

		cout << a[ind] << " ";
		g = __gcd(g, a[ind]);
		us[ind] = 1;
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