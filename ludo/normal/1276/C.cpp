#include<bits/stdc++.h>
using namespace std;

// Order statistics tree (if supported by judge!):
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TK, class TM> using order_tree =
	tree<TK, TM, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
// iterator	find_by_order(int r) (zero based)
// int		order_of_key(TK v)
template<class TV> using order_set = order_tree<TV, null_type>;

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
typedef vector<vi> vvi;
typedef vector<ii> vii;
template<class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

template<class T1, class T2>
ostream& operator<<(ostream &out, const pair<T1,T2> &a) { return out << '(' << a.x << ", " << a.y << ')'; }
template<class T1, class T2>
istream& operator>>(istream &in, pair<T1,T2> &a) { return in >> a.x >> a.y; }

const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

// lambda-expression: [] (args) -> retType { body }

bool canmake(int w, int h, const vii &cnt) {
	// w <= h
	int has = 0;
	for (ii pr : cnt) {
		has += min(pr.x, w);
	}
	return has >= w*h;
}

void print_sol(int w, int h, const vii &cnt) {
	int printed = 0;

	vvi A(w, vi(h, -1));

	for (ii pr : cnt) {
		int take = min(pr.x, w);
		if (printed + take > w*h)
			take = w*h - printed;

		for (int i = 0; i < take; i++) {
			int ix = (printed + i);
			int col = ix / w, row = ix - w*col;

			col = (col + row) % h;

			A[row][col] = pr.y;
		}

		printed += take;
		if (printed == w*h) break;
	}
	assert(printed == w*h);

	printf("%d\n%d %d\n", w*h, w, h);

	REP(i, w) REP(j, h) printf("%d%c", A[i][j], " \n"[j==h-1]);
}

void run() {
	int n;
	cin >> n;
	vi v(n);
	for (int &x:v) cin >> x;
	sort(all(v));

	vii cnt;

	int lx = v.front(), ccnt = 0;
	for (int x : v) {
		if (x != lx) cnt.eb(ccnt, lx), ccnt = 0;
		lx = x;
		ccnt++;
	}
	cnt.eb(ccnt, lx);

	sort(all(cnt));
	reverse(all(cnt));

	/* for (int x: v) cout << x << " ";
	cout << endl;
	for (ii x: cnt) cout << "(" << x.x << ", " << x.y << ") ";
	cout << endl; */

	int m = n;
	while (true) {
		for (int f = 1; f*f <= m; f++) {
			if (m % f != 0) continue;
			int g = m/f;

			// m = f*g
			if (canmake(f,g, cnt)) {
				print_sol(f,g, cnt);
				return;
			}
		}
		m--;
	}
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