#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main ()
{
	int n , a[4]={0} , i , t=0;
	char s[101] , c[4];
	scanf("%s",&s);
	n = strlen(s);
	for (i = 0 ; i < 4 ; i++)
	    c[i] = '0';
	for (i = 0 ; i < n && t < 4 ; i++)
	{
	    if (c[i%4] == '0' && s[i] != '!')
	    {
	    	t++;
	    	c[i%4] = s[i];
	    } 
	}
	for (i = 0 ; i < n ; i++)
	{
		if (s[i] == '!')
		{
		    switch (c[i%4])
			{
				case 'R':a[0]++;break;
				case 'B':a[1]++;break;
				case 'Y':a[2]++;break;
				case 'G':a[3]++;break;
			}	
		}
	}
	printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
    //system("PAUSE");
	return 0;
}