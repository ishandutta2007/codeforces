#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, a[200005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	
	LL s = 0;
	rep(i, n) s += a[i];
	if(s + 1LL * (n - 2) * a[0] > 0 || s + 1LL * (n - 2) * a[n - 1] < 0) {
		printf("INF\n"); return;
	}
	
	LL sl = 0, ans = -INF;
	rep(i, n - 1) {
		sl += a[i];
		LL coef = s + 1LL * (n - i - 2) * a[0] + 1LL * i * a[n - 1];
		ans = max(ans, max(coef * -a[i], coef * -a[i + 1]) + sl * a[n - 1] + (s - sl) * a[0] - 1LL * a[0] * a[n - 1]);
	}
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}