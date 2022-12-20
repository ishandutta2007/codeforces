#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int tree[10000005][2],tot=0,a[300005],ans[300005],size[10000005],po[35];bool vis[300005];
void dfs(int x)
{
	size[x]=1;
	if(tree[x][0])
	{
		dfs(tree[x][0]);
		size[x]+=size[tree[x][0]];
	}
	if(tree[x][1])
	{
		dfs(tree[x][1]);
		size[x]+=size[tree[x][1]];
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=20;j>=0;j--)
		{
			if(a[i]&(1<<j))
			{
				if(!tree[now][1])
				tree[now][1]=++tot;
				now=tree[now][1];
			}
			else
			{
				if(!tree[now][0])
				tree[now][0]=++tot;
				now=tree[now][0];
			}
		}
	}
	dfs(0);
	po[0]=1;
	for(int i=1;i<=30;i++)
	po[i]=(po[i-1]<<1);
	//for(int i=0;i<=tot;i++)
	//cout<<size[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		int x=read(),now=0,cnt=0,final=0;bool ac=1;
		for(int j=20;j>=0;j--)
		{
			if(x&(1<<j))
			{
				vis[j]^=1;
			}
			//cout<<vis[j]<<" ";
			if(!ac)
			ans[++cnt]=vis[j];
			else if(vis[j])
			{
				if(tree[now][1]&&size[tree[now][1]]!=po[j+1]-1)
				{now=tree[now][1],ans[++cnt]=1;
				//cout<<j<<""<<"size[tree[now][1]]="<<size[now]<<" "<<po[j]<<" "<<tree[now][1];
				}
				else if(!tree[now][1])
				{
					ans[++cnt]=1;
					ac=0;
				}
				else now=tree[now][0],ans[++cnt]=0;
			}
			else
			{
				if(tree[now][0]&&size[tree[now][0]]!=po[j+1]-1)
				{now=tree[now][0],ans[++cnt]=0;
				//cout<<j<<""<<"size[tree[now][1]]="<<size[now]<<" "<<po[j]<<" "<<tree[now][1];
				}
				else if(!tree[now][0])
				{
					ans[++cnt]=0;
					ac=0;
				}
				else now=tree[now][1],ans[++cnt]=1;
			}
		}
		//cout<<endl;
		for(int j=0;j<=20;j++)
		{
			//cout<<ans[cnt]<<" ";
			final+=(ans[cnt--]^vis[j])*(1<<j);
		}
		printf("%d\n",final);
	}
}