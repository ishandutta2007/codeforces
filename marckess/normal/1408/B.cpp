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

const int MX = 105;
int n, k, a[MX];

int techo (int a, int b) {
	return (a + b - 1) / b;
}

void solve () {
	cin >> n >> k;
	forn (i, n) cin >> a[i];

	set<int> st;

	forn (i, n) st.insert(a[i]);

	if (k == 1) {
		if (st.size() == 1) cout << 1 << endl;
		else cout << -1 << endl;
	} else {
		if (k >= st.size()) cout << 1 << endl;
		else cout << 1 + techo((int)st.size() - k, k - 1) << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)	
		solve();

	return 0;
}