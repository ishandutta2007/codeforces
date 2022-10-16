#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300010;
typedef long long LL;
int n, k, a[N];
LL ans, sum[N];
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) 
		scanf("%d", a + i);
	for(int i = n; i; i--)
		sum[i] = sum[i + 1] + a[i];
	sort(sum + 2, sum + 1 + n);
	ans = sum[1];
	for(int i = n; i >= n - k + 2; i--)	ans += sum[i];
	printf("%lld\n", ans);
	return 0;
}