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

const int MX = 300005;
int a[MX], n;
struct Node {
	bool ok;
	int mn, mx;

	Node () : ok(true), mx(0), mn(int(1e9+5)) {}
	Node (bool ok, int mn, int mx) : ok(ok), mn(mn), mx(mx) {}
};

Node operator + (const Node a, const Node b) {
	return {
		a.ok && b.ok && b.mn * 2 >= a.mx,
		min(a.mn, b.mn),
		max(a.mx, b.mx),
	};
}

Node st[4*MX];
void build (int i, int j, int pos) {
	if (i == j) {
		st[pos] = {true, a[i], a[i]};
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
	st[pos] = st[pos*2] + st[pos*2+1];
}

int query (int i, int j, int pos, int mx) {
	if (i == j) {
		if (2 * st[pos].mn >= mx) return i;
		return i - 1;
	}
	int m = (i + j) / 2;
	if (st[pos*2].ok && 2 * st[pos*2].mn >= mx)
		return query(m + 1, j, pos * 2 + 1, max(mx, st[pos*2].mx));
	return query(i, m, pos * 2, mx);
}

void update (int i, int j, int pos, int x) {
	if (x < i || j < x) return;
	if (i == j) {
		st[pos] = Node();
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos*2, x);
	update(m+1, j, pos*2+1, x);
	st[pos] = st[pos*2] + st[pos*2+1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i + 2 * n] = a[i];
	}

	build(1, 3 * n, 1);
	for (int i = 1; i <= n; i++) {
		int j = query(1, 3 * n, 1, 0);
		if (j == 3 * n) cout << -1 << " ";
		else cout << j - i + 1 << " ";
		update(1, 3 * n, 1, i);
	}
	cout << endl;

	return 0;
}