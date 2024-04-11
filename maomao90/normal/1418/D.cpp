#include <bits/stdc++.h>
using namespace std;

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
#define MAXN 100005

int n, q;
int a[MAXN];
set<int> trash;
multiset<int, greater<int> > gaps;

int main() {
	scanf("%d%d", &n, &q);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		trash.insert(a[i]);
	}
	sort(a, a + n);
	REP (i, 1, n) {
		gaps.insert(a[i] - a[i - 1]);
	}
	if (trash.size() <= 1) printf("0\n");
	else {
		int diff = *prev(trash.end()) - *trash.begin();
		printf("%d\n", diff - *gaps.begin());
	}
	REP (i, 0, q) {
		int t, x; scanf("%d%d", &t, &x);
		if (t == 0) {
			if (trash.size() != 1) {
				auto cur = trash.lower_bound(x);
				assert(*cur == x);
				if (cur == trash.begin()) {
					auto nxt = next(cur);
					gaps.erase(gaps.find(*nxt - *cur));
				} else if (next(cur) == trash.end()) {
					auto prv = prev(cur);
					gaps.erase(gaps.find(*cur - *prv));
				} else {
					auto prv = prev(cur), nxt = next(cur);
					gaps.erase(gaps.find(*nxt - *cur));
					gaps.erase(gaps.find(*cur - *prv));
					gaps.insert(*nxt - *prv);
				}
			}
			trash.erase(x);

		} else {
			auto lower = trash.lower_bound(x);
			int prv = -1, nxt = -1;
			if (lower != trash.begin()) prv = *(prev(lower));
			if (lower != trash.end()) nxt = *lower;
			if (prv != -1) {
				gaps.insert(x - prv);
			}
			if (nxt != -1) {
				gaps.insert(nxt - x);
			}
			if (prv != -1 && nxt != -1) {
				gaps.erase(gaps.find(nxt - prv));
			}
			trash.insert(x);
		}
		if (trash.size() <= 1) printf("0\n");
		else {
			int diff = (*prev(trash.end())) - (*trash.begin());
			printf("%d\n", diff - *gaps.begin());
		}
	}
	return 0;
}