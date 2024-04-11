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
typedef vector<ll> vl;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, q, a[MX];
ll res;
ordered_set ft[MX];

void update (int i, int k) {
	while (i <= n) {
		if (k > 0) ft[i].insert(k);
		else ft[i].erase(-k);
		i += i & -i;
	}
}

int query (int i, int k) {
	int s = 0;
	while (i) {
		s += ft[i].order_of_key(k);
		i -= i & -i;
	}
	return s;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		update(i, i);
		a[i] = i;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		#define inv(x) x + a[x] - 2 * (1 + query(x, a[x]));

		res -= inv(l)
		res -= inv(r)
		if (a[l] < a[r] != l < r) res++;

		update(l, -a[l]);
		update(r, -a[r]);
		swap(a[l], a[r]);
		update(l, a[l]);
		update(r, a[r]);

		res += inv(l)
		res += inv(r)
		if (a[l] < a[r] != l < r) res--;

		cout << res << endl;
	}

	return 0;
}