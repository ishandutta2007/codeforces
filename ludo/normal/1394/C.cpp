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

int n;
vii pts;
vi xs, ys;

int xlo, xhi, ylo, yhi;

// used 'metric':
int dist(int dx, int dy) {
	if (dx >= 0 && dy >= 0) return max(dx, dy);
	if (dx <= 0 && dy <= 0) return max(-dx, -dy);
	return abs(dx) + abs(dy);
}

int maxd(int x, int y) {
	int res = 0;
	for (auto [u,v] : pts)
		res = max(res, dist(x-u, y-v));
	return res;
}

int f(int x) {
	int A = ylo, B = yhi;
	while (B - A > 10) {
		int miL = (2*A+B)/3;
		int miR = (A+2*B)/3;

		if (maxd(x, miL) < maxd(x, miR))
			B = miR;
		else
			A = miL;
	}

	int retVal = INT_MAX;
	for (int y = A; y <= B; y++) {
		int res = maxd(x, y);
		if (res <= retVal) {
			retVal = res;
		}
	}

	return retVal;
}

ii minim(int x) {
	int A = ylo, B = yhi;
	while (B - A > 10) {
		int miL = (2*A+B)/3;
		int miR = (A+2*B)/3;

		if (maxd(x, miL) < maxd(x, miR))
			B = miR;
		else
			A = miL;
	}

	int retVal = INT_MAX;
	int rety = -1;
	for (int y = A; y <= B; y++) {
		int res = maxd(x, y);
		if (res <= retVal) {
			retVal = res; rety = y;
		}
	}

	return {retVal, rety};
}

void run() {
	cin >> n;

	REP(i, n) {
		string S;
		cin >> S;
		int na = 0, nb = 0;
		for (char ch : S)
			(ch == 'B' ? na : nb)++;
		pts.eb(na, nb);
		xs.pb(na);
		ys.pb(nb);
	}

	/* cerr << "Poly: " << endl;
	for (auto [x,y] : pts) cerr << x << ", " << y << endl; */

	xlo = *min_element(all(xs));
	xhi = *max_element(all(xs));
	ylo = *min_element(all(ys));
	yhi = *max_element(all(ys));

	int A = xlo, B = xhi;
	while (B - A > 10) {
		int miL = (2*A+B)/3;
		int miR = (A+2*B)/3;

		if (f(miL) < f(miR))
			B = miR;
		else
			A = miL;
	}

	int retVal = INT_MAX;
	int retx = -1;
	for (int x = A; x <= B; x++) {
		int res = f(x);
		if (res <= retVal) {
			retVal = res; retx = x;
		}
	}

	auto [D, rety] = minim(retx);

	// cerr << "ret location: " << retx << ", " << rety << endl;

	cout << D << endl;
	REP(i, retx) cout << 'B';
	REP(i, rety) cout << 'N';
	cout << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}