#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
main(int argc, char **argv) { 
	int r1, r2, c1, c2, d1, d2;
	scanf("%d%d%d%d%d%d", &r1, &r2, &c1, &c2, &d1, &d2);
	int a = r1+d1-c2;
	int b = r1+c2-d1;
	int c = r2+c1-d1;
	int d = r2+d1-c1;
	if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 0){
	a = a/2; b = b/2; c = c/2; d = d/2;
		if(a!=b && a != c && a != d && b != c && b != d && c != d){
			if(a >= 1 && b >= 1 && c >= 1 && d >= 1 && a <= 9 && b <= 9 && c <= 9 && d <= 9){
				printf("%d %d\n%d %d\n", a, b, c, d);
				exit(0);
			}
		}
	}
printf("-1\n");
exit(0);
}