#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int N, K, A[1<<17];
int dp[1<<18][2][2];
const int INF = 1e9;

void Do(int rt, int l, int r) {
	rep(v, 2) rep(w, 2) dp[rt][v][w] = -INF;
	if(r-l == 1) {
		int c = A[l] + A[r];
		if(c == 0) {
			dp[rt][0][0] = 0;
		}
		else if(c == 1) {
			dp[rt][0][1] = dp[rt][1][0] = 1;
		}
		else {
			dp[rt][1][1] = 1;
		}
		return;
	}
	int m = (l + r) >> 1;
	Do(rt * 2, l, m);
	Do(rt * 2 + 1, m+1, r);
	auto upd = [&](int &x, int y) {
		if(x < y) x = y;
	};
	auto D1 = dp[rt*2], D2 = dp[rt*2+1];
	rep(a, 2) rep(b, 2) rep(c, 2) rep(d, 2) {
		if(D1[a][b] == INF || D2[c][d] == INF) continue;
		rep(x, 2) rep(y, 2) rep(z, 2) {
			int wa = (x ? a : c);
			int la = (x ? c : a);
			int wb = (y ? b : d);
			int wc = (z ? la : wb);
			int val = D1[a][b] + D2[c][d];
			if(a|c) ++val;
			if(b|d) ++val;
			if(la|wb) ++val;
			upd(dp[rt][wa][wc], val);
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	rep(k, K) {
		int x; scanf("%d", &x);
		--x;
		A[x] = 1;
	}
	Do(1, 0, (1<<N) - 1);
	int ans = 0;
	rep(a, 2) rep(b, 2) ans = max(ans, dp[1][a][b] + (a|b));
	printf("%d\n", ans);
	return 0;
}