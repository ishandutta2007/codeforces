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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, k, a[105];
set<int> st;
vi res;

void solve () {
	cin >> n >> k;

	st.clear();
	forn (i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}

	if (st.size() > k) {
		cout << -1 << endl;
		return;
	}

	for (int i = 1; i <= n && st.size() < k; i++)
		st.insert(i);

	res.clear();

	for (int i = 0; i < n;) {
		for (int x : st) {
			if (i < n && x == a[i]) i++;
			res.pb(x);
		}
	}

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
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