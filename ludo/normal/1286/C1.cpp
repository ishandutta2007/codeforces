#include<bits/stdc++.h>
using namespace std;

// Order statistics tree (if supported by judge!):
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<class TK, class TM> using order_tree = tree<TK, TM, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
// iterator	find_by_order(int r) (zero based)
// int		order_of_key(TK v)
// template<class TV> using order_set = order_tree<TV, null_type>;

#define x first
#define y second
#define rs resize
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ii> vii;
template<class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

template<class T1, class T2>
ostream& operator<<(ostream &out, const pair<T1,T2> &a) { return out << '(' << a.x << ", " << a.y << ')'; }
template<class T1, class T2>
istream& operator>>(istream &in, pair<T1,T2> &a) { return in >> a.x >> a.y; }

template<class T> int sz(const vector<T> &v) { return (int) v.size(); }

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

// lambda-expression: [] (args) -> retType { body }

string test;
int n;

vector<vector<string>> query(int l, int r) {
	int nrs = (r-l+1) * (r-l+2) / 2;
	vector<string> S(nrs);
#ifdef DEBUG
	int ix = 0;
	for (int L = l; L <= r; L++) {
		for (int R = L; R <= r; R++) {
			S[ix++] = test.substr(L, R-L+1);
		}
	}
#else
	printf("? %d %d\n", l+1, r+1);
	fflush(stdout);
	REP(i, nrs) cin >> S[i];
#endif

	vector<vector<string>> ret(r-l+2);
	for (string &s : S) sort(all(s));
	for (const string &s : S) ret[s.size()].pb(s);

	return ret;
}

vector<int> analyze(const vector<vector<string>> &v) {
	vector<int> w(v.size());
	for (int i=0; i<v.size(); i++) {
		w[i] = 0;
		for (const string &s : v[i]) {
			for (char c : s) w[i] += (c - 'a');
		}
	}
	return w;
}

void stop(string &ans) {
	printf("! %s\n", ans.c_str());
	fflush(stdout);
#ifdef DEBUG
	assert(ans == test);
#endif
}

void run() {
#ifdef DEBUG
	n = (int) test.size();
#else
	cin >> n;
#endif

	string ans(n, 'X');
	if (n <= 3) {
		REP(i, n) {
			auto v = query(i, i);
			// cout << v << endl;
			ans[i] = v[1][0][0];
		}
	} else {
		int mid = n/2;

		vi A = analyze(query(0, mid-1));
		vi B = analyze(query(1, mid-1));
		int lsum = 0;
		for (int i=0; i<mid; i++) {
			int cur = A[i+1] - (i == mid-1 ? 0 : B[i+1]);
			ans[i] = 'a' + (cur - lsum);
			lsum = cur;
		}

		cerr << "  " << ans << " " << n << " " << mid << endl;

		vi C = analyze(query(0, n-1));
		int sub = 0;
		for (int i = mid; i < n; i++) {
			if (n % 2 == 0) sub += ans[mid+mid-i-1] - 'a';

			// determine ans[i]
			int diff = C[n-i] - (n==i-1 ? 0 : C[n-i-1]);

			cerr << diff << "/" << sub << " ";
			// cerr << (diff - sub) << " ";

			ans[i] = 'a' + (diff - sub);

			sub = diff;
			if (n % 2 == 1) sub += ans[mid+mid-i-1] - 'a';
		}
		cerr << endl;
	}
	stop(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

#ifdef DEBUG
	// test = "abcdabcd";
	// test = "cbaaasdlkqwerpiouzcblkjzxbmnwebrkqjweiuyzxcb";
	test = "abc";
#endif

	run();

	return 0;
}