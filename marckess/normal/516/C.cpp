#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, q, a, b, d[200005], mx[200005], act;
ll h[200005] = {0}, acu[200005] = {0};

struct Nodo {
	ll pref, suf, mx, tot;

	Nodo () {}
	Nodo (int x) {
		pref = suf = mx = -1e12;
		tot = 0;
	}
};

struct ST {
	Nodo st[500005];

	Nodo marge (Nodo a, Nodo b) {
		Nodo res;

		res.pref = max(a.pref, a.tot + b.pref);
		res.suf = max(b.suf, b.tot + a.suf);
		res.mx = max(a.suf + b.pref, max(a.mx, b.mx));
		res.tot = a.tot + b.tot;

		return res;
	}

	void constr (int i, int j, int pos) {
		if (i == j) {
			st[pos].suf = 2 * h[i] + d[i];
			st[pos].pref = 2 * h[i];
			st[pos].mx = 0;
			st[pos].tot = d[i];
			return;
		}

		int m = (i+j)/2;
		constr(i, m, pos*2);
		constr(m+1, j, pos*2+1);

		st[pos] = marge(st[pos*2], st[pos*2+1]);
	}

	Nodo query (int i, int j, int a, int b, int pos) {
		if (i > b || j < a)
			return Nodo(0);

		if (a <= i && j <= b)
			return st[pos];

		int m = (i+j)/2;
		return marge(query(i, m, a, b, pos*2), query(m+1, j, a, b, pos*2+1));
	}
};

ST st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		d[i+n] = d[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		h[i+n] = h[i];
	}

	st.constr(1, 2*n, 1);

	while (q--) {
		cin >> a >> b;

		if (a <= b) {
			a += n;
			a--;
			b++;
			swap(a, b);
		} else {
			swap(a, b);
			b--;
			a++;
		}

		cout << st.query(1, 2*n, a, b, 1).mx << endl;
	}

	return 0;
}