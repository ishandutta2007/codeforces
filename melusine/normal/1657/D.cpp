#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
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
int c[300005],d[300005],h[300005];
int qd[300005],qh[300005],qans[300005];
int pos[300005];
bool bi(int x,int y)
{
	return qd[x]<qd[y];
}
int maxs[1000005];
int maxq[1000005];
signed main()
{
	int n,zc;
	n=read();
	zc=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		d[i]=read();
		h[i]=read();
		d[i]=d[i]*h[i];
		maxs[c[i]]=max(maxs[c[i]],d[i]);
	}
	int m;
	m=read();
	for(int i=1;i<=m;i++)
	{
		qd[i]=read();
		qh[i]=read();
		qd[i]=qd[i]*qh[i];
		pos[i]=i;
	}
	sort(pos+1,pos+m+1,bi);
	for(int i=1;i<=zc;i++)
	{
		if(maxs[i]==0)continue;
		for(int j=i;j<=zc;j+=i)
		{
			maxq[j]=max(maxq[j],maxs[i]*(j/i)-1);
		}
	}
	int now=1;
	for(int i=1;i<=m;i++)
	{
		int x=pos[i];
		while(now<=zc&&maxq[now]<qd[x])now++;
		qans[x]=now;
		if(now>zc)qans[x]=-1;
	}
	for(int i=1;i<=m;i++)printf("%lld ",qans[i]);
	printf("\n");
	return 0;
}