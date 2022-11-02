// Problem: CF671D Roads in Yusland
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF671D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 2022-01-20 11:07:49
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
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=3e5+5,M=34005;
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
int n,m,c[maxn],x,y,z,tag[maxn],v[maxn],dis[maxn],ls[maxn],rs[maxn],rt[maxn],dep[maxn],tot,ans,d[maxn];
vector<int>e[maxn];
vector<pi>l[maxn];
void get(int x,int y){tag[x]+=y,v[x]+=y;}
void push(int x){if(tag[x])get(ls[x],tag[x]),get(rs[x],tag[x]),tag[x]=0;}
int merge(int x,int y)
{
	//cout<<x<<" "<<y<<endl;
	if(!x||!y)return x+y;
	//cout<<x<<" "<<y<<endl;
	push(x),push(y);
	if(v[x]>v[y])swap(x,y);
	rs[x]=merge(rs[x],y);
	if(dis[ls[x]]<dis[rs[x]])swap(ls[x],rs[x]);
	dis[x]=dis[rs[x]]+1;return x;
}
int del(int x){return merge(ls[x],rs[x]);}
void dfs(int x,int fa)
{
	//cout<<x<<" "<<fa<<endl;
	d[x]=d[fa]+1;
	for(auto i:e[x])
		if(i^fa)dfs(i,x),c[x]+=c[i],rt[x]=merge(rt[x],rt[i]);
	//cout<<x<<" "<<c[x]<<endl;
	if(c[x]==0){if(x==1)cout<<ans;else cout<<"-1";exit(0);}
	for(auto i:l[x])
		v[++tot]=i.se,dep[tot]=d[i.fi],rt[x]=merge(rt[x],tot);
	//cout<<tot<<endl;
	while(dep[rt[x]]>=d[x])rt[x]=del(rt[x]);
	if(rt[x])ans+=v[rt[x]],get(rt[x],-v[rt[x]]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=m;i++)x=read(),y=read(),z=read(),c[x]++,c[y]--,l[x].pb(mp(y,z));
	dfs(1,0);
 	return 0;
}