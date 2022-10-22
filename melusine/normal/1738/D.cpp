#include<bits/stdc++.h>
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
int b[100005],a[100005];
vector<int>v[100005];
bool vis[200005];
int nex[200005];
int main()
{
	int t,n,k,now;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)b[i]=read();
		k=0;
		while(k<=n-1&&b[k+1]>=k+1)k++;
		for(int i=0;i<=n+1;i++)v[i].clear(),nex[i]=-1,vis[i]=false;
		for(int i=1;i<=n;i++)
		{
			v[b[i]].push_back(i);
			vis[b[i]]=true;
		}
		for(int i=1;i<=n;i++)if(vis[i]==true)nex[b[i]]=i;
		now=0;
		for(int i=1;i<=n;i++)if(b[i]==n+1)
		{
			now=n+1;
			break;
		}
		printf("%d\n",k);
		while(now!=-1)
		{
			if(now>=1&&now<=n)printf("%d ",now);
			for(int i=0;i<v[now].size();i++)
			{
				if(vis[v[now][i]]==true)continue;
				printf("%d ",v[now][i]);
			}
			now=nex[now];
		}
		printf("\n");
	}
	return 0;
}