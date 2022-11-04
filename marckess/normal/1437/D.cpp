#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
int n, a[MX];

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	vi v;
	int cn = 1;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] < a[i + 1]) cn++;
		else {
			v.pb(cn);
			cn = 1;
		}
	}
	if (cn) v.pb(cn);
	int act = 1, nex = 0, res = 0;
	for (int x : v) {
		if (!nex) res++;
		nex += x;
		act--;
		if (!act) {
			act = nex;
			nex = 0;
		}
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