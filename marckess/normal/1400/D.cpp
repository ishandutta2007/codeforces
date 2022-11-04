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

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 3005;
int n, a[MX];
ordered_set st[MX];
ll res;

void solve () {
	cin >> n;

	for (int i = 1; i <= n; i++)
		st[i].clear();

	forn (i, n) {
		cin >> a[i];
		st[a[i]].insert(i);
	}

	res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int x = st[a[j]].order_of_key(i);
			int y = st[a[i]].size() - st[a[i]].order_of_key(j + 1);
			res += x * y;
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