#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , i , s;
int l=0 , m;

int main ()
{
	scanf("%I64d%d",&n,&m);
	s = sqrt(n);
	for (i = 1 ; i <= s && l < m ; i++)
	{
		if (n%i==0)
		{
			l++;
			if (l==m)printf("%I64d\n",i);    
		}
	}
	if (s*s==n)s--;
	for (i = s ; i >= 1 && l < m ; i--)
	{
		if (n%i==0)
		{
			l++;
			if (l==m)printf("%I64d\n",n/i);    
		}
	}
	if (l<m)
	    printf("-1\n"); 
    //system("PAUSE");
	return 0;
}