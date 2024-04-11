#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, a[MX], p[MX];
string s;

struct Node {
	int mx, pre, suf, tot, ciz, cde, cto;
}st[4*MX];

Node op = {1, 1, 0, 1, 1, 1, 1};
Node cl = {1, 0, 1, -1, 1, 1, 1};

Node operator + (Node &a, Node &b) {
	Node n;

	n.mx = max({a.mx, b.mx, a.cde + b.pre, a.suf + b.ciz});
	n.pre = max(a.pre, a.tot + b.pre);
	n.suf = max(b.suf, a.suf - b.tot);
	n.tot = a.tot + b.tot;
	n.ciz = max({a.ciz, a.cto + b.pre, -a.tot + b.ciz});
	n.cde = max({b.cde, a.suf + b.cto, a.cde + b.tot});
	n.cto = max({-a.tot + b.tot, a.cto + b.tot, -a.tot + b.cto});

	return n;
}

void build (int i, int j, int pos) {
	if (i == j) {
		if (a[i] == 1) st[pos] = op;
		else st[pos] = cl;
		p[i] = pos;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	st[pos] = st[pos*2] + st[pos*2+1];
}

void update (int i) {
	int pos = p[i];
	if (a[i] == 1) st[pos] = op;
	else st[pos] = cl;

	pos /= 2;
	while (pos) {
		st[pos] = st[pos*2] + st[pos*2+1];
		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q >> s;
	n = 2 * (n - 1);

	for (int i = 0; i < n; i++)
		a[i+1] = s[i] == '(' ? 1 : -1;

	build(1, n, 1);
	cout << st[1].mx << endl;

	while (q--) {
		int x, y;
		cin >> x >> y;
		swap(a[x], a[y]);

		update(x);
		update(y);
		cout << st[1].mx << endl;
	}

	return 0;
}