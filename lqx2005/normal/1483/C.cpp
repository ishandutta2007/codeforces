#include<bits/stdc++.h>
 
using namespace std;
 
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
 
template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
typedef pair<int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 5e5 + 10, inf = 0x3f3f3f3f;
int n, a[N], b[N];
P mn[N];
LL dp[N];

void solve(int l, int r) {
	if(l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid);
	mn[mid + 1] = mp(a[mid + 1], b[mid + 1]);
	rep(i, mid + 2, r) mn[i] = min(mn[i - 1], mp(a[i], b[i]));
	mn[mid] = mp(inf, -inf);
	per(i, mid - 1, l) mn[i] = min(mn[i + 1], mp(a[i + 1], b[i + 1]));
	int now = mid + 1;
	LL v = -1e18;
	rep(i, mid + 1, r) {
		while(now - 1 >= l && mn[now - 1] > mn[i]) now--, ckmax(v, dp[now]);
		ckmax(dp[i], v + mn[i].y);
	}
	now = l - 1, v = -1e18;
	per(i, r, mid + 1) {
		while(now + 1 <= mid && mn[now + 1] < mn[i]) now++, ckmax(v, dp[now] + mn[now].y);
		ckmax(dp[i], v);
	}
	solve(mid + 1, r);
	return;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	memset(dp, 0xc0, sizeof(dp));
	dp[0] = 0;
	solve(0, n);
	printf("%lld\n", dp[n]);
	return 0;
}