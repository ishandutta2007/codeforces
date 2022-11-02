#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
const int maxn=6e3+5;
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node{int v,nex;}e[maxn*2];
int n,m,x,y,f[maxn],b[maxn],head[maxn],ans,a[maxn],tot=0,cnt,g[maxn],Max,p[maxn];
//void C(int x,int num){for(int i=x;i<=n;i+=lowbit(i))c[i]=max(c[i],num);}
// query(int x){int res=0;for(int i=x;i>0;i-=lowbit(i))res=max(res,i);return res;}
void add(int x,int y){e[++cnt].v=y;e[cnt].nex=head[x];head[x]=cnt;}
void dfs(int x,int fa)
{
	int F=0,T=0,L=lower_bound(f+1,f+n+1,a[x])-f;
	ans=max(ans,L);T=f[L];f[L]=a[x];
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		dfs(v,x);
	}
	f[L]=T;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();sort(b+1,b+n+1);
//	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	//for(int i=1;i<=n;i++)cout<<a[i]<<endl;
	for(int i=1;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)
	{
		memset(f,0x3f3f3f3f,sizeof f);//memset(g,0,sizeof g);
		dfs(i,0);//cout<<endl;
	}
	cout<<ans;
	return 0;
}