#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
struct ST {
	ii mn[4 * MX];
	int lz[4 * MX];
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mn[pos].fi += lz[pos];
		lz[pos] = 0;
	}
	
	void build (int i, int j, int pos) {
		mn[pos] = {0, -j};
		lz[pos] = 0;
		
		if (i == j) return;
		
		int m = (i + j) / 2;
		build(i, m, pos * 2);
		build(m + 1, j, pos * 2 + 1);
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return {1e9, -1e9};
		
		if (a <= i && j <= b) return mn[pos];
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return min(x, y);
	}
}st;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n, b[MX], c[MX], f[MX];

void main_() {
	cin >> n;
	forn (i, n / 2)
		cin >> b[i];
	
	ordered_set sb, sc;
	forr (i, 1, n)
		sc.insert(i);
	
	forn (i, n / 2) {
		sb.insert(b[i]);
		sc.erase(b[i]);
		f[b[i]] = i;
	}
	
	if (sb.size() != n / 2) {
		cout << -1 << endl;
		return;
	}
	
	st.build(1, n, 1);
	
	vi vb, vc;
	for (int x : sb) {
		vb.pb(x);
		st.update(1, n, 1, x, x, 1e9);
	}
	
	for (int x : sc)
		vc.pb(x);
		
	int i = n / 2 - 1, j = n / 2 - 1;
	while (i >= 0) {
		while (j > 0 && vc[i] < vb[j - 1])
			j--;
		
		if (i - j < 0) {
			cout << -1 << endl;
			return;
		}
		
		st.update(1, n, 1, vc[i], vc[i], i - j);
		i--;
	}
	
	forn (i, n / 2) {
		auto it = sc.upper_bound(b[i]);
		if (it == sc.begin()) {
			cout << -1 << endl;
			return;
		}
		it--;
		
		ii p = st.query(1, n, 1, 1, *it);
		
		if (p.fi == 0) {
			c[i] = -p.se;
		} else {
			c[i] = *sc.begin();
		}
		
		st.update(1, n, 1, c[i], *it, -1);
		
		st.update(1, n, 1, c[i], c[i], 1e9);
		
		sb.erase(b[i]);
		sc.erase(c[i]);
	}
	
	forn (i, n / 2)
		cout << c[i] << " " << b[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}