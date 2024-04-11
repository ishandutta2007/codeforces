#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
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
int n, k, a[MX];

void solve () {
	cin >> n >> k;
	int res;
	forn (i, n) cin >> a[i];
	
	while (k--) {
		int ind = -1;
		forn (i, n - 1)
			if (a[i] < a[i + 1]) {
				ind = i;
				break;
			}
		if (ind == -1) {
			cout << -1 << endl;
			return;
		}
		a[ind]++;
		res = ind;
	}
	
	cout << res + 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}