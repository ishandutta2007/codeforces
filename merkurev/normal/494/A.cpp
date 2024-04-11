#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


const int maxn = 1e5 + 100;
char str[maxn];

void bad()
{
	printf("-1\n");
}

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif
	scanf("%s", str);
	int n = strlen(str);
	int numO = 0, numC = 0, numX = 0;
	int last = -1;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			numO++;
		else if (str[i] == ')')
			numC++;
		else
		{
			last = i;
			numX++;
		}
	}
	int x = numO - numC - numX;
	if (x < 0)
	{
		bad();
		return 0;
	}
	bool good = true;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			cnt++;
		else
			cnt--;
		if (i == last)
			cnt -= x;
		if (cnt < 0)
			good = false;
	}
	if (!good)
	{
		bad();
		return 0;
	}
	for (int i = 0; i < numX - 1; i++)
		printf("1\n");
	printf("%d\n", x + 1);
	return 0;
}