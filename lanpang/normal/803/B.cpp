#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int f[2][200001] , n;

int main ()
{
	int i , p;
	cin >> n;
	p = -n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&f[1][i]);
		if (f[1][i] == 0)
		{
			p = i;
		} 
		f[0][i] = i-p;
	}
	p = 2*n;
	for (i = n ; i >= 1 ; i--)
	{
		if (f[1][i] == 0)
		{
			p = i;
		}
		if (p-i < f[0][i])
		{
			f[0][i] = p-i;
		}
	}
	for (i = 1 ; i < n ; i++)
	{
		printf("%d ",f[0][i]);
	}
	printf("%d\n",f[0][n]);
	//system("PAUSE");
	return 0;
}