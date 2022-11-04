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

const int MX = 1000005;
const ll inf = 1e18;
ll mn[4*MX], lz[4*MX];
int st[4*MX];

void build (int i, int j, int pos) {
	st[pos] = i;
	mn[pos] = -inf;
	if (i == j) return;

	int m = (i + j) / 2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
}

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos*2] += lz[pos];
		lz[pos*2+1] += lz[pos];
	}
	mn[pos] += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, ll k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}

	int m = (i + j) / 2;
	update(i, m, pos*2, a, b, k);
	update(m+1, j, pos*2+1, a, b, k);
	
	if (mn[pos*2] > mn[pos*2+1]) st[pos] = st[pos*2], mn[pos] = mn[pos*2];
	else st[pos] = st[pos*2+1], mn[pos] = mn[pos*2+1];
}

ll query (int i, int j, int pos, int x) {
	if (lz[pos]) push(i, j, pos);
	if (j < x || x < i) return 0;
	if (i == j) return mn[pos];
	int m = (i + j) / 2;
	return query(i, m, pos*2, x) + query(m+1, j, pos*2+1, x);
}

int n, x[MX], y[MX], c[MX], m;
vi mp;
vii pos[MX];
ll res = 0, ra = 2e9, rb = 2e9;

int find (vi &v, int x) {
	return lower_bound(all(v), x) - v.begin();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> c[i];
		mp.pb(x[i]);
		mp.pb(y[i]);
	}

	mp.pb(-1);
	sort(all(mp));
	mp.erase(unique(all(mp)), mp.end());

	m = (int)mp.size() - 1;
	for (int i = 0; i < n; i++)
		pos[find(mp, min(x[i], y[i]))].emplace_back(find(mp, max(x[i], y[i])), c[i]);

	build(1, m, 1);

	for (int i = m; i > 0; i--) {
		update(1, m, 1, i, i, inf);
		for (ii &x : pos[i]) {
			update(1, m, 1, x.fi, m, x.se);
		}
		if (i < m)
			update(1, m, 1, i+1, m, mp[i] - mp[i+1]);
		
		if (mn[1] > res) {
			res = mn[1];
			ra = mp[i];
			rb = mp[st[1]];
		}
	}

	cout << res << endl;
	cout << ra << " " << ra << " " << rb << " " << rb << endl;

	return 0;
}