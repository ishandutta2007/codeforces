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
	string s;
	cin >> s;
	vector<char> A;
	vi B;
	for (ll i = 0; i < s.size(); i++) {
		ll c = 1;
		A.pb(s[i]);
		while (i+1 < s.size() && s[i+1] == s[i]) {
			c++;
			i++;
		}
		B.pb(c);
	}
	if (B.size()%2 == 0) {
		cout << 0 << endl;
		return;
	}
	for (ll i = 0; i < A.size()/2; i++) {
		if (A[i] != A[A.size()-1-i] || B[i] + B[A.size()-1-i] < 3) {
			cout << 0 << endl;
			return;
		}
	}
	if (B[A.size()/2] < 2) {
		cout << 0 << endl;
		return;
	}
	ll res = B[A.size()/2]+1;
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