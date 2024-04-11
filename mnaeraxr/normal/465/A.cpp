/*
	author:		MarX
	school:		UH
*/

#include <bits/stdc++.h>	

using namespace std;

char W[100 + 10];

int main()
{
	int n; scanf("%d",&n);
	scanf("%s",W);
	int c = 0;
	for (int i = 0; i < n ; ++i)
	{
		c++;
		if (W[i] == '0')
			break;
	}
	printf("%d\n",c);
	return 0;
}