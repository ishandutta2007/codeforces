#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
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
#define MAXN 1005

int t;
int n;
int a[2 * MAXN];
multiset<int> st;
vii ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n * 2) scanf("%d", &a[i]);
		sort(a, a + n * 2, greater<int>());
		bool isPos = 0;
		int fst = -1;
		REP (i, 1, 2 * n) {
			st.clear();
			ans.clear();
			REP (j, 1, 2 * n) {
				if (j == i) continue;
				st.insert(a[j]);
			}
			int x = a[0];
			bool curPos = 1;
			REP (j, 1, 2 * n) {
				if (st.find(a[j]) == st.end()) continue;
				st.erase(st.find(a[j]));
				auto temp = st.lower_bound(x - a[j]);
				int lower = -1;
				if (temp != st.end()) lower = *temp;
				if (lower != x - a[j]) {
					curPos = 0;
					break;
				}
				ans.pb(a[j], lower);
				st.erase(st.find(lower));
				x = a[j];
			}
			if (curPos) {
				isPos = 1;
				fst = a[i];
				break;
			}
		}
		if (!isPos) {
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("%d\n", a[0] + fst);
			printf("%d %d\n", a[0], fst);
			REP (i, 0, ans.size()) {
				printf("%d %d\n", ans[i].FI, ans[i].SE);
			}
		}
		ans.clear();
		st.clear();
	}
	return 0;
}