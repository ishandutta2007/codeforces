#include<bits/stdc++.h>
#define int long long
#define N 300005
using namespace std;
int size[N],now[N],tong[N],sum,MAX,a[N],head[N],cnt,ans[N],n,x,y;
struct 
{
	int to,nx;
}e[N<<1];
void ad(int x,int y)
{
	cnt++;
	e[cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
void dfs(int k,int ft)
{
	size[k]=1;
	now[k]=0;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=ft)
	  {
	  	  dfs(e[i].to,k);
	  	  if (size[e[i].to]>size[now[k]]) now[k]=e[i].to;
	  	  size[k]+=size[e[i].to];
	  }
}
void dfs2(int k,int ft,int nw)
{
	tong[a[k]]++;
	if (tong[a[k]]>MAX) 
	{
		MAX=tong[a[k]];
		sum=a[k];
	} else if (tong[a[k]]==MAX) 
	{
		sum+=a[k];
	}
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=ft&&e[i].to!=nw)
	  {
	  	  dfs2(e[i].to,k,nw);
	  }
}
void init(int k,int ft)
{
	tong[a[k]]--;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=ft)
	  {
	  	  init(e[i].to,k);
	  }
}
void dfs1(int k,int ft)
{
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=ft&&e[i].to!=now[k])
	  {
	  	  dfs1(e[i].to,k);
	  	  init(e[i].to,k);
	  	  sum=MAX=0;
	  }
	if (now[k]) 
	{
	  dfs1(now[k],k);
    }
    dfs2(k,ft,now[k]);
	ans[k]=sum;
}
signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++)
	{
		cin>>x>>y;
		ad(x,y);
		ad(y,x);
	}
	dfs(1,0);
	dfs1(1,0);
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}