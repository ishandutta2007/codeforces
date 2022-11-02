// Skyqwq
#include <iostream>
#include <cstdio>
 
using namespace std;
 
typedef long long LL;
 
int n;
 
int inline ask(int i) {
	if (i == 0 || i == n + 1) return 1000000;
	printf("? %d\n", i);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}
 
int main() {
	scanf("%d", &n);
	int l = 1, r = n - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (ask(mid) < ask(mid + 1)) r = mid;
		else l = mid + 1;
	}
	if (r == n - 1 && ask(r) > ask(r + 1)) printf("! %d\n", r + 1); 
	else printf("! %d\n", r);
	fflush(stdout);
	return 0;
}