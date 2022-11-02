// Problem: CF1120D Power Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1120D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-04-21 20:42:21
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
#define int long long
const int maxn=2e5+5,M=34005;
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
int n,m,a[maxn],tot=0,cnt=0,ans=0,num=0,x,y,fa[maxn],vis[maxn];
vector<int>e[maxn];
struct node{int x,y,z,w;}b[maxn];
bool cmp(node a,node b){return a.w<b.w;}
int find(int x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
void dfs(int x,int fa){
	int l=tot,r;
	if(e[x].size()==1&&x!=1){l=++tot;b[++cnt]={l,l+1,x,a[x]};return;}
	for(auto i:e[x])if(i^fa)dfs(i,x);
	r=tot;b[++cnt]={l+1,r+1,x,a[x]};
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].pb(y),e[y].pb(x);dfs(1,0);
	tot++;for(int i=1;i<=tot;i++)fa[i]=i;int r=0;sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i=r+1){
		while(b[r+1].w==b[i].w){r++;
			int u=find(b[r].x),v=find(b[r].y);
			if(u==v)continue;vis[b[r].z]=1;num++;
		}r=i-1;
		while(b[r+1].w==b[i].w){r++;
			int u=find(b[r].x),v=find(b[r].y);
			if(u==v)continue;fa[u]=v;ans+=b[i].w;
		}
	}
	cout<<ans<<" "<<num<<endl;
	for(int i=1;i<=n;i++)
		if(vis[i])printf("%d ",i);
 	return 0;
}