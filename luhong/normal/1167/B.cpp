#include <cstdio>
#include <iostream>

void get(int x, int &a, int &b)
{
	if(x % 42 == 0 && x / 42 >= 4) a = 42, b = x / 42;
	else if(x % 23 == 0 && x / 23 >= 4) a = 23, b = x / 23;
	else if(x % 16 == 0 && x / 16 >= 4) a = 16, b = x / 16;
	else if(x % 15 == 0 && x / 15 >= 4) a = 15, b = x / 15;
	else if(x % 8 == 0 && x / 8 >= 4) a = 8, b = x / 8;
	else a = 4, b = x / 4;
}

int A[7];
int main()
{
	int x, a, b, c, d;
	printf("? 1 2\n"); fflush(stdout);
	scanf("%d", &x); get(x, a, b);
	printf("? 1 5\n"); fflush(stdout);
	scanf("%d", &x); get(x, c, d);
	if(a == d) std::swap(c, d);
	if(b == c) std::swap(a, b);
	if(b == d) std::swap(a, b), std::swap(c, d);
	A[1] = a; A[2] = b; A[5] = d;
	
	printf("? 3 4\n"); fflush(stdout);
	scanf("%d", &x); get(x, a, b); 
	printf("? 3 6\n"); fflush(stdout);
	scanf("%d", &x); get(x, c, d);
	if(a == d) std::swap(c, d);
	if(b == c) std::swap(a, b);
	if(b == d) std::swap(a, b), std::swap(c, d);
	A[3] = a; A[4] = b; A[6] = d;
	printf("!"); for(int i = 1; i <= 6; i++) printf(" %d", A[i]); fflush(stdout);
}