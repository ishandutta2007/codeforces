#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define ls (rt<<1)
#define rs (rt<<1|1) 
#define mid (l+r>>1)
const int maxn=2e5+5;
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
struct node
{
	int x,v;
}a[maxn],b[maxn];
struct wzp
{
	int x,y,v;
}c[maxn];
int n,m,q,g[maxn*10],tag[maxn*20],Max[maxn*20],h=1e6,f[maxn];
void push(int rt,int l,int r)
{
	if(tag[rt])
	{
		tag[ls]+=tag[rt],Max[ls]+=tag[rt];
		tag[rs]+=tag[rt];Max[rs]+=tag[rt];tag[rt]=0;
	}
}
void build(int rt,int l,int r)
{
	if(l==r){Max[rt]=g[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);Max[rt]=max(Max[ls],Max[rs]);
//	cout<<Max[rt]<<" "<<l<<" "<<r<<endl;
}
void add(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[rt]+=num;Max[rt]+=num;return;}
	push(rt,l,r);
	add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	Max[rt]=max(Max[ls],Max[rs]);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return -1e10;
	if(l>=L&&r<=R){return Max[rt];}
	push(rt,l,r);
	return max(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
bool cmp(node a,node b){return a.x<b.x;}
bool cmp2(wzp a,wzp b){return a.x<b.x;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),q=read();memset(g,0x80,sizeof g);
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].v=read();
	for(int i=1;i<=m;i++)b[i].x=read(),b[i].v=read(),g[b[i].x]=max(g[b[i].x],-b[i].v);
	for(int i=1;i<=q;i++)c[i].x=read(),c[i].y=read(),c[i].v=read();
	sort(a+1,a+n+1,cmp);sort(c+1,c+q+1,cmp2);
	build(1,1,h);int tot=1;f[0]=-1e10;
	for(int i=1;i<=n;i++)
	{
		while(a[i].x>c[tot].x&&tot<=q) 
			add(1,1,h,c[tot].y+1,h,c[tot].v),tot++;
		//cout<<tot<<" "<<a[i]
		f[i]=max(f[i-1],query(1,1,h,1,h)-a[i].v);
	} cout<<f[n]<<endl;
 	return 0;
}