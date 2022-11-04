#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long a[200001] , n , x , f[200001];
long long ans=0;

int main ()
{
    int i;
    scanf("%I64d%I64d",&n,&x);
    for (i = 0 ; i <= 200000 ; i++)
    {
    	a[i] = 0;
    	f[i] = 0;
    }
    for (i = 1 ; i <= n ; i++)
    {
        scanf("%I64d",&a[i]);
        f[a[i]]++;
    }
    for (i = 1 ; i <= n ; i++)
    {
    	if (x==0)
    	    ans += f[a[i]^x]-1;
    	else    
    	    ans += f[a[i]^x];
    }
    printf("%I64d\n",ans/2);	
	//system("PAUSE");
	return 0;
}