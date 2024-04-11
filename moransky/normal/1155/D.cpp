#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 300010, INF = 2147483647;
typedef long long LL;
int n, x, L[N];
LL a[N], f[3], ans = 0;
int main(){
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) 
		scanf("%lld", a + i);
	
	for(int i = 1; i <= n; i++){
		f[0] = max(f[0] + a[i], 0ll);
		f[1] = max(f[0], f[1] + a[i] * x);
		f[2] = max(f[1], f[2] + a[i]);
		ans = max(ans, f[2]); 
	} 
	printf("%lld\n", ans);
	return 0;
}