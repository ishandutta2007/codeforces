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

const int MX = 200005;
int n, res[MX];
ll s[MX], st[4*MX], lz[4*MX];

void build (int i, int j, int pos) {
	if (i == j) {
		st[pos] = s[i];
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	st[pos] = min(st[pos*2], st[pos*2+1]);
}

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos*2] += lz[pos];
		lz[pos*2+1] += lz[pos];
	}
	st[pos] += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int l, int r, ll k) {
	if (lz[pos]) push(i, j, pos);
	if (j < l || r < i) return;
	if (l <= i && j <= r) {
		lz[pos] += k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos*2, l, r, k);
	update(m+1, j, pos*2+1, l, r, k);
	st[pos] = min(st[pos*2], st[pos*2+1]);
}

int query (int i, int j, int pos) {
	if (lz[pos]) push(i, j, pos);
	if (st[pos] > 0) return -1;
	if (i == j) return i;
	int m = (i + j) / 2;
	int r = query(m + 1, j, pos * 2 + 1);
	if (r != -1) return r;
	return query(i, m, pos * 2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) cin >> s[i + 1];	
	build(1, n, 1);

	forn(i, n) {
		int t = query(1, n, 1);
		res[t] = i + 1;
		update(1, n, 1, t, t, 1e18);
		if (t < n)
			update(1, n, 1, t + 1, n, -i - 1);
	}

	forn(i, n) cout << res[i + 1] << " ";
	cout << endl;

	return 0;
}