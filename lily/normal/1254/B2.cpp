#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)
 
#define N 1001111
#define INF LL(1.5e18)
int n;
int a[N], b[N];
LL ans = INF;
 pair<LL, int> c[N];
void check(LL p) {
	LL ret = 0;
	memcpy(b, a, sizeof a);
	for (int i = 1; i <= n; ) {
		LL cur = b[i] % p;
		if (cur) {
			int top = 0;
			cur = 0;
			int j = i;
			for (; ; j++) {
				LL cc = b[j];
				if (j == i) cc %= p;
				if (cur + cc >= p) {
					c[top++] = {p - cur, j};
					b[j] -= int(p - cur);
					break;
				}
				else if (cc) {
					cur += cc;
					c[top++] = {cc, j};
				}
			}
			LL  pp = 0;
			bool flag = 0;
			for (int i = 0; i < top; i++) {
				const auto &v = c[i];
				ret += (flag ? 1  : -1) * v.first * v.second;
				pp += v.first;
				if (!flag && pp >= (p + 1) / 2) ret += (pp - (p - pp)) * v.second, flag = 1;
			}
			i = j;
		}
		else i++;
	}
	ans = min(ans, ret);
}
 
 
int main() {
	read(n);
//	n = 1e6;
	LL cnt = 0;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
//		a[i] = 969969 + (i & 1 ? 1 : -1);
		cnt += a[i];
	}
	for (int i = 2; (LL)i * i  <= cnt; i++) {
		if (cnt % i == 0) {
			while (cnt % i == 0) cnt /= i;
			check(i);
		}
	}
	if (cnt > 1) check(cnt);
	if (ans == INF) printf("-1");
	else printf("%lld\n", ans);
}