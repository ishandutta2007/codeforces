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
#define MAXN 200005

int n, k;
int a[MAXN];

int on[MAXN];
bool isPos(int x) {
	REP (i, 1, n + 1) {
		on[i] = a[i] < x ? -1 : 1;
		on[i] += on[i - 1];
	}
	int mn = INF;
	int res = -INF;
	REP (i, k, n + 1) {
		mnto(mn, on[i - k]);
		mxto(res, on[i] - mn);
	}
	return res >= 1;
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]); 
	}
	int lo = 1, hi = INF, mid;
	while (lo < hi) {
		mid = (ll) lo + hi + 1 >> 1;
		if (isPos(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	printf("%d\n", lo);
	return 0;
}