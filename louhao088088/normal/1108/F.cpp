// Problem: CF1108F MST Unification
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1108F
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 2021-12-13 21:18:26
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=2e5+5,M=34005;
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
int n,m,x,y,z,fa[maxn],f[maxn][22],s[maxn][22],d[maxn],flag[maxn],ans;
struct node
{
	int x,y,z;
}a[maxn];
vector<pi>e[maxn];
bool cmp(node a,node b){return a.z<b.z;}
int getf(int x){if(x==fa[x])return fa[x];return fa[x]=getf(fa[x]);}
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1],s[x][i]=max(s[x][i-1],s[f[x][i-1]][i-1]);
	for(auto i:e[x])
		if(i.fi^fa)
		{
			f[i.fi][0]=x,s[i.fi][0]=i.se;
			dfs(i.fi,x);
		}
}
int Lca(int x,int y)
{
	int res=0;
	if(d[x]<d[y])swap(x,y);
	for(int i=20;i>=0;i--)if(d[f[x][i]]>=d[y])res=max(res,s[x][i]),x=f[x][i];
	if(x==y)return res;
	for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])res=max(res,s[x][i]),res=max(res,s[y][i]),x=f[x][i],y=f[y][i];
	res=max(res,s[x][0]),res=max(res,s[y][0]);
	return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(getf(a[i].x)==getf(a[i].y))continue;flag[i]=1;
		e[a[i].x].push_back(mp(a[i].y,a[i].z)),e[a[i].y].push_back(mp(a[i].x,a[i].z));
		fa[getf(a[i].x)]=getf(a[i].y);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		if(flag[i])continue;
		x=Lca(a[i].x,a[i].y);ans+=max(0,x+1-a[i].z);
	}cout<<ans;
 	return 0;
}