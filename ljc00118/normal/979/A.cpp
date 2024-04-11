#include<bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	n++;
	long long ans = 0;
	if(n == 1) {
		printf("0");
		return 0;
	}
	if(n % 2 == 0) ans = 1;
	if(ans == 0) printf("%lld", n);
	else printf("%lld", n / 2);
	return 0;
}