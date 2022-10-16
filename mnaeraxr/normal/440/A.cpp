/*
	author:		MarX
	team:		Eclipse
	school:		UH
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;


bool L[100100];

int main()
{
	int times;
	scanf("%d",&times);
	int t;
	for (int i = 0; i < times - 1; ++i)
	{
		scanf("%d",&t);
		L[t] = true;
	}
	for (int i = 1; i <= times; ++i)
		if (!L[i])
			printf("%d\n", i);
	return 0;
}