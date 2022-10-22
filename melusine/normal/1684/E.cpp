#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
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
int a[200005];
int tsl[200005];
set<int>se;
int sth[200005],cnt;
signed main()
{
	int t,n,k,ans=0,pre,tk;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		se.clear();
		for(int i=0;i<=n;i++)tsl[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]<=n)tsl[a[i]]++; 
		}
		tk=k;
		pre=0;
		while(tsl[pre]>0||tk>0)
		{
			if(tsl[pre]==0)tk--;
			pre++;
			if(pre==n)break;
		}
		sort(a+1,a+n+1);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=pre)continue;
			if((i==1||a[i]!=a[i-1])&&a[i]>pre)
			{
				cnt++;
				sth[cnt]=1;
			}
			else sth[cnt]++;
		}
		sort(sth+1,sth+cnt+1);
		tk=k;
		//printf("%lld\n",pre);
		//printf("%lld\n",cnt);
		ans=cnt;
		for(int i=1;i<=cnt;i++)
		{
			if(tk>=sth[i])
			{
				tk-=sth[i];
				ans--;
			}
			else break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}