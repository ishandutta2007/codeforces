#include <cstdio>
#include <iostream>
#include <cmath> 
using namespace std;
typedef long long LL;
const int N = 200010;
int n, m, k, a[N], max1 = -1, max2 = -1;
LL res = 0;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if(a[i] > max1){
			max2 = max1;
			max1 = a[i];
		}else if(a[i] > max2){
			max2 = a[i];
		}
	}
	int num = m / (k + 1), ot = m % (k + 1);
	printf("%lld\n", (LL)num * k * max1 + (LL)num * max2 + (LL)ot * max1);
	 
	
	return 0;
}