#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int main()
{
	int T;
	LL n;
	scanf("%d", &T);
	while(T --) {
		scanf("%lld", &n);
		LL a = 2, b = n;
		while(b % 2 == 0) {
			a *= 2; b /= 2;
		}
		if(b == 1) printf("-1\n");
		else printf("%lld\n", min(a, b));
	}
	return 0;
}