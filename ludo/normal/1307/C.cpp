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
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const ld PI = acos(-1.0);

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

char c[100'001];

int occ[26] = {};

ll prod[26][26] = {};

bool run() {
	if (scanf("%s\n", c) != 1) return false;
	// printf("%s\n", c);
	int n = strlen(c);

	REP(i, 26) REP(j, 26) prod[i][j] = occ[i] = 0;

	REP(i, n) {
		REP(j, 26)
			prod[j][c[i] - 'a'] += occ[j];
		occ[c[i] - 'a']++;
	}

	ll ans = *max_element(occ, occ+26);
	REP(i, 26) REP(j, 26)
		ans = max(ans, prod[i][j]);
	
	printf("%lld\n", ans);
	return true;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	while (run()) {
		;
	}
	return 0;
}