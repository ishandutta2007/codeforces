#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
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
#define MAXN 200005
#define MAXK 20

int n;
int a[MAXN];
int sparse[MAXN][MAXK + 5], id[MAXN][MAXK + 5];

ii getMin(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	int fi = l, se = r - (1 << k) + 1;
	if (sparse[fi][k] < sparse[se][k]) {
		return MP(sparse[fi][k], id[fi][k]);
	} else {
		return MP(sparse[se][k], id[se][k]);
	}
}

int dp(int l, int r, int minus) {
	if (r < l) return 0;
	ii curMin = getMin(l, r);
	int mn = curMin.FI, mid = curMin.SE;
// 	REP (i, l, r + 1) {
// 		if (a[i] <= mn) {
// 			mn = a[i];
// 			mid = i;
// 		}
// 	}
	int res = (mn - minus) + dp(l, mid - 1, mn) + dp(mid + 1, r, mn);
	mnto(res, r - l + 1);
	return res;
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		sparse[i][0] = a[i];
		id[i][0] = i;
	}
	REP (k, 1, MAXK) {
		REP (i, 0, n) {
			sparse[i][k] = INF;
		}
	}
	REP (k, 1, MAXK) {
		REP (i, 0, n - (1 << k - 1)) {
			int l = i, r = i + (1 << k - 1);
			if (sparse[l][k - 1] < sparse[r][k - 1]) {
				sparse[i][k] = sparse[l][k - 1];
				id[i][k] = id[l][k - 1];
			} else {
				sparse[i][k] = sparse[r][k - 1];
				id[i][k] = id[r][k - 1];
			}
		}
	}
	printf("%d\n", dp(0, n - 1, 0));
	return 0;
}