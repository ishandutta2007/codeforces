#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=200055;
struct node{int l,r,id,pre;}b[maxn];
struct edge{int v,nex;}e[maxn];
struct str{int x,dfn,r;}a[maxn];
int n,m,t,t2,id[maxn],s[maxn],ans[maxn],sum=0,k,tot=0,f[maxn],cnt=0,l,r,p,c[maxn],x,y,ss[maxn],head[maxn];
bool cmp(node a,node b)
{
	if(id[a.l]!=id[b.l])return a.l<b.l;
	if(id[a.r]!=id[b.r])return a.r<b.r;
	return a.pre<b.pre;
}
bool cnp(str a,str b){return a.dfn<b.dfn;}
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt;}
void ins(int x){s[x]++;ss[s[x]]++;}
void cut(int x){ss[s[x]]--;s[x]--;}
void dfs(int x,int fa)
{
	a[x].dfn=++tot;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v!=fa)dfs(v,x);
	}
	a[x].r=tot;
}
signed main()
{
	n=read(),m=read();t=sqrt(n);
	for(int i=1;i<=n;i++)a[i].x=read(),id[i]=(i-1)/t+1;
	for(int i=1;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);dfs(1,0);
	for(int i=1;i<=m;i++)x=read(),b[i].l=a[x].dfn,b[i].r=a[x].r,b[i].id=i,b[i].pre=read();
	sort(a+1,a+n+1,cnp);
	sort(b+1,b+m+1,cmp);l=b[1].l,r=b[1].r,sum=0;
	for(int i=b[1].l;i<=b[1].r;i++)ins(a[i].x);ans[b[1].id]=ss[b[1].pre];
	for(int i=2;i<=m;i++)
	{
		//cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].id<<endl;
		while(l<b[i].l)cut(a[l].x),l++;
		while(l>b[i].l)l--,ins(a[l].x);
		while(r<b[i].r)r++,ins(a[r].x);
		while(r>b[i].r)cut(a[r].x),r--;//cout<<sum<<endl;
		ans[b[i].id]=ss[b[i].pre];
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}