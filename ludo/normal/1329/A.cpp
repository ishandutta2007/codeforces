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

bool run() {
	int n, m;
	cin >> n >> m;
	vi l(m), p(m);
	for (ll &x : l) cin >> x;

	ll sl = accumulate(all(l), 0LL);
	if (sl < n) return false;
	// if (l.back() + (m-1) > n) return false;

	ll lpos = 0;
	REP(i, m) {
		ll len = l[i];
		p[i] = max(lpos + 1LL, n - sl + 1);
		if (p[i] + len - 1 > n) {
			return false;
		}
		sl -= len;
		lpos = p[i];
	}

	for (ll pos : p)
		cout << pos << " ";
	cout << endl;
	return true;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	if (!run())
		puts("-1");
	return 0;
}