#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e5 + 10;
int n,q;
char s[maxn];

int dp[maxn << 2][6]; // a b c ab bc abc
void push_up(int rt) {
	int ls = rt << 1, rs = rt << 1 | 1;
	dp[rt][0] = dp[ls][0] + dp[rs][0];
	dp[rt][1] = dp[ls][1] + dp[rs][1];
	dp[rt][2] = dp[ls][2] + dp[rs][2];
	dp[rt][3] = min(dp[ls][0] + dp[rs][3], dp[ls][3] + dp[rs][1]);
	dp[rt][4] = min(dp[ls][1] + dp[rs][4], dp[ls][4] + dp[rs][2]);
	dp[rt][5] = min(min(dp[ls][0] + dp[rs][5], dp[ls][5] + dp[rs][2]), dp[ls][3] + dp[rs][4]);
}

void build(int rt, int l, int r) {
	if(l == r) {
		for(int i = 0; i < 3; ++i) dp[rt][i] = (s[l] == 'a' + i);
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	push_up(rt);
}

void upd(int rt, int l, int r, int pos) {
	if(l == r) {
		for(int i = 0; i < 3; ++i) dp[rt][i] = (s[l] == 'a' + i);
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) upd(rt << 1, l, mid, pos);
	else upd(rt << 1 | 1, mid + 1, r, pos);
	push_up(rt);
//	printf("%d[%d, %d]:\n", rt, l, r);
//	for(int i = 0; i < 6; ++i) printf("%d%c", dp[rt][i], " \n"[i == 5]);
}

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	build(1, 1, n);
	while(q--) {
		int pos; char ch;
		scanf("%d %c", &pos, &ch);
		s[pos] = ch;
		upd(1, 1, n, pos);
		printf("%d\n", dp[1][5]);
	}
	return 0;
}