#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
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
int n,m,a[maxn],sum[3][maxn*4],tag[3][maxn*4],op,dfn[maxn],idx=0,l,r,d[maxn],x,y,ed[maxn],b[maxn];
vector<int>e[maxn];
void dfs(int x,int fa)
{
	dfn[x]=++idx;d[x]=d[fa]+1;b[idx]=a[x];
	for(auto i:e[x])if(i^fa)dfs(i,x);ed[x]=idx;
}
void push(int rt,int l,int r,int x)
{
	if(tag[x][rt]!=0)
	{
		tag[x][ls]+=tag[x][rt];tag[x][rs]+=tag[x][rt];
		sum[x][ls]+=tag[x][rt]*(mid-l+1),sum[x][rs]+=tag[x][rt]*(r-mid);
	}tag[x][rt]=0;
}
void build(int rt,int l,int r)
{
	if(l==r){sum[1][rt]=sum[2][rt]=b[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	sum[1][rt]=sum[1][ls]+sum[1][rs];
	sum[2][rt]=sum[2][ls]+sum[2][rs];
}
void add(int x,int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[x][rt]+=num;sum[x][rt]+=num*(r-l+1);return;}
	push(rt,l,r,x);add(x,ls,l,mid,L,R,num),add(x,rs,mid+1,r,L,R,num);
	sum[x][rt]=sum[x][ls]+sum[x][rs];
}
int query(int x,int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return sum[x][rt];
	push(rt,l,r,x);return query(x,ls,l,mid,L,R)+query(x,rs,mid+1,r,L,R);
}
signed main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		op=read();
		if(op==1)
		{
			x=read();y=read();
			if(d[x]%2==1)add(1,1,1,n,dfn[x],ed[x],y),add(2,1,1,n,dfn[x],ed[x],-y);
			else add(1,1,1,n,dfn[x],ed[x],-y),add(2,1,1,n,dfn[x],ed[x],y);
		}
		else
		{
			x=read();
			if(d[x]%2==1) printf("%d\n",query(1,1,1,n,dfn[x],dfn[x]));
			else printf("%d\n",query(2,1,1,n,dfn[x],dfn[x]));
		}
	}
 	return 0;
}