#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
typedef long long ll;
typedef long double ld;
typedef double db;
int n,cnt[3];
ll x[maxn],y[maxn];

bool check(ld R) {
	ld l = -1e7, r = 1e7;
	for(int i = 1; i <= n; ++i) {
		if(R * 2 < y[i]) return 0;
		ld d = sqrt((2 * R - y[i]) * y[i]);
		l = max(l, x[i] - d);
		r = min(r, x[i] + d);
	}
	return l < r;
}

int main() {
	//freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld", &x[i], &y[i]),
		cnt[0] += y[i] < 0, cnt[1] += y[i] > 0, cnt[2] += y[i] == 0;
	if((cnt[0] && cnt[1]) || cnt[2] > 1) return printf("-1\n"), 0;
	if(cnt[0]) {
		for(int i = 1; i <= n; ++i)
			y[i] = -y[i];
	}
	ld l = 0, r = 1.1e14, mid, ans;
	for(int i = 1; i <= 100; ++i) {
		mid = (l + r) / 2;
		if(check(mid)) r = ans = mid;
		else l = mid;
	}
	printf("%.6Lf", ans);
	//fclose(stdin), fclose(stdout);
	return 0;
}