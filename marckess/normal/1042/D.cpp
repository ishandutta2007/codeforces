#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n;
ordered_set st;
ll t, a[MX], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	st.insert({0, 0});

	for (int i = 1; i <= n; i++) {
		res += i - st.order_of_key({a[i]-t, n});
		st.insert({a[i], i});
	}

	cout << res << endl;

	return 0;
}