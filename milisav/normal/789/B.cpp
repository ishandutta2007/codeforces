#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long b,q,l,m;
long long bp;
long long d;
bool n;
bool pb,pmb;
long long n1,n2;
long long a[2][300000];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	scanf("%lld %lld %lld %lld",&b,&q,&l,&m);
	for(long long i=0;i<m;i++)
	{
		scanf("%lld",&d);
		if(d==0) n=true;
		if(d==b) pb=true;
		if(d==-b) pmb=true;
		if(d>=0)
		{
			a[0][n1]=d;
			n1++;
		}
		else
		{
			a[1][n2]=d;
			n2++;
		}
	}
	sort(a[0],a[0]+n1);
	sort(a[1],a[1]+n2,cmp);
	if(abs(b)>l)
	{
		printf("0");
		return 0;
	}
	if(q==0)
	{
		if(!n) printf("inf");
		else
		{
			if(pb) printf("0");
			else printf("1");
		}
		return 0;
	}
	if(b==0)
	{
		if(!n) printf("inf");
		else printf("0");
		return 0;
	}
	if(q==1)
	{
		if(pb) printf("0");
		else printf("inf");
		return 0;
	}
	if(q==-1)
	{
		if(pb && pmb) printf("0");
		else printf("inf");
		return 0; 
	}
	bp=b;
	long long z=0;
	long long r=0;
	long long p1=0,p2=0;
	bool w=false;
	while(abs(b)<=l)
	{
		while(p1<n1 && a[0][p1]<b) p1++;
		while(p2<n2 && a[1][p2]>b) p2++;
		r++;
		if((p1<n1 && a[0][p1]==b) || (p2<n2 && a[1][p2]==b)) r--;
		b=b*q;
		if(bp==b)
		{
			if(r==0) printf("0");
			else printf("inf");
			return 0;
		}
		if(b==0)
		{
			printf("%lld",r);
			return 0;
		}
	}
	printf("%lld",r);
	return 0;
}