#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) begin(v), end(v)
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
		<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

namespace std { template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
}; }

typedef unsigned long long ull; 

// row echelon form:
const int ROWS = 200'000;
const int MAXM = 35, PARAM = 18;
// const int MAXM = 7, PARAM = 3;
const ll mod = 998244353;

struct M {
	ll x;
	M() : x(0LL) {}
	M(ll _x) : x(_x) {
		x %= mod;
		if (x < 0LL) x += mod;
	}

	M operator+(const M &rhs) const {
		ll y = x+rhs.x;
		return M(y >= mod ? y-mod : y);
	}

	M& operator+=(const M &rhs) {
		if ((x += rhs.x) >= mod)
			x -= mod;
		return *this;
	}

	M operator*(const M &rhs) const {
		ll prod = ll(x) * rhs.x;
		return M(prod % mod);
	}

	M operator^(ll exp) const {
		if (exp <= 1) return exp ? *this : M(1);
		M sq = (*this * *this)^(exp/2);
		if (exp & 1) return sq * *this;
		else return sq;
	}
};

inline bool test(const ull &mask, int idx) { return (mask >> idx) & 1; }

void print_bits(ull mask) {
	for (int i=MAXM; i--; ) cout << test(mask, i);
	cout << endl;
}


ull mat[ROWS] = {};

// returns the rank of the matrix
// puts M into reduced row echelon form..
int solveM(int n, int m) {
	int pr = 0, pc = 0;
	while (pc < m) {
		int r = pr, c;
		while (r < n && !test(mat[r], pc)) r++;
		if (r == n) { pc++; continue; }

		if (r != pr) swap(mat[pr], mat[r]);

		r = pr++;
		c = pc++;

		REP(row, n)
			if (row != r && test(mat[row], c)) mat[row] ^= mat[r];
	} // now M is in RREF
	return pr;
}


void fht(vi &A, bool inv, int l, int r) {
	if (l+1 == r) return;
	int k = (r-l)/2;
	if (!inv) fht(A, inv, l, l+k), fht(A, inv, l+k, r);
	rep(i,l,l+k) {
		ll x = A[i], y = A[i+k];
		if (!inv) A[i] =  x-y,    A[i+k] =   x+y;
		else      A[i] = (x+y)/2, A[i+k] = (-x+y)/2;
	}
	if (inv) fht(A, inv, l, l+k), fht(A, inv, l+k, r);
}

void fht(vi &A, bool inv) { fht(A, inv, 0, A.size()); }


int pc(ull mask) { return __builtin_popcountll(mask); }

int pre_pc[1<<PARAM];

void run() {
	REP(i, 1 << PARAM) pre_pc[i] = pc(i);

	int n, m;
	// n = 200'000; m = 0; REP(i, n) mat[i] = rand() % (1LL<<m);

	cin >> n >> m;
	REP(i, n) cin >> mat[i];

	int rk = solveM(n, m);

	assert(*max_element(mat, mat+rk) < (1LL << MAXM));

	vvi as(MAXM - PARAM + 1, vi(1<<PARAM, 0));
	vi bs(1<<PARAM, 0);

	const ull LOW_BITS = (1 << (MAXM - PARAM)) - 1;

	int nfst = min(MAXM - PARAM, rk);
	REP(mask, 1<<nfst) {
		ull xorSum = 0;
		for (int j=0; j < nfst; j++)
			if (test(mask, j)) xorSum ^= mat[j];
		ull hi = xorSum >> (MAXM - PARAM);
		ull lo = xorSum & LOW_BITS;

		as[pc(lo)][hi]++;
	}

	REP(mask, 1<<(rk-nfst)) {
		ull xorSum = 0;
		for (int j=0; j < rk-nfst; j++)
			if (test(mask, j)) xorSum ^= mat[nfst + j];
		ull hi = xorSum >> (MAXM - PARAM);
		ull lo = xorSum & LOW_BITS;
		// assert(lo == 0);
		bs[hi]++;
	}

	vector<M> ans(MAXM + 1);

	fht(bs, false);
	REP(i, MAXM - PARAM + 1) {

		fht(as[i], false);
		REP(j, 1<<PARAM)
			as[i][j] *= bs[j];

		fht(as[i], true);
		// as now has the product.

		REP(j, 1<<PARAM) {
			ans[i + pre_pc[j]] += M(as[i][j] % mod);
		}
	}
	// ans[i] <= 2^PARAM * n^2.

	M p2 = M(2)^(n - rk);

	for (int i=0; i<=m; i++) {
		M res = ans[i] * p2;
		cout << res.x << " \n"[i==m];
	}
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}