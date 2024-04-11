#include <cstdio>
#include <algorithm>
#include <iostream>
#define mod 1000000007

long long fac[1010000], inv[1010000];
int a[1010000];

long long C(int a, int b) {return fac[a] * inv[b] % mod * inv[a - b] % mod;}
int main()
{
	fac[0] = inv[1] = inv[0] = 1;
	for(int i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2; i <= 1000000; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= 1000000; i++) inv[i] = inv[i - 1] * inv[i] % mod;
	int n; scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int l = 0, s = 0;
	for(int i = 1; i <= n; i++)
	{
		int li = l - s;
		if(a[i] != a[n]) ans = ans + a[i] * fac[li] % mod * fac[n - li - 1] % mod * C(n, li) % mod, ans %= mod;
		l++;
		if(a[i + 1] == a[i]) s++;
		else s = 0;
	}
	printf("%lld\n", ans);
	return 0;
}


/*li
sigma ai * sigma j=1~li+1 C(li,j-1)*(j-1)!*(n-j)!
*
sigma ai * li! * (n - li - 1)! * sigma j=1~li+1 C(n-j,li-j+1)
C(i,j)=C(i-1,j)+C(i-1,j-1)=C(i-1,j)+C(i-2,j-1)+C(i-3,j-2)+...
sigma ai * li! * (n - li - 1)! * C(n,li)
*/