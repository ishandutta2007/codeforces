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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int a[10][10];

int mex (set<int> st) {
	for (int i = 1; ; i++)
		if (!st.count(i))
			return i;
}

void solve () {
	forn (i, 9) forn (j, 9) {
		char c;
		cin >> c;
		a[i][j] = c - '0';
	}

	forn (i, 3)
		a[3*i][i] = a[3*i+1][3+i] = a[3*i+2][6+i] = mex({a[3*i][i], a[3*i+1][3+i], a[3*i+2][6+i]});

	forn (i, 9) {
		forn (j, 9) cout << a[i][j];
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}