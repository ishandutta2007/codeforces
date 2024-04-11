#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
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
int a[200005];
int ans[200005],cnt;
map<int,int>ma;
int main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	if(n==1)
	{
		printf("-1\n");
		return 0;
	}
	if(n==2)
	{
		if(a[1]==a[2])
		{
			printf("1\n%d\n",a[1]);
			return 0;
		}
		ans[++cnt]=2*a[1]-a[2];
		ans[++cnt]=2*a[2]-a[1];
		if((a[2]-a[1])%2==0)ans[++cnt]=(a[1]+a[2])/2;
		sort(ans+1,ans+cnt+1);
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
		return 0;
	}
	for(int i=2;i<=n;i++)ma[a[i]-a[i-1]]++;
	for(int i=2;i<=n;i++)
	{
		if(ma[a[i]-a[i-1]]==n-1)
		{
			if(a[i]-a[i-1]==0)
			{
				printf("1\n%d\n",a[i]);
				return 0;
			}
			printf("2\n");
			printf("%d %d\n",a[1]-a[i]+a[i-1],a[n]+a[i]-a[i-1]);
			return 0;
		}
		if(ma[a[i]-a[i-1]]==n-2)
		{
			if(ma[2*(a[i]-a[i-1])]==0)continue;
			if(a[i]-a[i-1]==0)continue;
			for(int j=2;j<=n;j++)
			{
				if(a[j]-a[j-1]!=a[i]-a[i-1])
				{
					printf("1\n%d\n",(a[j]+a[j-1])/2);
					return 0;
				}
			}
		}
	}
	printf("0\n");
	return 0;
}