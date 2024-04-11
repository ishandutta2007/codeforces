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

vi E[100'000];

bool inDepth[2] = { false, false };
int rt, RET = 0;

bool dfs(int u, int v, int d) {
	if (E[v].size() == 1 && v != rt) {
		// leaf!

		inDepth[d%2] = true;

		return true;
	}

	bool sawLeaf = (v != rt && u == rt);

	for (int w : E[v]) if (u != w) {
		if (dfs(v, w, d+1)) {
			if (sawLeaf) {
				// do nothing
			} else {
				sawLeaf = true;
				RET++;
			}
		} else RET++;
	}

	return false;
}

void run() {
	int n;
	cin >> n;
	REP(i, n-1) {
		int a, b;
		cin >> a >> b;
		E[--a].pb(--b);
		E[b].pb(a);
	}

	rt = 0;
	while (E[rt].size() != 1) rt++;

	dfs(rt, rt, 0);

	// print min nr.
	if (!inDepth[1])
		printf("1 ");
	else
		printf("3 ");

	// print max nr.
	printf("%d\n", RET);
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}