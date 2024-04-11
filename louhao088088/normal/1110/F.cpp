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
#define int long long
const int maxn=5e5+5,M=34005;
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
int n,m,x,a[maxn],dfn[maxn],ed[maxn],tot=0,lx[maxn],rx[maxn],Min[maxn*4],tag[maxn*4],ans[maxn],s[maxn];
vector<int>e[maxn];
vector<int>q[maxn];
void dfs(int x)
{
	dfn[x]=++tot;
	for(auto i:e[x])s[i]=s[x]+a[i],dfs(i);
	ed[x]=tot;
}
void Push(int rt){if(tag[rt])tag[ls]+=tag[rt],tag[rs]+=tag[rt],Min[ls]+=tag[rt],Min[rs]+=tag[rt];tag[rt]=0;}
void build(int rt,int l,int r)
{
	tag[rt]=0;
	if(l==r){if(!e[l].size())Min[rt]=s[l];else Min[rt]=1e18;return;}
	build(ls,l,mid),build(rs,mid+1,r),Min[rt]=min(Min[ls],Min[rs]);
}
void add(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[rt]+=num;Min[rt]+=num;return;}
	Push(rt);
	add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	Min[rt]=min(Min[ls],Min[rs]);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 1e18;
	if(l>=L&&r<=R)return Min[rt];
	Push(rt);
	return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
void dfs2(int x)
{
	for(auto i:q[x])ans[i]=query(1,1,n,lx[i],rx[i]);
	for(auto i:e[x])
	{
		add(1,1,n,1,n,a[i]);
		add(1,1,n,dfn[i],ed[i],-2*a[i]);
		dfs2(i);
		add(1,1,n,1,n,-a[i]);
		add(1,1,n,dfn[i],ed[i],2*a[i]);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=2;i<=n;i++)x=read(),e[x].push_back(i),a[i]=read();
	dfs(1);build(1,1,n);
	//for(int i=1;i<=n;i++)cout<<dfn[i]<<" "<<ed[i]<<endl;
	for(int i=1;i<=m;i++)
		x=read(),lx[i]=read(),rx[i]=read(),q[x].push_back(i);
	dfs2(1);
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
 	return 0;
}