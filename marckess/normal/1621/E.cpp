// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

//RB Tree
#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<vi,null_type,less<vi>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 100005;
int n, m, a[MX], k[MX];
vvi b, x;

set<int> no, izq, der;
ordered_set st;

ll techo (ll a, ll b) {
	return (a + b - 1) / b;
}

bool find (set<int> &st, int l, int r) {
	auto it = st.lower_bound(l);
	return it != st.end() && *it <= r;
}

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
		
	string res;
	b = vvi(m);
	x = vvi(m);
	
	forn (i, m) {
		cin >> k[i];
		
		b[i] = vi(k[i]);
		x[i] = vi(3);
	
		x[i][1] = 0;
		x[i][2] = i;
		
		forn (j, k[i]) {
			cin >> b[i][j];
			x[i][1] += b[i][j];
			res.pb('0');
 		}
 		
 		x[i][0] = techo(x[i][1], k[i]);
	}
	
	sort(a, a + n);
	sort(all(x));
	
	no.clear();
	izq.clear();
	der.clear();
	st.clear();
	
	forn (i, m) {
		int j = n - (m - i);
		ll avg = x[i][0];
		
		if (j < 0 || n <= j) no.insert(i);
		if (avg > a[j]) no.insert(i);
		
		j--;
		if (j < 0 || n <= j) izq.insert(i);
		if (avg > a[j]) izq.insert(i);
		
		j += 2;
		if (j < 0 || n <= j) der.insert(i);
		if (avg > a[j]) der.insert(i);
		
		st.insert(x[i]);
	}
	
	sort(all(x), [&] (const vi &a, const vi &b) {
		return a[2] < b[2];
	});
	
	int ptr = -1;
	forn (i, m) {
		int act = st.order_of_key(x[i]);
		
		for (int t : b[i]) {
			ptr++;
			
			ll na = techo(x[i][1] - t, k[i] - 1);
			int nex = st.order_of_key(vi{na});
			
			if (nex <= act) {
				if (find(no, 0, nex - 1)) continue;
				if (find(der, nex, act - 1)) continue;
				if (find(no, act + 1, m - 1)) continue;
				if (na > a[n - (m - nex)]) continue;
			} else {
				if (find(no, 0, act - 1)) continue;
				if (find(izq, act + 1, nex - 1)) continue;
				if (find(no, nex, m - 1)) continue;
				if (na > a[n - (m - (nex - 1))]) continue;
			}
			
			res[ptr] = '1';
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}