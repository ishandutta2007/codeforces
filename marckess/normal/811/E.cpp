#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, LMX = 18;
#define num(i,j) ((i) + (j) * 10)

int p[10*MX];
stack<int> st;

void reset () {
	while (st.size()) {
		int u = st.top();
		st.pop();
		p[u] = u;
	}
}

int parent (int a) {
	if (a == p[a]) return a;
	st.push(a);
	return p[a] = parent(p[a]);
}

int joint (int a, int b) {
	a = parent(a), b = parent(b);
	st.push(a);
	p[a] = b;
}

bool same (int a, int b) {
	return parent(a) == parent(b);
}

int n, m, q, l, r, a[10][MX];
int tl[MX][LMX][10], tr[MX][LMX][10];
int cl[MX][LMX], cr[MX][LMX], cn;
int inl[MX][LMX], inr[MX][LMX];

void merge (int l, int r) {
	if (l == r) {
		for (int k = 1; k < n; k++)
			if (a[k][l] == a[k-1][l]) {
				cn--;
				joint(num(k, l), num(k-1, l));
			}
	} else {
		for (int k = 0; k < n; k++)
			if (a[k][l] == a[k][r] && !same(num(k, l), num(k, r))) {
				cn--;
				joint(num(k, l), num(k, r));
			}
	}
}

void build () {
	for (int j = 0; (1 << j) <= m; j ++) {
		int sz = 1 << j;

		int mk = sz-1;
		int act = 0;
		cn = 0;

		for (int i = 0; i < m; i++) {
			cn += n;

			merge(i, i);
			if (i > act) merge(i-1, i);

			for (int k = 0; k < n; k++) tl[i][j][k] = parent(num(k, act));
			cl[i][j] = cn;
			inl[i][j] = act;

			if ((i & mk) == mk) {
				reset();
				act = i+1, cn = 0;
			}
		}

		reset();
		act = m-1, cn = 0;
		for (int i = m-1; i >= 0; i--) {
			cn += n;

			merge(i, i);
			if (i < act) merge(i, i+1);

			for (int k = 0; k < n; k++) tr[i][j][k] = parent(num(k, act));
			cr[i][j] = cn;
			inr[i][j] = act;
			
			if ((i & mk) == 0) {
				reset();
				act = i-1, cn = 0;
			}
		}
	}
}

int query (int l, int r) {
	reset();

	if (l == r) {
		cn = n;
		merge(l, l);
		return cn;
	}

	int i = 31 - __builtin_clz(l ^ r);
	cn = cl[r][i] + cr[l][i];
	
	for (int k = 0; k < n; k++) {
		if (a[k][inl[r][i]] == a[k][inr[l][i]] && !same(tl[r][i][k], tr[l][i][k])) {
			cn--;
			joint(tl[r][i][k], tr[l][i][k]);
		}
	}

	return cn;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+10*MX, 0);

	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	build();

	while (q--) {
		cin >> l >> r;
		cout << query(l-1, r-1) << endl;
	}

	return 0;
}