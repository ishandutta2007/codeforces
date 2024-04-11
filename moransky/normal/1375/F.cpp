#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

LL a[3];

void work() {
	int maxLoc = (a[0] > a[1] ? (a[0] > a[2] ? 0 : 2) : (a[1] > a[2] ? 1 : 2)); 
	LL p = 3 * a[maxLoc] - a[0] - a[1] - a[2];
	printf("%lld\n", p);
	fflush(stdout);
	int m; scanf("%d", &m);
	if (m - 1 == maxLoc) {
		a[maxLoc] += p;
		work();
	} else {
		printf("%lld\n", 2 * a[maxLoc] - a[0] - a[1] - a[2] + a[m - 1]);
		fflush(stdout);
		scanf("%d", &m);
	}
} 

int main() {
	for (int i = 0; i < 3; i++) scanf("%lld", a + i);
	puts("First");
	work();
	return 0;
}