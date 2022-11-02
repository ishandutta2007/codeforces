#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
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

// ------------------------------------------------------------------------------
int h, g, v[1<<20];

vi getpath(int i) {
	vi res = { i };
	while (v[i] != 0 && 2*i < (1<<h)) {
		i *= 2;
		if (v[i+1] > v[i]) i++;
		if (v[i]) res.pb(i);
	}
	return res;
}

void run() {
	cin >> h >> g;
	for (int i=1; i < (1<<h); i++)
		cin >> v[i];

	vi ans;
	for (int i=1, ch=1; i < (1<<g); ) {
		vi path = getpath(i);
		while (sz(path) >= g+2-ch) {
			for (int j=1; j < sz(path); j++)
				v[path[j-1]] = v[path[j]];
			v[path.back()] = 0;
			ans.pb(i);
			path = getpath(i);
		}
		if (++i == (1<<ch)) ch++;
	}
	assert(sz(ans) == (1<<h) - (1<<g));
	ll sum = 0;
	for (int i=1; i < (1<<g); i++)
		sum += v[i];
	printf("%lld\n", sum);
	for (int i : ans) printf("%d ", i);
	printf("\n");
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int ntc;
	cin >> ntc;
	while (ntc--) {
		run();
	}

	return 0;
}