#include <iostream>
#include <cstdio>
#define MN 101000

int a[MN], b[MN], c[MN];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		b[i] = b[i - 1] | a[i];
	for(int i = n; i >= 1; i--)
		c[i] = c[i + 1] | a[i];
	int Max = -1, id = 0;
	for(int i = 1; i <= n; i++) 
	{
		int x = (a[i] | (b[i - 1] | c[i + 1])) - (b[i - 1] | c[i + 1]);
		if(x > Max) Max = x, id = i;
	}
	printf("%d ", a[id]);
	for(int i = 1; i <= n; i++)
		if(i != id) printf("%d ", a[i]);
}