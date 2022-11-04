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

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, k, a[MX], res;
map<int, int> mp;
ordered_set st;
ii b[MX];

void solve () {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];

	mp.clear();
	forn (i, n / 2) {
		int x = a[i] + a[n - i - 1];
		mp[x]++;
		b[i] = {a[i], a[n - i - 1]};
		if (b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
	}

	sort(b, b + n / 2);
	res = n / 2;

	int i = 0;

	st.clear();
	for (auto it : mp) {
		int p = n / 2 - it.se;

		while (i < n / 2 && b[i].fi < it.fi) {
			st.insert(ii(b[i].se, i));
			i++;
		}

		p += n / 2 - i;
		p += st.order_of_key(ii(it.fi - k, -1));

		res = min(res, p);
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