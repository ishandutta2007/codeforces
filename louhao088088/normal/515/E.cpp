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
#define int long long
const int maxn=2e5+5,M=34005,inf=-1e18;
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
struct node{int Max1,Max2,ans;}tr[maxn*4];
int n,m,d[maxn],h[maxn],l,r,ans;
void build(int rt,int l,int r)
{
	if(l==r){tr[rt].Max1=2*h[l]-d[l],tr[rt].Max2=d[l]+2*h[l];tr[rt].ans=0;return;}
	build(ls,l,mid),build(rs,mid+1,r);
	node a=tr[ls],b=tr[rs];
	tr[rt]=(node){max(a.Max1,b.Max1),max(a.Max2,b.Max2),max(max(a.ans,b.ans),max(a.Max1+b.Max2,a.Max2+b.Max1))};
}
node query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return (node){inf,inf,inf};
	if(l>=L&&r<=R){return tr[rt];}
	node a=query(ls,l,mid,L,R),b=query(rs,mid+1,r,L,R);
	return (node){max(a.Max1,b.Max1),max(a.Max2,b.Max2),max(max(a.ans,b.ans),max(a.Max1+b.Max2,a.Max2+b.Max1))};
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)d[i+1]=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++)d[i+n+1]=d[i+1],h[i+n]=h[i];
	n=n*2;
	for(int i=1;i<=n;i++)d[i]=d[i-1]+d[i];//,cout<<2*h[i]-d[i]<<" ";cout<<endl;
	//for(int i=1;i<=n;i++)cout<<2*h[i]+d[i]<<" ";cout<<endl;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		l=read(),r=read();
		if(l<=r)
			ans=query(1,1,n,r+1,l+n/2-1).ans;//,cout<<r+1<<" "<<l+n/2-1<<endl;
		else
			ans=query(1,1,n,r+1,l-1).ans;
		printf("%lld\n",ans);
	}
 	return 0;
}