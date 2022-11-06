#include <iostream>
#include <cstdio>
#define MN 201000

int T;
int a[MN];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		int t = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			t ^= a[i];
		}
		int w = -1;
		for(int i = 30; i >= 0; i--)
		{
			if((t >> i) & 1)
			{
				w = i; 
				break;
			}
		}
		if(w == -1) {puts("DRAW"); continue;}
		int s = 0;
		for(int i = 1; i <= n; i++)
			if((a[i] >> w) & 1) s++;
		if(!((n - s) & 1))
		{
			if(s % 4 == 1) puts("WIN");
			if(s % 4 == 3) puts("LOSE"); 
		}
		else puts("WIN");
	}
}