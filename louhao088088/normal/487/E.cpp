// Problem: CF487E Tourists
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF487E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 2022-02-10 09:01:57
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
int n,m,low[maxn],dfn[maxn],tot,st[maxn],tp,cnt,id[maxn],b[maxn],a[maxn];
int fa[maxn],son[maxn],siz[maxn],top[maxn],d[maxn],Min[maxn*4],idx,q,x,y;
vector<int>e[maxn],G[maxn];
multiset<int>s[maxn];
char ch;
void tarjan(int x){
	dfn[x]=low[x]=++tot;st[++tp]=x;
	for(auto i:G[x])
		if(!dfn[i]){
			tarjan(i);low[x]=min(low[x],low[i]);
			if(dfn[x]==low[i]){
				cnt++;e[cnt].pb(x),e[x].pb(cnt);
				for(;st[tp+1]!=i;tp--)e[cnt].pb(st[tp]),e[st[tp]].pb(cnt);
			}
		}
		else low[x]=min(low[x],dfn[i]);
}
void dfs1(int x,int f)
{
	//cout<<x<<' '<<f<<endl;
	d[x]=d[f]+1,fa[x]=f;siz[x]=1;
	for(auto i:e[x])
		if(i^fa[x])
		{
			dfs1(i,x);
			if(x>n)s[x].insert(a[i]);
			if(siz[i]>siz[son[x]])son[x]=i;
			siz[x]+=siz[i];
		}
}
void dfs2(int x,int tf)
{
	top[x]=tf;id[x]=++idx;
	if(x<=n)b[idx]=a[x];else b[idx]=*s[x].begin();
	if(son[x])dfs2(son[x],tf);
	for(auto i:e[x])
		if(i!=fa[x]&&i!=son[x])
			dfs2(i,i);
	
}
void build(int rt,int l,int r)
{
	if(l==r){Min[rt]=b[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	Min[rt]=min(Min[ls],Min[rs]);
}
void change(int rt,int l,int r,int x,int num)
{
	if(l>x||r<x)return;
	if(l==r){Min[rt]=num;return;}
	change(ls,l,mid,x,num),change(rs,mid+1,r,x,num);
	Min[rt]=min(Min[ls],Min[rs]);
	//cout<<Min[rt]<<" "<<Min[ls]<<" "<<Min[rs]<<" "<<l<<" "<<r<<" "<<x<<" "<<num<<endl;
}
int query(int rt,int l,int r,int L,int R)
{
	//cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(l>R||r<L)return 1e9;
	if(l>=L&&r<=R)return Min[rt];
	return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
int treequery(int x,int y)
{
	int res=1e9;
	while(top[x]!=top[y])
	{
		//cout<<x<<" "<<y<<endl;
		if(d[top[x]]<d[top[y]])swap(x,y);
		res=min(res,query(1,1,cnt,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(d[x]<d[y])swap(x,y);
	res=min(res,query(1,1,cnt,id[y],id[x]));
	//cout<<y<<" "<<x<<" "<<id[y]<<" "<<id[x]<<endl;
	if(y>n)res=min(res,a[fa[y]]);
	return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),q=read();cnt=n;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),G[x].pb(y),G[y].pb(x);
	tarjan(1);dfs1(1,0);dfs2(1,1);build(1,1,cnt);
//	for(int i=1;i<=cnt;i++)cout<<fa[i]<<endl;
	for(int i=1;i<=q;i++)
	{
		ch=getchar();while(ch!='A'&&ch!='C')ch=getchar();x=read(),y=read();
		if(ch=='A')printf("%d\n",treequery(x,y));
		else 
		{
			if(fa[x])
			{
				s[fa[x]].erase(s[fa[x]].find(a[x]));
				s[fa[x]].insert(y);
				change(1,1,cnt,id[fa[x]],*s[fa[x]].begin());
			}
			a[x]=y;change(1,1,cnt,id[x],y);
			
		}
	}
 	return 0;
}