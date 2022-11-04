#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
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

const int MX = 500005;
int m, q;
ll a[MX], k[MX], res[MX], w[MX], mn, n;
ordered_set st;
vi pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> q;
	forn(i, n) {
		int x;
		cin >> x;
		a[x]++;
	}
	forn(i, q) cin >> k[i];

	iota(w, w+q, 0);
	sort(w, w+q, [&] (int i, int j) {
		return k[i] < k[j];
	});

	forr(i, 1, m) {
		pos[a[i]].pb(i);
		if (!a[i])
			st.insert(i);
	}

	forn(i, q) {
		ll u = k[w[i]];
		while (mn < MX && u - n - 1 >= st.size()) {
			n += st.size();
			mn++;
			if (mn < MX)
				for (int x : pos[mn])
					st.insert(x);
		}
		res[w[i]] = *st.find_by_order((u - n - 1) % st.size());
	}

	forn(i, q) cout << res[i] << endl;

	return 0;
}