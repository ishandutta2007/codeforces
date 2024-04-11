#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int a; scanf("%d", &a);
		for(int i = 3; i <= 360; i++)
		{
			if((a * i) % 180 == 0 && a * i / 180 < i - 1) {printf("%d\n", i); break;}
		}
	}
}