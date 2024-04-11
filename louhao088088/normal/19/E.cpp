// Problem: CF19E Fairy
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF19E
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// 2022-04-13 21:23:50
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
#define lowbit(x) (x&-x)
const int maxn=1e5+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,f[maxn][22],a[maxn],fa[maxn],s[maxn],h,v[maxn],u[maxn],d[maxn],vis[maxn],ans[maxn],tot=0;
vector<int>b[maxn],c;vector<pi>e[maxn];
int find(int x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
void dfs(int x,int fa){
	d[x]=d[fa]+1;f[x][0]=fa;vis[x]=1;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(auto i:b[x])c.pb(i);
	for(auto i:e[x])if(i.fi^fa)dfs(i.fi,x);
}
void dfs2(int x,int fa){
	for(auto i:e[x])
		if(i.fi^fa)
		{
			dfs2(i.fi,x),s[x]+=s[i.fi];
			if(s[i.fi]==h)ans[++tot]=i.se;
		}
}
int Lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=20;i>=0;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
bool check(int x,int y){
	//cout<<x<<" "<<y<<" "<<d[x]<<" "<<d[y]<<endl; 
	if((d[x]&1)!=(d[y]&1)){s[x]--,s[y]--,s[Lca(x,y)]+=2;return 0;}
	s[x]++,s[y]++,s[Lca(x,y)]-=2;return 1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		x=u[i]=read(),y=v[i]=read();
		int tx=find(x),ty=find(y);
		if(tx==ty){b[x].pb(i);continue;}
		fa[tx]=ty;e[x].pb(mp(y,i));e[y].pb(mp(x,i));
	}int F=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		c.clear();dfs(i,0);
		h=0;int p;
		for(auto j:c)
			if(check(u[j],v[j]))h++,p=j;
		if(h){
			F++;if(F>1){puts("0");exit(0);}
			dfs2(i,0);
			if(h==1)ans[++tot]=p;
		}
	}
	if(!F){
		cout<<m<<endl;
		for(int i=1;i<=m;i++)printf("%d ",i);exit(0);
	}
	cout<<tot<<endl;
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
 	return 0;
}