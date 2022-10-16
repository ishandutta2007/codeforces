#include <cstdio>
#include <iostream>
 
using namespace std;
 
typedef long long LL;
 
int r, b, k;
 
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &r, &b, &k);
		int d = gcd(r, b);
		if (r > b) swap(r, b);
		if (d + (LL)(k - 1) * r < b) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}