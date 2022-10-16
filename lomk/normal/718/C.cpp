/*input
5 4
1 1 2 1 1
2 1 5
1 2 4 10000009
2 2 4
2 1 5
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define int unsigned
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1)
const int N = 1e5 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> a) {
	os << '[';
	for (unsigned i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
typedef array<array<int, 2>, 2> matrix;
const int mod = 1e9 + 7;

matrix operator*(const matrix &a, const matrix &b) {
	matrix c{{{0, 0}, {0, 0}}};
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 2; j++) {
				c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
			}
		}
	}
	return c;
}

matrix operator+(const matrix &a, const matrix &b) {
	matrix c; for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
			c[i][j] = (a[i][j] + b[i][j]);
			c[i][j] -= (c[i][j] > mod ? mod : 0);
		}
	return c;
}

matrix binPow(const matrix &a, int q) {
	if (q == 1) return a;
	if (!(q % 2)) return binPow(a * a, q / 2);
	else return a * binPow(a * a, q / 2);
}

pair<int, int> operator*(const pair<int, int> &a, const matrix &b) {
	pair<int, int> c{0, 0};
	c.fi = (1LL * a.fi * b[0][0] + 1LL * a.se * b[1][0]) % mod;
	c.se = (1LL * a.fi * b[0][1] + 1LL * a.se * b[1][1]) % mod;
	return c;
}

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
	return mp((a.fi + b.fi) % mod, (a.se + b.se) % mod);
}

matrix ONE{{{1, 0}, {0, 1}}};
matrix ZERO;
int n, q;
int a[N];
class ITrangeSum {
private:
	array<matrix, 3 * N> lazy;
	array<pair<int, int>, 3 * N> f;
	void dolazy(int k, int l, int r) {
		if (lazy[k] == ONE) return;
		f[k] = f[k] * lazy[k];
		if (l != r) {
			lazy[k * 2] = lazy[k * 2] * lazy[k];
			lazy[k * 2 + 1] = lazy[k * 2 + 1] * lazy[k];
		}
		lazy[k] = ONE;
	}
public:
	void init() {
		lazy.fill(ONE); f.fill(mp(1, 1));
	}
	void update(int k, int l, int r, int L, int R, const matrix &val) {
		dolazy(k, l, r);
		if (L <= l && r <= R) {
			lazy[k] = lazy[k] * val;
			dolazy(k, l, r);
			return;
		}
		if (r < L || R < l) return;
		int mid = (l + r) / 2;
		update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
		f[k] = f[k * 2] + f[k * 2 + 1];
	}
	pair<int, int> get(int k, int l, int r, int L, int R) {
		dolazy(k, l, r);
		if (L <= l && r <= R) return f[k];
		if (r < L || R < l) return mp(0, 0);
		int mid = (l + r) / 2;
		return get(k * 2, l, mid, L, R) + get(k * 2 + 1, mid + 1, r, L, R);
	}
} IT;


matrix mem[31];
void prep() {
	mem[0] = {{{0, 1}, {1, 1}}};
	loop(i, 1, 30) {
		mem[i] = mem[i - 1] * mem[i - 1];
	}
}

matrix getMat(int p) {
	matrix ret = ONE;
	for (int i = 0; i < 30; i++) {
		if (bit(p, i)) ret = ret * mem[i];
	}
	return ret;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef in1code
	freopen("1test.inp", "r", stdin);
	freopen("1test.out", "w", stdout);
#endif
	prep();
	cin >> n >> q;
	loop(i, 1, n) cin >> a[i];
	IT.init();
	loop(i, 1, n) IT.update(1, 1, n, i, i, getMat(a[i] - 1));
	loop(Q, 1, q) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, x; cin >> l >> r >> x;
			IT.update(1, 1, n, l, r, getMat(x));
		}
		else {
			int l, r; cin >> l >> r;
			cout << IT.get(1, 1, n, l, r).fi << endl;
		}
	}
}