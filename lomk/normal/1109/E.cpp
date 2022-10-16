/*input
5 2100
1 2 3 4 5
4
1 1 3 12
1 1 5 10
2 5 50
3 1 5
1 4 4 28
2 4 7
2 3 3
3 1 5
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// priority to use auto
const int N = 1e5 + 5; const int P = 1600030;
const int D = 11;

int power[D][P], mod, inv[N];

int eulerPhi(int n) {
	if (n == 0) return 0;
	int ans = n;
	for (int x = 2; 1LL * x * x <= n; ++x) {
		if (n % x == 0) {
			ans -= ans / x;
			while (n % x == 0) n /= x;
		}
	}
	if (n > 1) ans -= ans / n;
	return ans;
}

int extract(const array<int, D> &div, int more) {
	int ret = more;
	loop(i, 0, D - 1) ret = 1LL * ret * power[i][div[i]] % mod;
	return ret;
}

struct Lazy {
	int rem; array<int, D> div;
	Lazy(): rem(1) {div.fill(0);};
	Lazy(int _rem, array<int, D> _div): rem(_rem), div(_div) {};
	void combine(const Lazy &Y) { // not to make leaf
		rem = 1LL * rem * Y.rem % mod;
		loop(i, 0, D - 1) div[i] = div[i] + Y.div[i];
	}
} ZERO;

struct Node {
	int sum, rem; bool leaf; array<int, D> div;
	Node(): sum(0), rem(1), leaf(0) {div.fill(0);};
	void norm() {
		assert(leaf);
		sum = extract(div, rem);
	}
	void combine(const Node &Y) { // not to make leaf
		sum = (sum + Y.sum); if (sum >= mod)sum -= mod;
	}
	void combine(const Lazy &Y) {
		if (!leaf) {
			sum = 1LL * sum * extract(Y.div, Y.rem) % mod;
			return;
		}
		leaf = true;
		rem = 1LL * rem * Y.rem % mod;
		loop(i, 0, D - 1) div[i] = div[i] + Y.div[i];
		norm();
	}

	void rCombine(const Lazy &Y) {
		assert(leaf);
		rem = 1LL * rem * inv[Y.rem] % mod;
		loop(i, 0, D - 1) div[i] = (div[i] - Y.div[i]);
		norm();
	}
};

#ifdef UncleGrandpa
ostream &operator<<(ostream &os, Node X) {
	os << "sum " << X.sum << " rem " << X.rem << " div:" << X.div;
	return os;
}

ostream &operator<<(ostream &os, Lazy X) {
	os << "[rem " << X.rem << " div:" << X.div << "]";
	return os;
}
#endif

bool operator ==(const Lazy &a, const Lazy &b) {
	return (a.rem == b.rem && a.div == b.div);
}

class ITrangeSum {
private:
#define mid ((l+r)/2)
	int n;
	Node f[4 * N];
	Lazy lazy[4 * N];
	void dolazy(int k, int l, int r) {
		if (lazy[k] == ZERO) return;
		f[k].combine(lazy[k]);
		if (l != r) {
			lazy[k * 2].combine(lazy[k]);
			lazy[k * 2 + 1].combine(lazy[k]);
		}
		lazy[k] = ZERO;
	}
	void mul(int k, int l, int r, int L, int R, const Lazy &val) {
		dolazy(k, l, r);
		if (r < L || R < l) return;
		if (L <= l && r <= R) {
			lazy[k] = val; dolazy(k, l, r);
			return;
		}
		mul(k * 2, l, mid, L, R, val); mul(k * 2 + 1, mid + 1, r, L, R, val);
		f[k].sum = (f[k * 2].sum + f[k * 2 + 1].sum) % mod;
	}
	int get(int k, int l, int r, int L, int R) {
		dolazy(k, l, r);
		if (r < L || R < l) return 0;
		if (L <= l && r <= R) 
			return f[k].sum;
		return (get(k * 2, l, mid, L, R) + get(k * 2 + 1, mid + 1, r, L, R)) % mod;
	}
	void init(int k, int l, int r, vector<Node>&a) {
		if (l == r) {
			f[k] = a[l - 1];
			return;
		}
		init(k * 2, l, mid, a); init(k * 2 + 1, mid + 1, r, a);
		f[k].sum = 0;
		f[k].combine(f[k * 2]); f[k].combine(f[k * 2 + 1]);
	}
	void div(int k, int l, int r, int pos, const Lazy &val) {
		dolazy(k, l, r);
		if (r < pos || pos < l) return;
		if (l == pos && pos == r) {
			f[k].rCombine(val);
			return;
		}
		div(k * 2, l, mid, pos, val); div(k * 2 + 1, mid + 1, r, pos, val);
		f[k].sum = 0;
		f[k].combine(f[k * 2]); f[k].combine(f[k * 2 + 1]);
	}
public:
	void init(int _n, vector<Node> &a) {n = _n; init(1, 1, n, a);}
	int get(int l, int r) {return get(1, 1, n, l, r);};
	void mul(int l, int r, Lazy val) {mul(1, 1, n, l, r, val);};
	void div(int p, Lazy val) {div(1, 1, n, p, val);}
#undef mid
} IT;


auto fact(int X) {
	vector<pair<int, int> > ret;
	for (int i = 2; 1LL * i * i <= X; i++) {
		int cnt = 0;
		while (X % i == 0) {
			cnt++; X /= i;
		}
		if (cnt) ret.push_back({i, cnt});
	}
	if (X > 1) ret.push_back({X, 1});
	return ret;
}

#define pow binPow
int binPow(int a, int q) {
	int ret = 1;
	while (q) {
		if (q & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		q >>= 1LL;
	}
	return ret;
}


unordered_map<int, int> enc;
void prep() {
	auto rec = fact(mod);
	loop(i, 0, D - 1) loop(j, 0, P - 5) power[i][j] = 1;
	sort(rec.begin(), rec.end());
	loop(i, 0, rec.size() - 1) {
		enc[rec[i].fi] = i;
		loop(j, 1, P - 5) power[i][j] = 1LL * power[i][j - 1] * rec[i].fi % mod;
	}
	const int ph = eulerPhi(mod);
	loop(i, 1, N - 5) inv[i] = binPow(i, ph - 1);
}

Node conv(int X) {
	auto rec = fact(X);
	Node ret;
	for (auto it : rec) {
		if (enc.find(it.fi) != enc.end()) ret.div[enc[it.fi]] += it.se;
		else while (it.se--)ret.rem = (ret.rem * it.fi) % mod;
	}
	return ret;
}

Lazy convLz(int X) {
	auto rec = conv(X);
	return {rec.rem, rec.div};
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> mod;
	prep();
	vector<Node> inp;
	loop(i, 1, n) {
		int t; cin >> t;
		auto rec = conv(t); rec.leaf = true; rec.norm();
		inp.push_back(rec);
	}
	IT.init(n, inp);
	int q; cin >> q;
	loop(Q, 1, q) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, val;
			cin >> l >> r >> val;
			IT.mul(l, r, convLz(val));
		}
		else if (type == 2) {
			int pos, val; cin >> pos >> val;
			IT.div(pos, convLz(val));
		}
		else {
			int l, r; cin >> l >> r;
			cout << IT.get(l, r) << endl;
		}
	}
}