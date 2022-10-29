#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, r, i, j;
	scanf("%d", &n);
	if(n>0)
		r = n;
	else {
		i = n/10;
		j = (n/100) * 10 + n%10;
		if(i<j)
			r = j;
		else
			r = i;
	}
	printf("%d\n", r);
	
	return 0;
}