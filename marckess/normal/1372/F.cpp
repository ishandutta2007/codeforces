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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
set<int> st;

ii query (int l, int r) {
	int x, f;
	cout << "? " << l << " " << r << endl;
	cin >> x;
	if (x == -1) exit(0);
	cin >> f;
	return {x, f};
}

void solve (int i, int j, int mn) {
	if (i > j) return;

	ii r = query(i, j);

	if (r.fi == mn) {
		forn (k, r.se)
			a[i + k] = r.fi;
		return solve(i + r.se, j, r.fi);
	}

	if (j - i + 1 == r.se) {
		forn (k, r.se)
			a[i + k] = r.fi;
		return;
	}

	if (st.count(r.fi)) {
		forn (k, r.se)
			a[j - k] = r.fi;
		return solve(i, j - r.se, mn);
	}

	st.insert(r.fi);

	for (int k = i; k <= j; k += r.se) {
		if (k != i) mn = a[k - 1];
		solve(k, min(j, k + r.se - 1), mn);
	}
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	solve (1, n, 1);

	cout << "!";
	for (int i = 1; i <= n; i++)
		cout << " " << a[i];
	cout << endl;

	return 0;
}