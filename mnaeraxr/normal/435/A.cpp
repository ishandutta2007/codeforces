// MOGContest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>

int main()
{
	int total, size;
	scanf("%d%d",&total,&size);
	int v;
	int bus = 0;
	int filled = 0;
	for (int i = 0; i < total; i++)
	{
		scanf("%d",&v);
		if (filled + v > size)
		{
			bus++;
			filled = v;
		}
		else
		{
			filled += v;
		}
	}
	printf("%d\n",bus + 1);

}