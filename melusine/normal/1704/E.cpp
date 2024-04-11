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
int a[1005],na[1005];
bool dy[1005];
int ys[10005],rd[1005],cd[1005];
int xs[1005];
vector<int>v[1005],fx[1005];
queue<int>que;
int pos[1005],cnt;
bool bi(int x,int y)
{
	return ys[x]<ys[y];
}
signed main()
{
	int t,n,m,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)dy[i]=false;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)cd[i]=0,xs[i]=0;
		for(int i=1;i<=n;i++)v[i].clear(),fx[i].clear();
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			cd[x]++;
			v[x].push_back(y);
			fx[y].push_back(x);
		}
		bool tflag=true;
		for(int i=1;i<=m;i++)
		{
			bool flag=true;
			for(int j=1;j<=n;j++)
			{
				if(a[j]>0)
				{
					flag=false;
					break;
				}
			}
			if(flag==true)
			{
				printf("%lld\n",i-1);
				tflag=false;
				break;
			}
			for(int j=1;j<=n;j++)na[j]=a[j];
			for(int j=1;j<=n;j++)
			{
				if(a[j]>0)
				{
					na[j]--;
					for(int k=0;k<v[j].size();k++)
					{
						na[v[j][k]]++;
					}
				}
			}
			for(int j=1;j<=n;j++)a[j]=na[j];
		}
		if(tflag==false)continue;
		for(int i=1;i<=n;i++)
		{
			if(cd[i]==0)
			{
				que.push(i);
				xs[i]=1;
				break;
			}
		}
		while(!que.empty())
		{
			x=que.front();
			que.pop();
			for(int j=0;j<fx[x].size();j++)
			{
				xs[fx[x][j]]=(xs[fx[x][j]]+xs[x])%mod;
				cd[fx[x][j]]--;
				if(cd[fx[x][j]]==0)que.push(fx[x][j]);
			}
		}
		int ans=m;
		for(int j=1;j<=n;j++)ans=(ans+1LL*a[j]*xs[j]%mod)%mod;
		printf("%lld\n",ans);
	}
}