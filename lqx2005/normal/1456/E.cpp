#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;
const int N = 52;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int n, k;
ll a[N][2];
ll f[N][N][N][2][2][2][2];
ll c[N];

void chkmin(ll &x, ll y) {
	if(x > y) x = y;
}

ll DP(int l, int r, int d, int p, int q, int s, int t) {
	if(d >= k) return 0;
	int ls = (a[l][p] >> d & 1) ^ q, rs = (a[r][s] >> d & 1) ^ t;
	ll cost = (l == 0 || r == n + 1) ? 0 : c[d] * (ls ^ rs);
	ll &res = f[l][r][d][p][q][s][t];
	if(res < oo) return res;
	int flag = 0;
	res = oo - 1;
	for(int i = l + 1; i < r; i++) {
		flag |= ((a[i][0] >> (d + 2)) == (a[i][1] >> (d + 2)));
		if((a[i][0] >> (d + 1)) != (a[i][1] >> (d + 1))) {
			if(~a[i][0] >> d & 1) chkmin(res, DP(l, i, d, p, q, 0, 1) + DP(i, r, d, 0, 1, s, t));
			if(a[i][1] >> d & 1) chkmin(res, DP(l, i, d, p, q, 1, 1) + DP(i, r, d, 1, 1, s, t));
		}
		if(d == 0) {
			chkmin(res, DP(l, i, d, p, q, 0, 0) + DP(i, r, d, 0, 0, s, t));
			chkmin(res, DP(l, i, d, p, q, 1, 0) + DP(i, r, d, 1, 0, s, t));
		}
	}
	if(!flag) chkmin(res, DP(l, r, d + 1, p, 0, s, 0) + cost);
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &a[i][0], &a[i][1]);
	for(int i = 0; i < k; i++) scanf("%lld", &c[i]);
	memset(f, 0x3f, sizeof(f));
	printf("%lld\n", DP(0, n + 1, 0, 0, 0, 0, 0));
	return 0;
}