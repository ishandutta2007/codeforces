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

const int MX = 200005;
int n, k, a[MX], w[MX];
ll res;

void solve () {
	cin >> n >> k;
	forn (i, n) cin >> a[i];
	sort(a, a + n, greater<int>());

	forn (i, k) cin >> w[i];
	sort(w, w + k);

	res = 0;
	int j = 0;
	forn (i, k) {
		res += a[j];
		if (w[i] == 1) res += a[j]; 
		j++;
	}

	forn (i, k)
		if (w[i] != 1) {
			w[i] -= 2;
			while (w[i]--)
				j++;
			res += a[j];
			j++;
		}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}