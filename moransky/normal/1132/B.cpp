#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300010;
typedef long long LL;
int n, m, a[N], q;
LL sum = 0;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i), sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", &q);
		printf("%lld\n", sum - a[n - q + 1]);
	}
	return 0;
}