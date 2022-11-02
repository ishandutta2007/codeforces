#include<bits/stdc++.h>
using namespace std;
#define ls (rt<<1ll)
#define rs (rt<<1ll|1ll)
#define mid (l+r>>1ll)
#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
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
const int maxn=2e5+5,mod=1e9+7;
int a[maxn],l,r,x,y,n,m,opt,ss[maxn],k[maxn];
char s[5];
struct node
{
    long long a[3][3];
    node(){memset(a,0,sizeof a);}
}g,tag[maxn*4],sum[maxn*4]; 
node operator*(const node&x,const node&y)  
{
    node z;
	for(int k=1;k<=2;++k)
	    for(int i=1;i<=2;++i)
	        for(int j=1;j<=2;++j)
                z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
    return z;
}
node operator+(const node&x,const node&y)  
{
    node z;
	for(int i=1;i<=2;++i)
	    for(int j=1;j<=2;++j)
            z.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
    return z;
}
node Pow(node a,int b) 
{ 
	node res;res.a[1][1]=1,res.a[2][2]=1,res.a[1][2]=res.a[2][1]=0;
	while(b>0){if(b%2==1)res=res*a;a=a*a;b/=2;}return res;
}
void build(int rt,int l,int r)
{
	tag[rt].a[1][1]=tag[rt].a[2][2]=1;
	if(l==r){sum[rt]=Pow(g,a[l]);return;}
	build(ls,l,mid),build(rs,mid+1,r);
	sum[rt]=sum[ls]+sum[rs];
}
void push(int rt,int l,int r)
{
	if(tag[rt].a[1][1]!=1||tag[rt].a[2][2]!=1||tag[rt].a[1][2]!=0||tag[rt].a[2][1]!=0)
	{
		tag[ls]=tag[ls]*tag[rt];tag[rs]=tag[rs]*tag[rt];
		sum[ls]=sum[ls]*tag[rt];sum[rs]=sum[rs]*tag[rt];
		tag[rt].a[1][1]=tag[rt].a[2][2]=1;tag[rt].a[1][2]=tag[rt].a[2][1]=0;
	}
}
void add(int rt,int l,int r,int L,int R,node num)
{
	
	if(l>R||r<L)return;
	if(l>=L&&r<=R)
	{
		sum[rt]=num*sum[rt];tag[rt]=tag[rt]*num;return;
	}
	push(rt,l,r);add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	sum[rt]=sum[ls]+sum[rs];
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return sum[rt].a[1][2];
	push(rt,l,r);return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}
signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	g.a[1][1]=g.a[1][2]=g.a[2][1]=1;build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)l=read(),r=read(),x=read(),add(1,1,n,l,r,Pow(g,x));
		else l=read(),r=read(),printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
}