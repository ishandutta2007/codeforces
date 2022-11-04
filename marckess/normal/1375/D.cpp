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

const int MX = 1005;
int n, a[MX];
vi res;

int mex () {
	set<int> st;
	forn (i, n) st.insert(a[i]);

	for (int i = 0;; i++)
		if (!st.count(i))
			return i;
}

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];

	res.clear();
	
	forn (i, n) {
		if (a[i] == i) continue;

		while (mex() != i) {
			int x = mex();

			if (x == n) {
				forn (j, n) if (a[j] == i) {
					a[j] = x;
					res.pb(j);
					break;
				}
			} else {
				a[x] = x;
				res.pb(x);
			}
		}

		a[i] = i;
		res.pb(i);
	}

	/*forn (i, n) cout << a[i] << " ";
	cout << endl;*/

	cout << res.size() << endl;
	for (int r : res) cout << r + 1 << " ";
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