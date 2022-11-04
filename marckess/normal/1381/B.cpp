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

const int MX = 4005;
int n, p[MX], mem[MX][MX];
vi a;

int dp (int i, int j) {
	if (i == a.size()) return j == 0;
	if (j < 0) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;

	return res = dp(i + 1, j) || dp(i + 1, j - a[i]);
}

void solve () {
	cin >> n;

	forn (i, 2 * n) cin >> p[i];

	int act = 0, acu = 0;
	a.clear();

	forn (i, 2 * n) {
		if (p[i] > act) {
			act = p[i];
			a.pb(acu);
			acu = 0;
		}
		acu++;
	}
	a.pb(acu);

	forn (i, a.size()) forn (j, n + 1) mem[i][j] = -1;
	if (dp(0, n)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}