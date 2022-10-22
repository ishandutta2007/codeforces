#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 300005

#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>

int n, m;
int a[MAXN];
int ptr = 0;
int mp[MAXN], mx[MAXN], mn[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, m) {
		scanf("%d", &a[i]);
	}
	ordered_set st;
	REP (i, 1, n + 1) {
		st.insert(MP(i, i));
		mp[i] = i;
		mn[i] = i;
		mx[i] = i;
	}
	REP (i, 0, m) {
		mn[a[i]] = 1;
		mx[a[i]] = max(mx[a[i]], ((int) st.order_of_key(MP(mp[a[i]], a[i])) + 1));
		st.erase(MP(mp[a[i]], a[i]));
		mp[a[i]] = ptr--;
		st.insert(MP(mp[a[i]], a[i]));
	}
	int cnt = 1;
	for (auto &i : st) {
		mxto(mx[i.SE], cnt++);
	}
	REP (i, 1, n + 1) {
		printf("%d %d\n", mn[i], mx[i]);
	}
	return 0;
}