#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

const int maxn = 1e5 + 20;
int n, st[maxn], top;

int main()
{
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
	{
		st[++top] = 1;
		
		while(top >= 2 && st[top] == st[top - 1]) st[--top]++;
	}
	
	for(int i = 1; i <= top; i++)
		printf("%d ", st[i]);
	return 0;
}