#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define mod 1000000007
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
int a[1000005];
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		flag=true;
		for(int i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			if(a[i]<0)
			{
				flag=false;
				break;
			}
			if(a[i]==0)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]!=0)
					{
						flag=false;
						break;
					}
				}
				break;
			}
		}
		if(a[n]!=0)
		{
			printf("NO\n");
			continue;
		}
		if(flag==false)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}