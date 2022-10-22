#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 600005

int n, l;
int a[MAXN], tmp[MAXN];
set<ii> b;

int getd(int s, int e) {
	int fi = (e - s + l) % l;
	int se = (s - e + l) % l;
	return min(fi, se);
}

bool isPos(int x) {
	int up = INF, down = -INF;
	REP (i, 0, n) {
		int lo = a[i] - x;
		auto lower = b.lower_bound(MP(lo, 0));
		int lft = -1;
		if (getd(a[i], lower -> FI) > x) {
		   	lft = INF;
		} else {
			lft = lower -> SE;
		}
		int hi = a[i] + x;
		auto upper = prev(b.upper_bound(MP(hi, INF)));
		int rht = -1;
		if (getd(a[i], upper -> FI) > x) {
			rht = -INF;
		} else {
			rht = upper -> SE;
		}
		mxto(down, lft - i);
		mnto(up, rht - i);
	}
	return up >= down;
}

int main() {
	scanf("%d%d", &n, &l);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	REP (i, 0, n) {
		scanf("%d", &tmp[i]);
		tmp[i + n] = tmp[i] - l;
		tmp[i + 2 * n] = tmp[i] + l;
	}
	sort(tmp, tmp + 3 * n);
	REP (i, 0, 3 * n) {
		b.insert(MP(tmp[i], i));
	}
	int lo = 0, hi = l, mid;
	while (lo < hi) {
		mid = lo + hi >> 1;
		if (isPos(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	printf("%d\n", hi);
	return 0;
}