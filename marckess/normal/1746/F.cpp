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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MX = 300005, tries = 60;

void update (int ft[], int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int ft[], int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query (int ft[], int a, int b) {
	return query(ft, b) - query(ft, a - 1);
}

int n, q, a[MX];
map<int, ll> mp;
int ft[tries][MX];

ll get_hash (int x) {
	if (!mp.count(x))
		mp[x] = uniform_int_distribution<ll>(0, 1ll << tries)(rng);
	return mp[x];
}

void update (int i, int x) {
	ll t = get_hash(abs(x));
	forn (j, tries)
		if (t & (1ll << j))
			update(ft[j], i, x > 0 ? 1 : -1);
}

void main_() {
	cin >> n >> q;
	forr (i, 1, n) {
		cin >> a[i];
		update(i, a[i]);
	}
	
	while (q--) {
		int op;
		cin >> op;
		
		if (op == 1) {
			int i, x;
			cin >> i >> x;
			
			update(i, -a[i]);
			update(i, a[i] = x);
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			
			int f = (r - l + 1) % k == 0;
			forn (j, tries)
				f &= query(ft[j], l, r) % k == 0;
			
			if (f) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}