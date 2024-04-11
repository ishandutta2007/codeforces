#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map> 
#define MN 1010000

int n, p;

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 1; ; i++)
	{
		int N = n - i * p;
		if(N < i) break;
		int cnt = 0;
		for(int j = 0; j <= 30; j++)
		{
			if((N >> j) & 1) cnt++;
		}
		if(i >= cnt) return 0 * printf("%d\n", i);
	}
	puts("-1");
}