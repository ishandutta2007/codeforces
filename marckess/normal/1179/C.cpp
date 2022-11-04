#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, a[MX], b[MX], q, i, x, op, st[4*MX], lz[4*MX];

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos*2] += lz[pos];
		lz[pos*2+1] += lz[pos];
	}
	st[pos] += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int x, int k) {
	if (lz[pos]) push(i, j, pos);
	if (x < i) return;
	if (j <= x) {
		lz[pos] += k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos*2, x, k);
	update(m+1, j, pos*2+1, x, k);
	st[pos] = max(st[pos*2], st[pos*2+1]);
}

int query (int i, int j, int pos) {
	if (lz[pos]) push(i, j, pos);
	if (i == j) {
		if (st[pos] > 0) return i;
		return -1;
	}
	int m = (i + j) / 2;
	if (lz[pos*2+1]) push(m+1, j, pos*2+1);
	if (st[pos*2+1] > 0) return query(m+1, j, pos*2+1);
	return query(i, m, pos*2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 1e6, 1, a[i], 1);
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		update(1, 1e6, 1, b[i], -1);
	}

	cin >> q;
	while (q--) {
		cin >> op >> i >> x;
		if (op == 1) {
			update(1, 1e6, 1, a[i], -1);
			a[i] = x;
			update(1, 1e6, 1, a[i], 1);
		} else {
			update(1, 1e6, 1, b[i], 1);
			b[i] = x;
			update(1, 1e6, 1, b[i], -1);
		}
		cout << query(1, 1e6, 1) << endl;
	}

	return 0;
}