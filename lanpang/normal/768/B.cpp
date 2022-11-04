#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , l1 , r1 , ll , rr;

long long dfs(long long x , long long l , long long s)
{
	if (x == 0)
	    return 0;
	if (x == 1)
	{
        if (l == l1)
            ll = s;
        if (l == r1)
		    rr = s+1;
	    return 1;
	}
	else   
	{
		long long p = dfs(x/2,l,s);
		if (p+l == l1)
		    ll = s+x/2;
		if (p+l == r1)
		    rr = s+x/2+x%2;
		if ((r1 >= p+l+1 && r1 <= l+p*2) || (l1 >= p+l+1 && l1 <= l+p*2))
		    dfs(x/2,p+l+1,s+(x/2)+(x%2));	
		return p*2+1;	  
	} 
}

int main ()
{
	scanf("%I64d%I64d%I64d",&n,&l1,&r1);
	dfs(n,1,0);
	printf("%I64d\n",rr-ll);     
    //system("PAUSE");
	return 0;
}