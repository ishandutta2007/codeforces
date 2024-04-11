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

struct M {
	ll a, b, t;
};

bool operator<(M a, M b) {
	if (a.t != b.t) {
		return a.t < b.t;
	} else if (a.a != b.a) {
		return a.a < b.a;
	} else {
		return a.b < b.b;
	}
}

void run() {
	ll n;
	cin >> n;
	
	vector<pair<ll,M>> starts;
	vector<pair<ll,M>> ends;
	set<M> times;
	
	for (ll i = 0; i < n; i++) {
		ll a, b, t;
		cin >> a >> b >> t;
		M m {a,b,t};
		starts.eb(a, m);
		ends.eb(b-t,m);
	}
	sort(all(starts));
	sort(all(ends));
	
	ll si= 0, ei = 0, st = starts[0].x;
	ll res = 0;
	while (si < starts.size() || ei < ends.size()) {
		//cout << si << ", " << ei << ", " << st << endl;
		if (si < starts.size() && (ei == ends.size() || starts[si].x <= ends[ei].x) && starts[si].x <= st) {
			times.insert(starts[si].y);
			st = min(st, starts[si].y.a+starts[si].y.t);
			si++;
		} else if (ei == ends.size() || st <= ends[ei].x) {
			if (times.size() == 0) {
				st = starts[si].x;
				continue;
			}
			M m = *times.begin();
			ll count = (m.b-st)/m.t;
			if (si < starts.size()) {
				count = min(count, (starts[si].x-st+m.t-1)/m.t);
			}
			res += count;
			st += count*m.t;
		} else {
			times.erase(ends[ei].y);
			ei++;
		}
	}
	cout << res << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}