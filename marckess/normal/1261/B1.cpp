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
int n, a[MX], m, k[MX], pos[MX], res[MX];
ii in[MX];
vi q[MX];
ordered_set st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		in[i] = {a[i], -i};
	}
	sort(in, in+n, greater<ii>());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k[i] >> pos[i];
		q[k[i]-1].pb(i);
	}

	for (int i = 0; i < n; i++) {
		st.insert(-in[i].se);
		for (int j : q[i]) {
			int r = *st.find_by_order(pos[j]-1);
			res[j] = a[r];
		}
	}

	for (int i = 0; i < m; i++)
		cout << res[i] << endl;

	return 0;
}