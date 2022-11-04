#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , a , b , c , i , j , l , r , p1 , p2 , p3 , ll , rr , f1 , f2 , t; 

long long gcd(long long f1 , long long f2)
{
	if (f1 == 0)
	    return f2;
	gcd(f2%f1,f1);
}

int main ()
{
	scanf("%I64d",&n);
	l = n/2;
	l++;
	r = 3*n/2;
	if (n%2==0)
	    r--;
    for (i = l ; i <= r ; i++)
    {
    	t = 0;
    	a = i;
    	p2 = 2*a-n;
    	p1 = a*n;
    	p3 = gcd(p1,p2);
    	p1 /= p3;
    	p2 /= p3;
    	if (a > (p1/p2))
    	    ll = a+1;
    	else
		    ll = (p1/p2)+1;    
    	rr = 2*p1/p2;
    	if ((2*p1)%p2==0)
    	    rr--;
    	for (j = ll ; j <= rr ; j++)
    	{
    		b = j;
    		f1 = b*p2-p1;
    		f2 = p1*b;
    		if (f2%f1==0)
    		{
    		    c = f2/f1;
    		    if (b < 1000000000 && c <= 1000000000 && b < c && a < b && a < 99999999)
    		    {
	    		    t = 1;
	    		    break;
    		    }
    		}
    	}
    	if (t == 1)
    		break;
    }
    if (t == 1)
	    printf("%I64d %I64d %I64d\n",a,b,c);
	else    
	    printf("-1\n");
    //system("PAUSE");
	return 0;
}