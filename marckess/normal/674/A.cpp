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

const int MX = 5005;
int n, a[MX], cn[MX], mx, ind, res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];

	forn (i, n) {
		memset(cn, 0, sizeof(cn));
		mx = ind = 0;

		for (int j = i; j < n; j++) {
			cn[a[j]]++;

			if (cn[a[j]] > mx) {
				mx = cn[a[j]];
				ind = a[j];
			} else if (cn[a[j]] == mx) {
				ind = min(ind, a[j]);
			}

			res[ind]++;
		}
	}

	forn (i, n) cout << res[i + 1] << " ";
	cout << endl;

	return 0;
}