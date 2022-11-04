#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a , b , c , n , l1=0 , l2=0;
long long f1[300001] , f2[300001] , k;
int i;
int p1 , p2 , p3 , p;
long long h=0;
char s[10];

int main ()
{
	scanf("%d%d%d%d",&a,&b,&c,&n);
    for (i = 1 ; i <= n ; i++)
    {
    	scanf("%I64d",&k);
    	gets(s);
    	if (s[1] == 'U')
    	{
    		l1++;
    		f1[l1]=k;
    	}
    	else
    	{
    		l2++;
    		f2[l2]=k;
    	}
    }
    sort(f1+1,f1+l1+1);
    sort(f2+1,f2+l2+1);
    p1 = min(l1,a);
    for (i = 1 ; i <= p1 ; i++)
        h += f1[i];
    p2 = min(l2,b);
    for (i = 1 ; i <= p2 ; i++)
        h += f2[i];
    p3 = min(c,n-p1-p2);
    p = p1+p2+p3;
    p1++;
    p2++;
	for (i = 1 ; i <= p3 ; i++)
	{
		if (p1 <= l1 && p2 <= l2)
		{
			if (f1[p1] < f2[p2])
			{
				h += f1[p1];
				p1++;
			}
			else
			{
				h += f2[p2];
				p2++;
			}
		}
		else
		{
			if (p1 > l1)
			{
				h += f2[p2];
				p2++;
			}
			else
			{
				h += f1[p1];
				p1++;
			}
		}
	}    
	printf("%d %I64d\n",p,h);
    //system("PAUSE");
	return 0;
}