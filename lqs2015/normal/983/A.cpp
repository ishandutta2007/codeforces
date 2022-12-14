#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long p,q,b,n; 
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
void get(long long &x)
{
    long long f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int main()
{
	get(n);
	while(n--)
	{
		get(p);get(q);get(b);
		q=q/gcd(p,q);
		while(q!=1)
		{
			long long k=gcd(q,b);
			if (k==1)  break;
			while(q%k==0) q=q/k;
		}
		if (q==1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}