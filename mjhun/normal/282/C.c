#include <stdbool.h>
#include <stdio.h>

int main() {
	char c;
	unsigned int la = 0, lb = 0;
	bool a=false, b=false;
	
	while((c=getchar())!='\n') {
		a = a || c == '1';
		la++;
	}
	
	while((c=getchar())!='\n') {
		b = b || c == '1';
		lb++;	
	}
	
	if(la==lb && a==b)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}