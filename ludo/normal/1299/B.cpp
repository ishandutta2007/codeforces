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
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const ld PI = acos(-1.0);
template<class T> using min_queue =
		priority_queue<T, vector<T>, greater<T>>;
template<class T> int sz(const T &x) {
	return (int) x.size(); // copy the ampersand(&)!
}

template<class T> ostream& operator<<(ostream &os, vector<T> &v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

struct pairhash {
public:
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2> &p) const {
		size_t lhs = hash<T1>()(p.x);
		size_t rhs = hash<T2>()(p.y);
		return lhs ^ (rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
	}
};

bool run() {
	int n;
	cin >> n;

	vii pts(n);
	for (int i=0; i<n; i++) {
		cin >> pts[i].x >> pts[i].y;
		pts[i].x *= 2;
		pts[i].y *= 2;
	}

	if (n % 2 == 1) return false;

	int hn = n/2;
	ii orig(
		(pts[0].x + pts[hn].x) / 2,
		(pts[0].y + pts[hn].y) / 2
	);
	for (int i=0; i<n; i++) pts[i].x -= orig.x;
	for (int i=0; i<n; i++) pts[i].y -= orig.y;

	for (int i=0; i<hn; i++)
		if (pts[i].x != -pts[i+hn].x ||
			pts[i].y != -pts[i+hn].y) return false;
	return true;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	(cout << fixed).precision(18);
	bool ans = run();
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}