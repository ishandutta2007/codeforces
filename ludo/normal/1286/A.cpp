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

int bestfill(vi be, vi bo, int ne, int no) {
	if (ne < 0 || no < 0) return 10000;

	int cost = 0;
	for (int x : be) {
		if (x <= ne) ne -= x;
		else cost++;
	}
	for (int x : bo) {
		if (x <= no) no -= x;
		else cost++;
	}
	return cost + cost;
}

int run() {
	int n;
	cin >> n;
	vi v(n);
	for (int &x : v) cin >> x;

	int ne = n/2, no = (n+1)/2, cost = 0;
	for (int i=0; i < n; i++) {
		if (v[i] == 0) continue;
		if (v[i] % 2 == 0) ne--;
		else no--;
	}

	vi be, bo;
	for (int i=1; i<n; i++) {
		if (v[i] && v[i-1] && (v[i]%2) != (v[i-1]%2)) {
			cost++;
		}

		if (v[i-1] != 0 && v[i] == 0) {
			int j = i;
			while (j < n && v[j] == 0) j++;
			if (j == n) continue;

			if ((v[i-1]%2) == (v[j]%2)) {
				// cost 2 or 0
				if (v[i-1]%2 == 0) be.pb(j-i);
				else bo.pb(j-i);
			} else {
				// no matter what, cost = 1
				cost++;
			}
		}
	}

	sort(all(be));
	sort(all(bo));

	int len_l = 0;
	while (len_l < n && v[len_l] == 0) len_l++;

	int len_r = 0;
	while (len_r < n && v[n-1-len_r] == 0) len_r++;

	if (len_l == n) return (n >= 2); // only XXXX

	// cerr << len_l << " " << len_r << " " << cost << " " << ne << " " << no << " " << be << " " << bo << endl;
	int xl = v[len_l]%2, xr = v[n-1-len_r]%2;

	int extra = bestfill(be, bo, ne, no) + (len_l != 0) + (len_r != 0);
	extra = min(extra, (len_r != 0) + bestfill(be, bo, ne - len_l*(1-xl), no - len_l*(xl)));
	extra = min(extra, (len_l != 0) + bestfill(be, bo, ne - len_r*(1-xr), no - len_r*(xr)));
	extra = min(extra, bestfill(be, bo, ne - len_l*(1-xl) - len_r*(1-xr), no - len_l*(xl) - len_r*(xr)));

	return cost + extra;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	int ans = run();
	cout << ans << endl;

	return 0;
}