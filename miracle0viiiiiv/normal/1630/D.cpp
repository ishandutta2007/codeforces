#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int n, m, x, a[1000005], b[1000005], M[1000005];
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	x = 0;
	rep(i, m) {
		int y; scanf("%d", &y);
		x = gcd(x, y);
	}
	
	LL ans = 0;
	rep(i, x) {
		b[i] = 0; M[i] = INF;
	}
	rep(i, n) {
		if(a[i] < 0) {
			b[i % x] ^= 1; a[i] *= -1;
		}
		ans += a[i]; M[i % x] = min(M[i % x], a[i]);
	}
	
	LL d[2] = {0, 0};
	rep(i, x) d[b[i]] += M[i];
	printf("%lld\n", ans - min(d[0], d[1]) * 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}