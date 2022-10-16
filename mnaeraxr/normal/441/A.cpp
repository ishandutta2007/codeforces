/*
	author:		MarX
	school:		UH
*/

#include <bits/stdc++.h>
//#include <stdio.h>

using namespace std;

int aaa[1000000];

int main()
{
	int total,v;
	scanf("%d%d",&total,&v);
	int t,min;
	int c;
	int amount = 0;
	for (int i = 0; i < total; i++)
	{
		scanf("%d%d",&t,&min);
		for (int j = 1; j < t; ++j)
		{
			scanf("%d",&c);
			if (c < min)
				min = c;
		}
		if (min < v)
		{
			aaa[amount] = i + 1;
			amount++;
		}
	}
	printf("%d\n",amount);
	if (amount > 0)
	{
		for (int i = 0; i < amount - 1; ++i)
			printf("%d ",aaa[i]);
		printf("%d\n",aaa[amount - 1]);
	}
	else
		printf("\n");

	//system("pause");
	return 0;
}