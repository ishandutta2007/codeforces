#include <cstdio>
#include <cstring>
const int MAXN = 400005;
typedef long long int LL;

int n, a[MAXN], maxv[MAXN], res[MAXN], len[MAXN], G[MAXN];

int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
inline int min(int a, int b){return a > b ? b : a;}
LL solve(int g){
	int i; LL ret = 0LL;
	memset(maxv, -1, sizeof(maxv));
	for(i = 1; i <= n; ++ i)
		if(a[i] > maxv[i % g])
			maxv[i % g] = a[i];
	for(i = (n << 1); i; -- i)
		if(a[i] == maxv[i % g])
			len[i] = len[i + 1] + 1;
		else len[i] = 0;
	for(i = 1; i <= n; ++ i)
		res[i] = res[i - 1] + int(G[i] == g);
	for(i = 1; i <= n; ++ i)
		ret += res[min(n - 1, len[i])];
	return ret;
}
int main(){
	int i; LL ans = 0LL;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		a[n + i] = a[i];
		G[i] = gcd(i, n);
	}
	for(i = 2; i <= n / i; ++ i)
		if(n % i == 0){
			ans += solve(i);
			if(i != n / i) ans += solve(n / i);
		}
	printf("%I64d\n", ans + solve(1));
	return 0;
}