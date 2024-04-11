#include <bits/stdc++.h>
using namespace std;

#define mnto(a, b) a = min(a, (__typeof__(a)) b)
#define mxto(a, b) a = max(a, b)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
#define pb emplace_back
typedef vector<int> vi;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
#define MT make_tuple
typedef tuple<int, int, int> iii;

#define LINF 10000000000000005
#define MAXN 300005

int n[3];
int a[3][MAXN];
ll ans;

int main() {
	REP (i, 0, 3) scanf("%d", &n[i]);
	REP (i, 0, 3) {
		REP (j, 0, n[i]) {
			scanf("%d", &a[i][j]);
			ans += a[i][j];
		}
	}
	ll mn = LINF, mnn = LINF;
	REP (i, 0, 3) {
		ll curMin = LINF;
		REP (j, 0, n[i]) {
			mnto(curMin, a[i][j]);
		}
		if (curMin <= mn) {
			mnn = mn;
			mn = curMin;
		} else if (curMin < mnn) {
			mnn = curMin;
		}
	}
	ll minus = mn + mnn;
	mn = LINF;
	REP (i, 0, 3) {
		ll sum = 0;
		REP (j, 0, n[i]) {
			sum += a[i][j];
		}
		mnto(mn, sum);
	}
	mnto(minus, mn);
	ans -= minus * 2;
	printf("%lld\n", ans);
	return 0;
}