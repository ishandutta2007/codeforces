#include <stdbool.h>
#include <stdio.h>

bool is_white(int x, int y);

int main() {
	int x, y;
	
	scanf("%d %d", &x, &y);
	
	printf("%s\n", is_white(x, y)?"white":"black");
	
	return 0;
}

bool is_white(int x, int y) {
	if(x==0 || y==0)
		return false;
	
	bool b = true;
	int sqrt = 0, r = 0;
	
	r = x*x +y*y;
	
	sqrt = 0;
	
	while((sqrt)*(sqrt)<=r)
		sqrt++;
	
	sqrt--;
	
	if(sqrt*sqrt==r)
		return false;
	
	b = sqrt%2 == 1;
	
	if(x*y < 0)
		b = !b;
	
	return b;
}