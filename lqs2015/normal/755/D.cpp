#include<iostream>
#include<cstdio>
using namespace std;
int bit[2222222];
long long ans;
int n,k,x,y;
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
long long getsum(int i)
{
	long long res=0;
	while(i)
	{
		res+=(long long)bit[i];
		i-=i&-i;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	k=min(k,n-k);
	x=1;
	ans=1;
	for (int i=1;i<=n;i++)
	{
		y=x+k;
		ans++;
		if (y>n)
		{
		 	ans=ans+getsum(n)-getsum(x)+getsum(y-n-1);
		 	y-=n;
		}
		else
		{
			ans=ans+getsum(y-1)-getsum(x);
		}
		add(x,1);
		add(y,1);
		x=y;
		printf("%I64d ",ans);
	}
	return 0;
}