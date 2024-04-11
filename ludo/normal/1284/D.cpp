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

const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

// lambda-expression: [] (args) -> retType { body }

struct event {
	int time, idx;
	bool add;
};

bool operator<(event a, event b) {
	if (a.time != b.time) return a.time < b.time;
	// first add, then remove!
	if (a.add != b.add) return a.add;
	return false;
}

bool happy(const vii &A, const vii &B) {
	int n = sz(A);

	// make events
	vector<event> evts;
	REP(i, n) {
		evts.pb({A[i].x, i, true});
		evts.pb({A[i].y, i, false});
	}

	set<int> sact, eact;
	sort(all(evts));
	int nact = 0;
	
	for (const event &e : evts) {
		int i = e.idx;

		if (!e.add) {
			sact.erase(B[i].x);
			eact.erase(B[i].y);
			nact--;
		}

		auto it1 = eact.lower_bound(B[i].x);
		auto it2 = sact.upper_bound(B[i].y);

		if (nact > 0 && (
				(it1 != eact.begin() && *(--it1) < B[i].y) ||
				(it2 != sact.end() && *it2 > B[i].x)
			)) {

			/* fprintf(stderr, "%d overlaps at t=%d\n", i, e.time);
			for (int j : sact)
				fprintf(stderr, "%d ", j);
			fprintf(stderr, " are active\n"); */
			return false;
		}

		if (e.add) {
			sact.insert(B[i].x),
			eact.insert(B[i].y);
			nact++;
		}
	}
	return true;
}

bool run() {
	int n;
	cin >> n;
	vii A(n), B(n);
	REP(i, n) {
		cin >> A[i].x >> A[i].y;
		cin >> B[i].x >> B[i].y;
	}

	/* set<int> vals;
	REP(i, n) vals.insert(A[i].x), vals.insert(A[i].y);
	vi v(all(vals));
	REP(i, n) {
		A[i].x = lower_bound(all(v), A[i].x) - v.begin();
		A[i].y = lower_bound(all(v), A[i].y) - v.begin();
	}

	vals.clear();
	v.clear();
	REP(i, n) vals.insert(B[i].x), vals.insert(B[i].y);
	v = vi(all(vals));
	REP(i, n) {
		B[i].x = lower_bound(all(v), B[i].x) - v.begin();
		B[i].y = lower_bound(all(v), B[i].y) - v.begin();
	} */

	// REP(i, n) fprintf(stderr, " [%d, %d] ; [%d, %d]\n", A[i].x, A[i].y, B[i].x, B[i].y);


	// A,B normalized.
	return happy(A, B) && happy(B, A);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	bool ans = run();
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}