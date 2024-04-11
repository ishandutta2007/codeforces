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
typedef pair<ll, ll> pt;

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

int sgn(ll x) { return (x>0) - (x<0); }
//    B
//   /     ?
// O --- A
bool left_of(pt a, pt b) { return a.x*b.y > a.y*b.x; }
pt operator-(pt p) { return pt(-p.x, -p.y); }
pt operator-(pt a, pt b) { return pt(a.x-b.x, a.y-b.y); }

// return #{ fr<=i<=to | cmp P[i] left of cmp }
ll nr_left_of(const vector<pt> &P, int fr, int to, pt cmp) {
	int lo = fr-1, hi = to+1;
	while (hi - lo > 1) {
		int m = (lo+hi) / 2;
		if (left_of(cmp, P[m])) lo = m;
		else hi = m;
	}
	return hi - fr; // [fr, fr+1, ..., lo]
}

ll triangles_with_origin(vector<pt> &P) {
	// sort points by orientation around origin (0,0).
	sort(all(P), [] (pt a, pt b) -> bool {
		int s1 = sgn(a.y), s2 = sgn(b.y);
		if (s1 == 0 && a.x > 0) s1 = 2;
		if (s2 == 0 && b.x > 0) s2 = 2;
		return s1 != s2 ? s1 > s2 : left_of(a, b);
	});

	int n = sz(P), i = 0, j = 1;
	REP(k, n) P.pb(P[k]);

	while (j < n && left_of(P[i], P[j])) j++;

	ll count = 0, ans = 0;
	// number of good positions:
	for (int k = 1; k < j; k++)
		count += nr_left_of(P, j, n-1, P[k]);

	while (i < n) {
		int a = j-i-1, oldj = j;
		i++;
		while (j < n+i && left_of(P[i], P[j])) j++;
		int b = n+i - j;
		count += (j - oldj) * (b-a);
		ans += count;
	}

	// returns number of triangles
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	int n;
	cin >> n;
	assert(n >= 5);

	vector<pt> P(n);
	REP(i, n) cin >> P[i].x >> P[i].y;

	ll sum = 0;
	REP(i, n) {
		pt origin = P[i];

		// do some work
		vector<pt> Q(n-1);
		REP(j, n) {
			if (j != i) Q[j - (j >= i)] = P[j] - origin;
		}
		sum += triangles_with_origin(Q);
	}

	// cerr << sum << endl;

	sum *= (n-4);
	assert(sum % 6 == 0);
	sum /= 6;

	cout << sum << endl;
	return 0;
}