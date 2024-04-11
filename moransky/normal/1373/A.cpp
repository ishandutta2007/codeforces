#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long LL;
 
int a, b, c;
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a < c) {
			printf("%d ", 1);
		} else printf("-1 ");
		if ((LL)a * b > c) printf("%d\n", b);
		else printf("-1\n");
	}
	return 0;
}