#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

int main()
{
	int a = 0, b = 0;
	int ck = -2;
	for(int i = 29; i >= 0; i--)
	{
		int k1, k2;
		if(ck != -2) k1 = ck;
		else
		{
			printf("? %d %d\n", a, b);
			fflush(stdout);
			scanf("%d", &k1);
		}
		printf("? %d %d\n", a + (1 << i), b + (1 << i));
		fflush(stdout);
		scanf("%d", &k2);
		
		if(k1 == k2)
		{
			int k3;
			printf("? %d %d\n", a + (1 << i), b);
			fflush(stdout);
			scanf("%d", &k3);
			
			if(k3 == -1) 
			{
				a += (1 << i);
				b += (1 << i);
				
			}
			
			ck = k1;
		}
		else
		{
			if(k1 > 0) 
			{
				a += (1 << i);
			}
			else
			{
				b += (1 << i);
			}
			ck = -2;
		}
	}
	printf("! %d %d\n", a, b);
	fflush(stdout);
	return 0;
}