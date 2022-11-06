#include <cstdio>
#include <iostream> 
#include <bitset>
#define MN 4010

std::bitset<MN> b;
int a[MN];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, N = 0; scanf("%d", &n);
		int Max = 0;
		for(int i = 1; i <= 2 * n; i++)
		{
			int p; scanf("%d", &p);
			if(p > Max) a[++N] = 1, Max = p;
			else a[N]++;
		}
		for(int i = 0; i <= 2 * n; i++) 
			b[i] = 0;
		b[0] = 1;
		for(int i = 1; i <= N; i++)
		{
			b |= b << a[i];
		}
		if(b[n] == 1) puts("YES");
		else puts("NO");
	}
}