#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1000007;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node 
{
	int v,nex;
}e[maxn];
int ans=0,n,m,a[maxn],b[maxn],x,y,T,head[maxn],c[maxn],F,vis[maxn],cnt,ans1,ans2;
void add(int x,int y){e[++cnt].v=y,e[cnt].nex=head[x],head[x]=cnt;}
void dfs(int x,int fa,int dis)
{
	vis[x]=dis;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v]&&v!=fa&&(dis-vis[v])%2==0)F=1;
		if(vis[v])continue;c[v]=c[x]^1;
		dfs(v,x,dis+1);
	}
}
signed main()
{
	T=read();
	while(T--)
	{
		for(int i=1;i<=n;i++)head[i]=0,c[i]=0,vis[i]=0;cnt=0;F=0;ans1=ans2=0;
		n=read(),m=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read(),ans=ans+abs(b[i]-a[i]),a[i]=b[i]-a[i];
		for(int i=1;i<=m;i++)x=read(),y=read(),add(x,y),add(y,x);
		if(ans%2==1){puts("NO");continue;}cnt=0;c[1]=1;
		dfs(1,0,1);if(F){puts("YES");continue;}
		for(int i=1;i<=n;i++)if(c[i]==1)ans1+=a[i];else ans2+=a[i];
		//cout<<ans1<<" "<<ans2<<endl;
		if(ans1==ans2)puts("YES");else puts("NO");
	}
	return 0;
}