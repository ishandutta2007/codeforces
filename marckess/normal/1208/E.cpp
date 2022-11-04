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

const int MX = 1000005, inf = 2000000000;
int n, w, len, s[MX], st[4*MX];
ll ft[MX];

void update(int i, ll k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i) {
	ll s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void build (int i, int j, int pos) {
	if (i == j) {
		st[pos] = i;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
	if (s[st[pos * 2]] > s[st[pos * 2 + 1]]) st[pos] = st[pos * 2];
	else st[pos] = st[pos * 2 + 1];
}

int query (int i, int j, int pos, int l, int r) {
	if (j < l || r < i) return -1;
	if (l <= i && j <= r) return st[pos];
	int m = (i + j) / 2;
	int a = query(i, m, pos * 2, l, r);
	int b = query(m + 1, j, pos * 2 + 1, l, r);
	if (a != -1 && (b == -1 || s[a] > s[b])) return a;
	return b;
}

void update (int i, int j, int pos, int x) {
	if (j < x || x < i) return;
	if (i == j) {
		s[i] = -inf;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	if (s[st[pos*2]] < s[st[pos*2+1]]) st[pos] = st[pos*2];
	else st[pos] = st[pos*2+1];
}

void go (int i, int j, int l, int r) {
	if (l > r || i > j) return;
	int p = query(1, len, 1, i, j);

	int mn = p;
	int mx = w - (len - p);
	mn = max(mn, l);
	mx = min(mx, r);

	if (mn > mx) {
		update(1, len, 1, p);
		return go(i, j, l, r);
	}

	update(mn, s[p]);
	update(mx+1, -s[p]);

	go(i, p - 1, l, mn - 1);
	go(p + 1, j, mx + 1, r);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> w;
	w += 2;

	while (n--) {
		cin >> len;
		forn(i, len) cin >> s[i + 2];

		s[1] = s[len + 2] = 0;
		len += 2; 

		build(1, len, 1);
		go(1, len, 1, w);
	}

	forr(i, 2, w - 1) cout << query(i) << " ";
	cout << endl;

	return 0;
}