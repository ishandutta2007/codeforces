#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
const int maxn = 1000100;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<ll> punkt;


struct Angle {
	ll x, y;
	int t;
	int half() const {
		return y < 0 || (y == 0 && x < 0);
	}
	Angle(int x=0, int y=0, int t=0) : x(x), y(y), t(t) {}
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
};
ll cross(const Angle &a, const Angle &b) {
    return a.x * b.y - a.y * b.x;
}
bool is_left(const Angle &p, const Angle &q) {
    return cross(p, q) > 0;
}
bool is_right(const Angle &p, const Angle &q) {
    return cross(p, q) < 0;
}

bool cmpzero(const Angle &A) {
    pii zero = {0, 0};
    pii a = {A.x, A.y};
    return a < zero;
}
bool eqzero(const Angle &A) {
    pii zero = {0, 0};
    pii a = {A.x, A.y};
    return a == zero;
}
bool operator<(const Angle &A, const Angle &B) {
    if (eqzero(B)) return false;
    if (eqzero(A)) return true;
    
	bool aorig = cmpzero(A);
	bool borig = cmpzero(B);
	if (aorig != borig) { return aorig > borig; }

	return is_left(A, B);
}

ll count_triangles(const vector <punkt> &vec, int ktory) {
    int n = sz(vec);
    
    vector <Angle> angles(n);
    rep(i, 0, n) {
        punkt tmp = vec[i] - vec[ktory];
        Angle kat(tmp.x, tmp.y, 0);
        angles[i] = kat;
    }
		
    sort(all(angles));
    assert(angles[0].x == angles[0].y && angles[0].x == 0);
    for (int i = 1; i < n; ++i) {
		angles.push_back(angles[i]);
	}
	
    ll ret = (ll)(n - 1) * (n - 2) * (n - 3) / 6;
    int j = 1;
    ll numbad = 0;
    rep(i, 1, n) {
		j = max(j, i);
        while (j + 1 < sz(angles) && is_left(angles[i], angles[j + 1])) j++;
        debug(i, j);
        ll ile = j - i;
        numbad += ile * (ile - 1) / 2;
    }
    ret -= numbad;
    debug(ret, numbad);
    return ret;
}

void solve(int tc) {
	int n, m;
	cin >> n;
	vector <punkt> vec(n);
	rep(i, 0, n) {
	    int a, b;
	    cin >> a >> b;
	    vec[i] = punkt(a, b);
	}
	
	ll res = 0;
	rep(i, 0, n) res += count_triangles(vec, i);
	res *= (ll)(n - 4);
	cout << res / 2 << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}