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

const string content[] = {
	"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

string line[2001];

// 0: not possible
// i: digit i-1 possible (1 <= i <= 10)
int poss[2001][2001] = {};

int reqs(int d, string &s) {
	int res = 0;
	REP(i, 7) {
		if (content[d][i] == s[i]) continue;
		if (s[i] == '1') // content[d][i] niet
			return -1;
		else res++;
	}
	return res;
}

void run() {
	int n, k;
	cin >> n >> k;

	REP(i, n) {
		cin >> line[i];
	}

	poss[n][0] = 1; // fake.

	for (int i=n-1; i >= 0; i--) {
		for (int dig = 9; dig >= 0; dig--) {
			int inc = reqs(dig, line[i]);
			if (inc < 0) continue;
			// cerr << "At pos " << i << ": " << dig << " - " << inc << endl;
			for (int kv = inc; kv <= k; kv++) {
				if (poss[i][kv] != 0) continue;
				if (poss[i+1][kv - inc] != 0) {
					poss[i][kv] = dig+1;
					//fprintf(stderr, "poss[%d][%d] = %d\n", i, kv, dig);
				}
			}
		}
	}

	if (poss[0][k] == 0) {
		puts("-1"); return;
	}

	REP(i, n) {
		int d = poss[i][k] - 1;
		k -= reqs(d, line[i]);
		printf("%d", d);
	}
	printf("\n");

}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}