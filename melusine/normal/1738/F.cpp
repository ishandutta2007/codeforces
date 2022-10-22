#include<bits/stdc++.h>
#define int long long
#define mod 998244353
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
int rd[100005],pos[100005];
bool bi(int x,int y)
{
	return rd[x]>rd[y];
}
int fa[100005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
bool vis[100005];
signed main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)rd[i]=read(),pos[i]=i,vis[i]=false,fa[i]=i;
		sort(pos+1,pos+n+1,bi);
		for(int ti=1;ti<=n;ti++)
		{
			int i=pos[ti];
			if(vis[i]==true)continue;
			vis[i]=true;
			for(int j=1;j<=rd[i];j++)
			{
				printf("? %d\n",i);
				fflush(stdout);
				x=read();
				int tx=findf(x),ty=findf(i);
				if(tx==ty)continue;
				if(vis[tx]==true)
				{
					fa[ty]=tx;
					break;
				}
				vis[tx]=true;
				fa[ty]=tx;
			}
		}
		printf("! ");
		for(int i=1;i<=n;i++)printf("%d ",findf(i));
		printf("\n");
		fflush(stdout);
	}
	return 0;
}