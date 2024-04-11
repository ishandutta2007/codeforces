#include<iostream>
#include<cstdio>
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
bool ispri(int x)
{
	if(x<=0)return false;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
int iscm(int x)
{
	if(x<=0)return -1;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i!=0)continue;
		while(x%i==0)x/=i;
		if(x!=1)return -1;
		return i;
	}
	return x;
}
signed main()
{
	int t,x,d,sth,ans,ansx;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		d=read();
		if(x%(d*d)!=0)
		{
			printf("NO\n");
			continue;
		}
		sth=iscm(d);
		if(ispri(d))
		{
			while(x%d==0)x/=d;
			if(ispri(x))
			{
				printf("NO\n");
				continue;
			}
			else
			{
				printf("YES\n");
				continue;
			}
		}
		else if(sth!=-1&&iscm(x)!=-1)
		{
			ans=0;
			while(d%sth==0)
			{
				d/=sth;
				ans++;
			}
			ansx=0;
			while(x%sth==0)
			{
				x/=sth;
				ansx++;
			}
			if(ans==2)
			{
				if(ansx>=8||ansx==6)
				{
					printf("YES\n");
					continue; 
				}
				else
				{
					printf("NO\n");
					continue;
				}
			}
			if(ans>=3)
			{
				if(ansx>=2*ans+2)
				{
					printf("YES\n");
					continue;
				}
				else
				{
					printf("NO\n");
					continue;
				}
			}
		}
		else
		{
			x/=(d*d);
			if(ispri(x))
			{
				printf("NO\n");
				continue;
			}
			else
			{
				printf("YES\n");
				continue;
			}
		}
	}
	return 0;
}