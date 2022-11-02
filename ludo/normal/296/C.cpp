#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize

template<class T> int sz(const vector<T> &v) { return (int) v.size(); }

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const bool LOG = false;
void Log() {
	if(LOG) cerr << "\n\n";
}
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

struct BIT {
	int n; vi A;
	BIT(int _n) : n(_n), A(_n+1, 0) {}
	BIT(vi &v) : n(sz(v)), A(1) {
		for (auto x:v) A.pb(x);
		for (int i=1, j; j=i&-i, i<=n; i++)
			if (i+j <= n) A[i+j] += A[i];
	}
	void update(int i, ll v) { // A[i] += v
		while (i <= n) A[i] += v, i += i&-i;
	}
	ll query(int i) { // sum_{j<=i} A[j]
		ll v = 0;
		while (i) v += A[i], i -= i&-i;
		return v;
	}
};

struct rangeBIT {
	int n; BIT b1, b2;
	rangeBIT(int _n) : n(_n), b1(_n), b2(_n+1) {}
	rangeBIT(vi &v) : n(sz(v)), b1(v), b2(sz(v)+1) {}
	void pupdate(int i, ll v) { b1.update(i, v); }
	void rupdate(int i, int j, ll v) { // A[k] += v (i <= k <= j)
		b2.update(i, v);
		b2.update(j+1, -v);
		b1.update(j+1, v*j);
		b1.update(i, (1-i)*v);
	}
	ll query(int i) { return b1.query(i)+b2.query(i)*i; }
};

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vi v(n);
	REP(i, n) scanf("%lld", &v[i]);

	vi L(m), R(m), D(m), occ(m+1, 0);
	REP(i, m) scanf("%lld%lld%lld", &L[i], &R[i], &D[i]);

	REP(i, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		occ[x-1]++;
		occ[y]--;
	}

	// construct the prefix sum now.
	REP(i, m) {
		occ[i+1] += occ[i];
	}

	rangeBIT main_ds(v);

	REP(i, m) {
		cerr << i << ": " << occ[i] << endl;
		main_ds.rupdate(L[i], R[i], occ[i]*D[i]);
	}

	ll lv = 0;
	REP(i, n) {
		ll nv = main_ds.query(i+1);
		printf("%lld ", (nv - lv));
		lv = nv;
	}
	printf("\n");
	
	return 0;
}