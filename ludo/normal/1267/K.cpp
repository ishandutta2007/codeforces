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

// using __int128 = unsigned long long;
#define __int128 unsigned long long

/* ostream& operator<<(ostream &out, __int128 x) {
	ll y = x;
	return out << y;
} */

__int128 calc(vi v) {
	int n = sz(v);

	__int128 div = 1;
	for (int i = 1, c = 1; i <= n; i++) {
		div *= c;
		if (i == n || v[i] != v[i-1]) {
			c = 1;
			continue;
		}
		c++;
	}

	__int128 prod = 1;
	int ways = 0, pos = 0;
	REP(i, n) {
		while (pos < n && v[pos] <= i+1) pos++, ways++;
		prod *= ways;
		ways--;
	}
	// cerr << prod << " / " << div << " " << (prod / div) << endl;
	return prod / div;
}

ll run(ll x) {
	vi rs;
	for (int i = 2; x != 0; i++) {
		rs.pb(x % i);
		x /= i;
	}

	sort(all(rs));
	// for (auto pr : A) cout << pr.x << ", " << pr.y << endl;

	__int128 cnt = calc(rs);
	if (rs[0] == 0) {
		rs.erase(rs.begin());
		cnt -= calc(rs);
	}
	return cnt;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		ll ans = run(x);
		cout << (ans-1LL) << endl;
	}
	return 0;
}