#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 5005

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct line {
	int x1, y1, x2, y2;
	bool isVert() {
		return x1 == x2;
	}
	bool operator< (const line& o) const {
		return x1 < o.x1;
	}
};

typedef tree<line, null_type, less<line>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

bool comp(line l, line r) {
	return l.y2 < r.y2;
}

int n;
vector<line> hor, ver;
ll ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (y1 > y2) swap(y1, y2);
		if (x1 > x2) swap(x1, x2);
		line cur = {x1, y1, x2, y2};
		if (cur.isVert()) {
			ver.pb(cur);
		} else {
			hor.pb(cur);
		}
	}
	sort(ALL(hor), comp);
	sort(ALL(ver), comp);
	REP (i, 0, hor.size()) {
		line tp = hor[i];
		vector<line> tmp;
		//printf("%d: %d %d %d %d\n", i, tp.x1, tp.x2, tp.y1, tp.y2);
		REP (j, 0, ver.size()) {
			if (ver[j].y1 <= tp.y1) {
				tmp.pb(ver[j]);
				//printf(" %d %d %d %d\n", ver[j].x1, ver[j].x2, ver[j].y1, ver[j].y2);
			}
		}
		int ptr = tmp.size() - 1;
		indexed_set st;
		RREP (j, hor.size() - 1, i + 1) {
			//printf("  %d %d %d %d\n", hor[j].x1, hor[j].x2, hor[j].y1, hor[j].y2);
			while (ptr >= 0 && tmp[ptr].y2 >= hor[j].y2) {
				//printf("    %d\n", ptr);
				st.insert(tmp[ptr--]);
			}
			int lft = max(tp.x1, hor[j].x1), rht = min(tp.x2, hor[j].x2);
			int lower = st.order_of_key({lft, 0, lft, 0}), 
				upper = st.order_of_key({rht + 1, 0, rht + 1, 0}) - 1;
			int tmp = upper - lower + 1;
			if (tmp > 1) ans += tmp * (tmp - 1) / 2;
			//printf("     %d %d\n", upper, lower);
		}
	}
	printf("%lld\n", ans);
	return 0;
}