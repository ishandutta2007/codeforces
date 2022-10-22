#include<iostream>
#include<cstdio>
#include<vector>
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
int ans[100005];
signed main()
{
	ans[0]=0;
	int sth,cs;
	for(int i=1;i<32768;i++)
	{
		sth=i;
		cs=0;
		while(sth!=0)
		{
			sth=sth*2%32768;
			cs++;
		}
		ans[i]=cs;
	}
	for(int i=32767;i>=0;i--)ans[i]=min(ans[i],ans[i+1]+1);
	int t,n;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		printf("%d ",ans[n]);
	}
	printf("\n");
	return 0;
}