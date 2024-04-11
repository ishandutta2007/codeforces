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

map<int, int> nr;

// n[x] = number of sizes with at least x planks.
int n[10];

void add_plank(int l, int inc = 1) {
	if (inc == 1) {
		int count = ++nr[l];
		if (count < 10) n[count]++;
	} else {
		int count = nr[l]--;
		if (count < 10) n[count]--;
	}
}

bool can() {
	if (n[8] != 0) return true;
	if (n[6] != 0 && n[2] >= 2) return true;
	if (n[4] >= 2) return true;
	if (n[4] != 0 && n[2] >= 3) return true;
	return false;

	// return n[8] >= 1 || n[4] >= 2 || (n[4] && n[2] >= 2) || (n[6] && n[2]);
}

void run() {
	int q, l;
	cin >> q;
	while (q--) {
		cin >> l;
		add_plank(l);
	}
	cin >> q;
	while (q--) {
		char op;
		cin >> op >> l;
		add_plank(l, op == '-' ? -1 : 1);
		cout << vector<string>{"NO","YES"}[can()] << endl;
	}
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}