#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
signed main()
{
	int t,a1,b1,c1,a2,b2,c2,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a1=read();
		b1=read();
		c1=read();
		a2=read();
		b2=read();
		c2=read();
		if(b2%b1!=0)
		{
			printf("0\n");
			continue;
		}
		if(a1+b1*(c1-1)<a2+b2*(c2-1)||a1>a2)
		{
			printf("0\n");
			continue;
		}
		if((a2-a1)%b1!=0)
		{
			printf("0\n");
			continue;
		}
		ans=0;
		flag=true;
		for(int i=1;i*i<=b2;i++)
		{
			if((b2%i)!=0)continue;
			if(1LL*i*b1/gcd(i,b1)==b2)
			{
				//printf("orz%d\n",i);
				if(a2-b2<a1)
				{
					flag=false;
					break;
				}
				if(a2+b2*c2>a1+b1*(c1-1))
				{
					flag=false;
					break;
				}
				ans+=1LL*(b2/i)*(b2/i)%mod;
				ans%=mod;
			}
			if(i==b2/i)continue;
			if(1LL*(b2/i)*b1/gcd(b2/i,b1)==b2)
			{
				//printf("orz%d\n",b2/i);
				if(a2-b2<a1)
				{
					flag=false;
					break;
				}
				if(a2+b2*c2>a1+b1*(c1-1))
				{
					flag=false;
					break;
				}
				ans+=1LL*(i)*(i)%mod;
				ans%=mod;
			}
		} 
		if(flag==false)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}