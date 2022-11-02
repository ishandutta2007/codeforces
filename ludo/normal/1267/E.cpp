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

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
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

void run() {
	int n, m;
	cin >> n >> m;
	vvi A(m, vi(n, 0LL));
	REP(i, m) REP(j, n) cin >> A[i][j];

	int mk = m+1;
	vi ma;
	REP(i, n-1) {
		vii incs;
		REP(j, m)
			incs.eb(A[j][i] - A[j][n-1], j);
		sort(all(incs));
		int k = 0, s = 0;
		REP(j, m) s += A[j][i] - A[j][n-1];

		vi a;
		while (k < m && s < 0) {
			s -= incs[k].x;
			a.pb(incs[k].y);
			k++;
		}
		assert(s >= 0);

		if (k < mk) {
			mk = k;
			ma = a;
		}
	}

	cout << mk << endl;
	for (int x : ma) cout << x+1 << " ";
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