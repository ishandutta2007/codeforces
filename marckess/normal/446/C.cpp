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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005, SQ = 550, mod = 1e9+9;
ll f[MX], acu[MX];
int n, q, a[MX], op, l, r;
ll st[4*MX], la[4*MX], lb[4*MX];
bitset<4*MX> lz;

void pre () {
	f[1] = 1;
	for (int i = 2; i < MX; i++)
		f[i] = (f[i-1] + f[i-2]) % mod;

	for (int i = 1; i < MX; i++)
		acu[i] = (acu[i-1] + f[i]) % mod;
}

void s (ll &x, ll y) {
	x = (x + y) % mod;
}

void build (int i, int j, int pos) {
	if (i == j) {
		st[pos] = a[i];
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	st[pos] = (st[pos*2] + st[pos*2+1]) % mod;
}

void push (int i, int j, int pos) {
	if (i == j) {
		s(st[pos], la[pos] + lb[pos]);
	} else {
		int m = (i+j)/2, len = m-i+1;

		s(st[pos], acu[j-i+1] * la[pos] + (acu[j-i+2] - 1) * lb[pos]);

		s(la[pos*2], la[pos]);
		s(lb[pos*2], lb[pos]);

		s(la[pos*2+1], f[len-1] * la[pos] + f[len] * lb[pos]);
		s(lb[pos*2+1], f[len] * la[pos] + f[len+1] * lb[pos]);

		lz[pos*2] = lz[pos*2+1] = 1; 
	}

	la[pos] = lb[pos] = 0;
	lz[pos] = 0;
}

int query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (b < i || j < a) return 0;
	if (a <= i && j <= b) return st[pos];

	int m = (i+j)/2;
	return (query(i, m, pos*2, a, b) + query(m+1, j, pos*2+1, a, b)) % mod;
}

void update (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (b < i || j < a) return;

	if (a <= i && j <= b) {
		int len = i - a;
		if (!len) la[pos] = 1, lb[pos] = 0;
		else la[pos] = f[len-1], lb[pos] = f[len];
		lz[pos] = 1;
		push(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2, a, b);
	update(m+1, j, pos*2+1, a, b);
	
	st[pos] = (st[pos*2] + st[pos*2+1]) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, n, 1);

	while (q--) {
		cin >> op >> l >> r;

		if (op == 1) update(1, n, 1, l, r);
		else cout << MOD(query(1, n, 1, l, r), mod) << endl;
	}

	return 0;
}