#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
const int maxn=4e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,a[maxn],dfn[maxn],siz[maxn],x,y,idx=0,opt,id[maxn],tag[maxn*4];
long long sum[maxn*4]; 
vector<int>e[maxn];
void dfs(int x,int fa)
{
	 siz[x]=1;dfn[x]=++idx;id[idx]=x;
	 for(auto i:e[x])
	 	if(i^fa)dfs(i,x),siz[x]+=siz[i];
} 
void push(int rt){if(tag[rt])sum[ls]=sum[rs]=sum[rt],tag[ls]=tag[rs]=1,tag[rt]=0;}
void build(int rt,int l,int r)
{
	if(l==r){sum[rt]=(1ll<<(a[id[l]]-1));return;}
	build(ls,l,mid),build(rs,mid+1,r);sum[rt]=sum[ls]|sum[rs];
}
void change(int rt,int l,int r,int L,int R,int num)
{	
//cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(l>R||r<L)return;
	if(l>=L&&r<=R){sum[rt]=(1ll<<(num-1)),tag[rt]=1;return;}push(rt);
	change(ls,l,mid,L,R,num),change(rs,mid+1,r,L,R,num);
	sum[rt]=sum[ls]|sum[rs];
}
long long query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0ll;
	if(l>=L&&r<=R)return sum[rt];push(rt);
	return query(ls,l,mid,L,R)|query(rs,mid+1,r,L,R);
}
int getnum(long long x)
{
	int ans=0;
	while(x)
	{
		if(x&1)ans++;x=x/2;
	}return ans;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)
			x=read(),y=read(),change(1,1,n,dfn[x],dfn[x]+siz[x]-1,y);
		else x=read(),print(getnum(query(1,1,n,dfn[x],dfn[x]+siz[x]-1))),puts("");
	}
 	return 0;
}