#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=5e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,s[25],Max,siz[maxn],son[maxn],g[maxn],d[maxn],f[maxn];
int id[maxn],ans[maxn],dis[maxn],t[maxn*10],L[maxn],R[maxn],idx=0;
char c[5];
vector<int>e[maxn];
void dfs(int x)
{
	siz[x]=1;L[x]=++idx;id[idx]=x;//cout<<dis[x]<<endl;
	for(auto i:e[x])
	{
		dis[i]=dis[x]^(g[i]);d[i]=d[x]+1;dfs(i);siz[x]+=siz[i];
		if(siz[son[x]]<siz[i])son[x]=i;
	}R[x]=idx;
}
void dfs2(int x,int y)
{
	for(auto i:e[x])
		if(i^son[x])dfs2(i,0),ans[x]=max(ans[x],ans[i]);
	if(son[x])dfs2(son[x],1),ans[x]=max(ans[x],ans[son[x]]);
	if(t[dis[x]])ans[x]=max(ans[x],t[dis[x]]-d[x]);t[dis[x]]=max(t[dis[x]],d[x]);
	for(int i=1;i<=22;i++)ans[x]=max(ans[x],t[dis[x]^s[i]]-d[x]);
	//cout<<ans[x]<<" "<<x<<endl;
	for(auto i:e[x])
	{
		if(i==son[x])continue;
		for(int j=L[i];j<=R[i];j++)
		{
			int u=id[j];
			if(t[dis[u]])ans[x]=max(ans[x],t[dis[u]]+d[u]-2*d[x]);//cout<<u<<" "<<t[dis[u]]<<" "<<dis[u]<<" "<<ans[x]<<" "<<x<<endl;
			for(int i=1;i<=22;i++)if(t[dis[u]^s[i]])ans[x]=max(ans[x],t[dis[u]^s[i]]+d[u]-2*d[x]);
			//cout<<u<<" "<<dis[u]<<" "<<ans[x]<<" "<<x<<endl;
		}
		for(int j=L[i];j<=R[i];j++)t[dis[id[j]]]=max(t[dis[id[j]]],d[id[j]]);
	}
	if(y==0)
		for(int i=L[x];i<=R[x];i++)t[dis[id[i]]]=0;
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=2;i<=n;i++)f[i]=read(),e[f[i]].push_back(i),scanf("%s",c+1),g[i]=(1<<(c[1]-'a'));
	s[0]=0,s[1]=1;dfs(1);
	for(int i=2;i<=22;i++)s[i]=s[i-1]*2;dfs2(1,1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
 	return 0;
}