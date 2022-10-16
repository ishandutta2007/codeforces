#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL a, b, n, res = 9e18, ans;
void work(int x) {
	int k;
	if(a % x == 0) k = 0;
	else k = x - a % x;
	LL val = (a + k) * (b + k) / x;
	if(val < res || (val == res && k < ans)) {
		res = val, ans = k;
	}
}
int main(){
	scanf("%lld%lld", &a, &b);
	if(a < b) swap(a, b);
	n = a - b;
	for (int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			if(n / i != i) work(n / i);
			work(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}