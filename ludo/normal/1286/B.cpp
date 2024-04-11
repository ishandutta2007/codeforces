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

vi child[2001];
int rnk[2001], ans[2001] = {};

// returns number of children in subtree
vi dfs(int u, int from) {
	// cerr << "DFS " << u << " " << from << endl;
	vi cols = {};
	for (int v : child[u]) {
		vi inc = dfs(v, from);
		for (int c : inc) cols.pb(c);

		from += inc.size();
	}

	if (rnk[u] > cols.size()) {
		cout << "NO\n";
		exit(0);
	}

	for (int i = rnk[u]; i < cols.size(); i++) {
		ans[ cols[i] ]++;
	}

	ans[ u ] = from - cols.size() + rnk[u];
	cols.insert(cols.begin() + rnk[u], u);

	// determine the k'th value
	return cols;
}

void run() {
	int n;
	cin >> n;
	vi p(n);
	REP(i, n) {
		cin >> p[i] >> rnk[i];
		p[i]--;
		child[p[i]].pb(i);
	}

	REP(i, n) if (p[i] == -1) {
		assert(dfs(i, 1).size() == n);
	}

	cout << "YES" << endl;
	REP(i, n) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	run();

	return 0;
}