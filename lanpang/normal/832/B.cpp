#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int a[26] , n , len , m , p;
char c[100001] , t , d[100001];

int main ()
{
	int i , j , k , h;
	gets(c);
	len = strlen(c);
	for (i = 0 ; i < len ; i++)
	{
		a[int(c[i]-'a')] = 1;
	}
	gets(c);
	len = strlen(c);
	p = len;
	for (i = 0 ; i < len ; i++)
	{
		if (c[i] == '*')
		{
			p = i;
		}
	}
	cin >> n;
	for (j = 1 ; j <= n ; j++)
	{
		if (j == 1) t = getchar();
		gets(d);
		m = strlen(d);
		h = 1;
		for (i = 0 ; i < p && h ; i++)
		{
			if (c[i] == '?')
			{
				if (a[int(d[i]-'a')] == 0)
				{
					h = 0;
				}
			}
			else
			{
				if (c[i] != d[i])
				{
					h = 0;
				}
			}
		}
		k = m-1;
		for (i = len-1 ; i > p && h ; i--)
		{
			if (c[i] == '?')
			{
				if (a[int(d[k]-'a')] == 0)
				{
					h = 0;
				}
			}
			else
			{
				if (c[i] != d[k])
				{
					h = 0;
				}
			}
			k--;
		}
		if ((p < len && len-1 > m) || (p == len && len != m))
		    h = 0;
		for (i = p ; i <= k && h ; i++)
		{
			if (a[int(d[i]-'a')])
			{
				h = 0;
			}
		}
		if (h)
			printf("YES\n");
		else
		    printf("NO\n");	
	}
	//system("PAUSE");
	return 0;
}