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

template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
};

const ll mod = 998'244'353LL;

void run() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll res = 1LL, sum = 0LL;
	int lpos = -1;
	for (int i=0; i<n; i++) {
		int p;
		scanf("%d", &p);

		if (p > n-k) {
			if (lpos >= 0) {
				// cerr << lpos << " - " << i << endl;
				int mul = i - lpos;
				res = (res * mul) % mod;
			}

			sum += p;
			lpos = i;
		}
	}
	printf("%lld %lld\n", sum, res);
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	run();
	return 0;
}