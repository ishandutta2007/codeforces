#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, mn[MX], cn[MX], res;
ii a[MX];
ordered_set st;

void solve () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a, a+n, [&] (const ii &i, const ii &j) {
		return i.se < j.se;
	});

	mn[n-1] = a[n-1].fi;
	cn[n-1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		cn[i] = cn[i+1] + (mn[i+1] > a[i].se);
		mn[i] = min(mn[i+1], a[i].fi);
	}

	st.clear();
	res = cn[1];

	for (int i = 0; i + 1 < n; i++) {
		while (st.size()) {
			int x = *st.find_by_order((int)st.size() - 1);
			if (x < a[i].fi) break;
			st.erase(x);
		}
		st.insert(a[i].se);

		if (i + 2 < n)
			res = max(res, cn[i+2] + (int)st.order_of_key(mn[i+2]));
	}

	res = max(res, (int)st.size());
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