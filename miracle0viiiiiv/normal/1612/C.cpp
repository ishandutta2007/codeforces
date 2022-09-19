#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

LL fsum(LL n, LL t)
{
	if(t <= n) return t * (t + 1) / 2;
	else return n * n - (2 * n - 1 - t) * (2 * n - t) / 2;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) {
		LL k, x;
		scanf("%lld%lld", &k, &x);
		LL l = 0, r = 2 * k - 1;
		while(l < r) {
			LL mid = (l + r) >> 1;
			if(fsum(k, mid) >= x) r = mid;
			else l = mid + 1;
		}
		printf("%lld\n", r);
	}
	return 0;
}